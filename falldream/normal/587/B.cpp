#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 1001000
#define mod 1000000007
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,K,a[MN+5],ans=0,b[MN+5],*f[MN+5],nn[MN+5];long long L;
int main()
{
    cin>>n>>L>>K;
    for(int i=0;i<=K;++i) f[i]=new int[n+5];
    for(int i=1;i<=n;++i) a[i]=b[i]=read();
    long long num=L/n;int Left=L%n,tot=1;nn[tot]=1;
    sort(b+1,b+n+1);
    for(int i=2;i<=n;++nn[tot],++i) if(b[i]!=b[i-1]) b[++tot]=b[i];
    for(int j=0;j<=tot;++j) f[0][j]=1;
    for(int i=1;i<=K;++i)
    {
        f[i][0]=0;
        for(int j=1;j<=tot;++j)
            f[i][j]=1LL*f[i-1][j]*nn[j]%mod;
        for(int j=1;j<=tot;++j)f[i][j]=(f[i][j]+f[i][j-1])%mod;
    }
    for(int i=1;i<=n;++i)
    {
        long long N=num+(i<=Left);int rk=lower_bound(b+1,b+tot+1,a[i])-b;
        for(int j=1;j<=min(N,(long long)K);++j)
            ans=(ans+1LL*f[j-1][rk]*((N-j+1)%mod))%mod;
    }
    printf("%d\n",ans);
    return 0;
}