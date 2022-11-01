#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)

using namespace std;

int linhas,colunas;
string str[1005];
bool isok[1005];

bool sortado(int coluna) {
     for(int i=0;i<linhas-1;i++) {
             if(isok[i]) continue;
             if(str[i][coluna] > str[i+1][coluna]) return false;
     }
     for(int i=0;i<linhas-1;i++) {
             if(str[i][coluna] != str[i+1][coluna]) {
                  isok[i] = 1;
             }
     }
     return true;
}

int main()
{
    int i,j,co=0;
    scanf("%d %d",&linhas,&colunas);
    for(i=0;i<linhas;i++) {
         cin >> str[i];
    }
    for(i=0;i<colunas;i++) {
         if(!sortado(i)) co++;
    }
    printf("%d\n",co);
    return 0;
}