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
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int linhascore[505],valo[550][550];

int max(int linhas) {
    int maior=0;
    for(int i=1;i<=linhas;i++) {
            if(linhascore[i] > maior) maior = linhascore[i];
    }
    return maior;
}

int main()
{
    int linhas,colunas,q,i,j,k,z,max_score=0,val,current;
    scanf("%d %d %d",&linhas,&colunas,&q);
    for(i=1;i<=linhas;i++) {
       current = 0;
       
       for(j=1;j<=colunas;j++) {
          scanf("%d",&val);
          valo[i][j] = val;
          
          if(val==1) current++;
          else {
               if(linhascore[i] < current) linhascore[i] = current;
               current = 0;
          }
       }
       
       if(linhascore[i] < current) linhascore[i] = current;
    }
    for(k=1;k<=q;k++) {
       scanf("%d %d",&i,&j);
       valo[i][j] = (valo[i][j]+1)%2;
       //------
       current = 0;
       linhascore[i] = 0;
       for(z=1;z<=colunas;z++) {                        
          if(valo[i][z]==1) current++;
          else {
               if(linhascore[i] < current) linhascore[i] = current;
               current = 0;
          }                        
       }
       if(linhascore[i] < current) linhascore[i] = current;                        
       //------
       max_score = max(linhas);
       printf("%d\n",max_score);
    }
    return 0;
}