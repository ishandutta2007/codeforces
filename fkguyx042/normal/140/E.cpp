#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1000005
#define M 5005
using namespace std;
int sum,last,now;
int A[M+5][M+5],B[M+5][M+5],i,j,m,n,Mo,p,k,f[2][M],a[N],fac[M+5];
inline int read()
{
        int x; char c;
        while (c=getchar(),c<'0'||c>'9');
        x=c-'0';
        while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
        return x;
}
void jia(int &x,int y)
{ 
   x+=y; if (x>=Mo) x-=Mo;
}  
void pre()
{
     A[1][1]=1;
     for (i=1;i<M;++i)
       for (j=1;j<=i;++j)
         if (A[i][j])
         {
               jia(A[i+1][j],1ll*A[i][j]*(j-1)%Mo);
               jia(A[i+1][j+1],A[i][j]);
         }
     fac[0]=fac[1]=1;
     for (i=1;i<M;++i) fac[i]=1ll*fac[i-1]*i%Mo;
     for (i=1;i<M;++i)
       for (j=1;j<=i;++j) 
         A[i][j]=1ll*A[i][j]*fac[j]%Mo;
     B[1][1]=m%Mo;
     for (i=1;i<M;++i)
       for (j=1;j<=i;++j)
         if (B[i][j])
         {
               jia(B[i+1][j],1ll*B[i][j]*(j-1)%Mo);
               jia(B[i+1][j+1],1ll*B[i][j]*(m-j)%Mo);
         }
     for (i=1;i<=a[1];++i)
       f[0][i]=B[a[1]][i],jia(sum,f[0][i]);
}
int main()
{
     scanf("%d%d%d",&n,&m,&Mo);
     for (i=1;i<=n;++i) a[i]=read();
    pre();
     for (i=2;i<=n;++i)
    {
        now^=1; last=now^1; 
        for (j=1;j<=a[i-2];++j) f[now][j]=0;
        for (j=1;j<=a[i];++j) 
        {
            jia(f[now][j],1ll*sum*B[a[i]][j]%Mo);
            jia(f[now][j],Mo-1ll*f[last][j]*A[a[i]][j]%Mo);
        }
        sum=0;
        for (j=1;j<=a[i];++j) jia(sum,f[now][j]);
     }
     printf("%d\n",sum);
}