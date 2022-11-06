#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <algorithm>
#define maxn    100005
#define point   vector<int>::iterator
using namespace std;

int     N,M,S,E,Ans,A[maxn],F[maxn];
vector<int>B[maxn];

int     main(){
        scanf("%d%d%d%d",&N,&M,&S,&E);  
        for (int i=1;i<=N;i++)      scanf("%d",&A[i]);
        for (int i=0;i<maxn;i++)    B[i].clear();
        for (int j=1,x;j<=M;j++)    scanf("%d",&x),B[x].push_back(j);
        memset(F,63,sizeof(F)); F[0]=0; Ans=0;
        
        for (int i=1;i<=N;i++)
        for (int j=S/E-1;j>=0;j--){
            int x=A[i];
            point k=upper_bound(B[x].begin(),B[x].end(),F[j]);
            if  (k==(B[x].end()))   continue;
            F[j+1]=min(F[j+1],*k);
            if  (j+1>Ans&&(j+1)*E+F[j+1]+i<=S)  Ans=j+1;
        }
        printf("%d\n",Ans);
        return  0;
}