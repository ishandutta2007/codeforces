#include <stdio.h>
#include <iostream>
#include <string>

//
// variao do problema LLPS do codeforces (para treino) incluindo caracteres MAISCULOS e 
// usando outra abordagem (usando outra string em vez da tabela ASCII
//

using namespace std;

int main()
{
    string str;
    string ordem = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> str;
    int i = ordem.size(),num = -1;
    while(num == -1)
         num = str.find(ordem[--i]);
    while(num != -1) {
         str.erase(num,1);
         printf("%c",ordem[i]);
         num = str.find(ordem[i]);
    }
    return 0;
}