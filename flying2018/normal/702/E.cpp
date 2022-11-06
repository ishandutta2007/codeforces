#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define M 35
#define ll long long
using namespace std;
ll f[M][N];
int nxt[M][N],g[M][N];
int main()
{
    int n;ll k;
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&nxt[0][i]),nxt[0][i]++;
    for(int i=1;i<=n;i++) scanf("%d",&f[0][i]),g[0][i]=f[0][i];
    for(int i=1;i<M;i++)
        for(int j=1;j<=n;j++)
        {
            int v=nxt[i-1][j];
            nxt[i][j]=nxt[i-1][v];
            f[i][j]=f[i-1][j]+f[i-1][v];
            g[i][j]=min(g[i-1][j],g[i-1][v]);
        }
    for(int p=1;p<=n;p++)
    {
        ll s=0;
        int u=p,mx=1e8;
        for(ll i=M-1;i>=0;i--)
        if((k>>i)&1) s+=f[i][u],mx=min(mx,g[i][u]),u=nxt[i][u];
        printf("%lld %d\n",s,mx);
    }
    return 0;
}