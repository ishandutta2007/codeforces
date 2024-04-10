#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define I64 long long
#define For(i,a,b)  for(int i=a;i<=b;i++)

I64     L,R,P,K,T;

struct  Mat{
        I64     A[2][2];
        Mat()   {memset(A,0,sizeof(A));}
        void    Init()  {For(i,0,1) A[i][i]=1;}

        Mat operator *  (const Mat&b){
            Mat c,a=*this;
            For(i,0,1)  For(j,0,1)  For(k,0,1)
                c.A[i][j]=(a.A[i][k]*b.A[k][j]+c.A[i][j])%P;
            return  c;
        }
        Mat operator ^  (I64 K){
            Mat ret,a=*this;    ret.Init();
            for (;K;K>>=1,a=a*a)
                if  (K&1)   ret=ret*a;
            return  ret;
        }
}S;

int     main(){
        scanf("%I64d%I64d%I64d%I64d",&P,&L,&R,&K);
        for (I64 i=1,j;i<=R;i=j+1){
            j=R/(R/i);
            if  (R/j-(L-1)/j>=K)    T=j;
        }

        S.A[0][0]=S.A[0][1]=S.A[1][0]=1;    S=S^(T-1);
        printf("%I64d\n",S.A[0][0]%P);
}