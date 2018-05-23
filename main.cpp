#include <iostream>
using namespace std;

char opposite_sign='o';
char tab_symb[5][5]={'e','e','e','e','e',
                     'e','x','e','e','e',
                     'e','e','o','e','e',
                     'e','e','e','x','e',
                     'e','e','e','e','o'
                    };
int size_of_table=5;
int winSize=2;



bool left_diagonals(char player_sign) {
    bool tmp=false;                                 // zmienna potwierdzająca zwyciestwo
    int ok_1=0;                                     // licznik znaków w rzędzie dla przekątnych poniżej i włącznie z środkową przekątna
    int ok_2=0;                                      // licznik znaków w rzędzie do wygranej powyżej środkowej przekątnej

    for (int b = 0; b<size_of_table; b++) { //pętla dla zejscia w dół
        int t=0;                                // zmienna ograniczająca długość przekątnej
        for (int a = 0; t>=winSize; a++) {       // pętla chodzenia po kolumnach

            ///////////////////////////////////////////////////////////////////////////////
            ////////////      WŁĄCZNIE I PONIŻEJ ŚRODKOWEJ PRZEKĄTNEJ      ///////////////
            if (tab_symb[a][a+b] == player_sign) {
                ok_1 += 1;
                if (ok_1 == winSize) { //sprawdzamy warunek za każdym nowym rzędem znakow
                    return true;
                }
            } else if ((tab_symb[a][a+b] == 'e') || (tab_symb[a][a+b] == opposite_sign)) {
                ok_1 = 0;
            }

                /////////////////////////////////////////////////////////////////////////////
                /////////////    POWYŻEJ ŚRODKOWEJ PRZEKĄTNEJ   ////////////////////////////
            else if(tab_symb[b+a+1][a]==player_sign) {
                ok_2 += 1;
                if (ok_2 == winSize) {
                    return true;
                }
            }
            else if((tab_symb[b+a+1][a] == 'e') || (tab_symb[b+a+1][a] == opposite_sign)){
                ok_2=0;
            }
        }
    }
}



bool right_diagonals(char player_sign) {
    bool tmp=false;                                 // zmienna potwierdzająca zwyciestwo
    int ok_1=0;                                     // licznik znaków w rzędzie dla przekątnych poniżej i włącznie z środkową przekątna
    int ok_2=0;                                      // licznik znaków w rzędzie do wygranej powyżej środkowej przekątnej

    for (int b=size_of_table;b>0; b--) { //pętla dla zejscia w dół
        int t=0;                                // zmienna ograniczająca długość przekątnej
        for (int a =size_of_table; t>=winSize; a--) {       // pętla chodzenia po kolumnach

            ///////////////////////////////////////////////////////////////////////////////
            ////////////      WŁĄCZNIE I PONIŻEJ ŚRODKOWEJ PRZEKĄTNEJ      ///////////////
            if (tab_symb[a][a+b] == player_sign) {
                ok_1 += 1;
                if (ok_1 == winSize) { //sprawdzamy warunek za każdym nowym rzędem znakow
                    return true;
                }
            } else if ((tab_symb[a][a+b] == 'e') || (tab_symb[a][a+b] == opposite_sign)) {
                ok_1 = 0;
            }

                /////////////////////////////////////////////////////////////////////////////
                /////////////    POWYŻEJ ŚRODKOWEJ PRZEKĄTNEJ   ////////////////////////////
            else if(tab_symb[b+a+1][a]==player_sign) {
                ok_2 += 1;
                if (ok_2 == winSize) {
                    return true;
                }
            }
            else if((tab_symb[b+a+1][a] == 'e') || (tab_symb[b+a+1][a] == opposite_sign)){
                ok_2=0;
            }
        }
    }
}

bool rows_and_columns(char player_sign){
  int ok_1=0;
  int ok_2=0;
    for (int a=0; a<size_of_table;a++) {
        for (int b = 0; b<size_of_table; b++) {
       //////////////////////////////////////////////////////
       /////////       KOLUMNY     //////////////////////////
            if(tab_symb[a][b]==player_sign) {
           ok_1+= 1;
           if (ok_1 == winSize)
               return true;
       }else if(tab_symb[a][b]==opposite_sign||'e')
           ok_1=0;
       //////////////////////////////////////////////////////
       /////////       RZĘDY       //////////////////////////
        if(tab_symb[b][a]==player_sign) {
            ok_2 += 1;
            if  (ok_2==winSize)
                return true;
        }
        else if(tab_symb[b][a]==opposite_sign||'e')
            ok_2=0;
        }
    }
}

bool isVictory(char player_sign) {
    bool left_diag=left_diagonals();
    bool right_diag=right_diagonals();
    bool row_and_column=rows_and_columns();
    if((left_diag||right_diag||row_and_column)==true)
        return true;
    else
        return false;
    }



int main(){
    cout<<isVictory('x')<<endl;
}
