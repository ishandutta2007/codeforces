#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
#define N 510
using namespace std;
bitset<N> f[2][61][N],g,h;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        f[w][0][u][v]=true;
    }
    for(int t=1;t<=60;t++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int _=0;_<=1;_++)
                if(f[_][t-1][i][j]!=0) f[_][t][i]|=f[!_][t-1][j];
    if(f[0][60][1].any()){puts("-1");return 0;}
    int u=0;h[1]=1;
    long long ans=0;
    for(int i=60;i>=0;i--)
    {
        g.reset();
        for(int j=1;j<=n;j++) if(h[j]) g|=f[u][i][j];
        if(g.any()){u=!u;h=g;ans+=1ll<<i;}
    }
    if(ans>1e18){puts("-1");return 0;}
    printf("%lld\n",ans);
    return 0;
}