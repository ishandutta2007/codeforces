#include<iostream>
#include<cstdio>
#include<algorithm>
#define MD 18
#define MN 200000
using namespace std;
inline int read()
{
    int x = 0 , f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}
pair<int,int> p[MN+5];
int cnt=0,head[MN+5],fa[MD+5][MN+5],dep[MN+5],f[MN+5],n;
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
    e[++cnt]=(edge){t,head[f]};head[f]=cnt;
    e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
bool cmp(pair<int,int> x,pair<int,int> y){return x.first>y.first;}
void Dfs(int x,int f)
{
    fa[0][x]=f;p[x]=make_pair(dep[x],x);
    for(int i=head[x];i;i=e[i].next)
        if(e[i].to!=f)
            dep[e[i].to]=dep[x]+1,Dfs(e[i].to,x);
}

inline int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j)
        if(k&1)x=fa[j][x];
    if(x==y) return x;
    for(int i=MD;~i;--i)
        if(fa[i][x]!=fa[i][y])
            x=fa[i][x],y=fa[i][y];
    return fa[0][x];
}

int main()
{
    n=read();int x=read();
    for(int i=1;i<n;++i) ins(read(),read());
    Dfs(1,0);
    for(int i=1;i<=MD;++i)
        for(int j=1;j<=n;++j)
            fa[i][j]=fa[i-1][fa[i-1][j]];
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;++i)
    {
        int z=lca(x,p[i].second);
        if(dep[x]-dep[z]>=dep[z]) continue;
        return 0*printf("%d\n",2*p[i].first);
    }
    return 0;
}