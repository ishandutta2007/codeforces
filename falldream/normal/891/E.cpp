#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 5000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int ans=0,n,k,a[MN+5],f[MN+5][MN+5];
inline int pow(int x,int k)
{
    int sum=1;
    for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) sum=1LL*sum*x%mod;
    return sum;
}
int main()
{
    n=read();k=read();
    for(int i=1;i<=n;++i) a[i]=read();
    f[0][0]=1;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=i;++j)
            f[i][j]=(f[i-1][j]+(j?(1LL*f[i-1][j-1]*a[i]):0))%mod;
    for(int i=n-1;~i;--i)
    {
        int d=n-1-i;if(k-d-1<0) continue;
        int X=1LL*(k-d)*pow(n,(k-d-1))%mod;
        for(int j=k-d;j<k;++j) X=1LL*X*(mod-1)%mod*(j+1)%mod;
        ans=(ans+1LL*X*f[n][i])%mod;
    }
    ans=1LL*ans*pow(pow(n,mod-2),k)%mod;
    printf("%d\n",ans);
    return 0;
}