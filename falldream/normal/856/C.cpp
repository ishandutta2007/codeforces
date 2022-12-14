#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define mod 998244353
#define MN 2000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],b[MN+5],num1,num2,f[MN+5][MN+5][12],F[MN+5][MN+5][12],C[MN+5][MN+5],p[MN+5],ans;
inline void R(int&x,int y){x+=y;x>=mod?x-=mod:0;}
int main()
{
    for(int i=0;i<=MN;++i) C[i][0]=1;
    for(int i=1;i<=MN;++i)
        for(int j=1;j<=i;++j)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    p[0]=1;
    for(int i=1;i<=MN;++i) p[i]=1LL*p[i-1]*i%mod;
    for(int t=read();t;--t)
    {
        n=read();num1=num2=ans=0;
        for(int i=1,j,t;i<=n;++i)
        {
            int x=read();
            for(t=x,j=1;t;t/=10,++j);
            if(j&1) a[++num1]=x%11;
            else b[++num2]=x%11;
        }
        int c1=num2/2+1,c2=(num2+1)/2;
        for(int i=0;i<=num2;++i)for(int j=0;j<=num2;++j)for(int k=0;k<11;++k)f[i][j][k]=0;
        f[0][0][0]=1LL*p[c1-1]*p[c2]%mod;
        for(int i=1;i<=num2;++i)
            for(int j=0;j<=min(i,c1-1);++j)
                for(int k=0;k<11;++k)
                {
                    if(i-j<=c2) R(f[i][j][(k-b[i]+11)%11],f[i-1][j][k]);
                    if(j) R(f[i][j][(k+b[i])%11],f[i-1][j-1][k]);
                }
        for(int i=0;i<=num1;++i)for(int j=0;j<=num1;++j)for(int k=0;k<11;++k)F[i][j][k]=0;
        for(int i=0;i<11;++i) F[0][0][i]=f[num2][c1-1][i];
        for(int i=1;i<=num1;++i)
            for(int j=0;j<i;++j)
            {
                int C1=c1+j,C2=c2+i-1-j;
                for(int k=0;k<11;++k)
                    R(F[i][j+1][(k+a[i])%11],1LL*F[i-1][j][k]*C1%mod),
                    R(F[i][j][(k-a[i]+11)%11],1LL*F[i-1][j][k]*C2%mod);
            }
        for(int i=0;i<=num1;++i) R(ans,F[num1][i][0]);
        printf("%d\n",ans);
    }
    return 0;
}