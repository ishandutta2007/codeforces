#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n   100005
#define I64 long long
#define For(i,a,b)  for(int i=a;i<=b;i++)

int     N,Q,A[n];
I64     Sum[n],Ans[n];

bool    Cmp(int a,int b)    {return a>b;}

int     main(){
        scanf("%d",&N);
        For(i,1,N)  scanf("%d",&A[i]);
        sort(A+1,A+N+1,Cmp);
        For(i,1,N)  Sum[i]=Sum[i-1]+A[i];

        For(k,1,100000){
            I64 t=1,p=1,d=k;
            for (;t<N;) {
                I64 r=min(t+d,N+0ll);
                Ans[k]+=(Sum[r]-Sum[t])*p;
                t+=d;   d=d*k;  p++;
            }
        }

        scanf("%d",&Q);
        for (int k;Q--;)    scanf("%d",&k),printf("%I64d ",Ans[k]);
}