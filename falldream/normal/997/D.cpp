#include<bits/stdc++.h>
#define mod 998244353
#define MN 4000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int C[80][80],K,ans;
struct edge{int to,next;};
struct Tree
{
    int n,head[MN+5],cnt,f[MN+5][40],g[MN+5][40],h[MN+5][40],F[MN+5][40],res[80],fa[MN+5];
    edge e[MN*2+5];
    inline void ins(int f,int t)
    {
        e[++cnt]=(edge){t,head[f]};head[f]=cnt;
        e[++cnt]=(edge){f,head[t]};head[t]=cnt;
    }
    void dfs(int x)
    {
        for(int i=head[x];i;i=e[i].next)
            if(e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),++h[x][0];
    }
    void dfs1(int x)
    {
        for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa[x]) dfs1(e[i].to);
        for(int i=1;i<=K;++i)
            for(int j=head[x];j;j=e[j].next) if(e[j].to!=fa[x])
                for(int l=0;l<i;++l) f[x][i]=(f[x][i]+1LL*f[e[j].to][l]*f[x][i-l-1])%mod;
    }
    void dfs2(int x)
    {
        if(fa[x]) for(int i=0;i<=K;++i) h[x][i]=(h[x][i]+g[x][i])%mod;
        for(int j=1;j<=K;++j)
            for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa[x])
            {
                for(int l=0;l<j;++l) g[e[i].to][j]=(g[e[i].to][j]+1LL*(h[x][l]-f[e[i].to][l]+mod)*g[e[i].to][j-l-1])%mod;
                h[x][j]=(h[x][j]+f[e[i].to][j])%mod;
            }
        for(int i=head[x];i;i=e[i].next) if(e[i].to!=fa[x]) dfs2(e[i].to);
    }
    void Build()
    {
        for(int i=1;i<n;++i) ins(read(),read());
        for(int i=1;i<=n;++i) f[i][0]=g[i][0]=F[i][0]=1;
        dfs(1);dfs1(1);dfs2(1);
        for(int i=1;i<=K;++i) for(int j=1;j<=n;++j)
            for(int k=head[j];k;k=e[k].next) for(int l=0;l<i;++l)
                F[j][i]=(F[j][i]+1LL*F[j][i-l-1]*(e[k].to==fa[j]?g[j][l]:f[e[k].to][l]))%mod;
        for(int i=1;i<=n;++i) for(int j=0;j<=K;++j)
            res[j]=(res[j]+F[i][j])%mod;
    }
}t1,t2;
int main()
{
    t1.n=read();t2.n=read();K=read();if(K&1) return 0*puts("0");K>>=1;
    for(int i=0;i<=K*2;++i) C[i][0]=1;
    for(int i=1;i<=K*2;++i) for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    t1.Build();t2.Build();
    for(int i=0;i<=K;++i) ans=(ans+1LL*C[K*2][i*2]*t1.res[i]%mod*t2.res[K-i])%mod;
    cout<<ans;
    return 0;
}