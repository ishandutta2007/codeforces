#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n   105
#define For(i,a,b)  for(int i=a;i<=b;i++)

int     N,M,X[n],Y[n],AnsX[n],AnsY[n],A[n][n];

int     main(){
        scanf("%d%d",&N,&M);
        For(i,1,N)  For(j,1,M)  scanf("%d",&A[i][j]);
        For(i,1,N)  {
            X[i]=0;
            For(j,1,M)  X[i]+=A[i][j];
        }
        For(j,1,M)  {
            Y[j]=0;
            For(i,1,N)  Y[j]+=A[i][j];
        }

        for (;;)    {
            int t,x,Min=1<<30;
            For(i,1,N)  if  (X[i]<Min)  Min=X[i],x=i,t=0;
            For(i,1,M)  if  (Y[i]<Min)  Min=Y[i],x=i,t=1;
            if  (Min>=0)break;

            if  (!t)    {
                AnsX[x]^=1; X[x]*=-1;
                For(i,1,M)  Y[i]-=2*A[x][i],A[x][i]*=-1;
            }   else    {
                AnsY[x]^=1; Y[x]*=-1;
                For(i,1,N)  X[i]-=2*A[i][x],A[i][x]*=-1;
            }
        }

        For(i,1,N)  if  (AnsX[i])   AnsX[++*AnsX]=i;
        For(i,1,M)  if  (AnsY[i])   AnsY[++*AnsY]=i;
        For(i,0,*AnsX)  printf("%d ",AnsX[i]);  puts("");
        For(i,0,*AnsY)  printf("%d ",AnsY[i]);  puts("");
}