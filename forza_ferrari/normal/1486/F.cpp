#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
struct edge
{
    int nxt,to;
}e[300001<<1];
struct line
{
    int x,y,lca,a,b;
}q[300001];
int n,m,tot,h[300001],s[300001],dep[300001],id[300001],fa[300001][21],cnt,ans[300001],num,t[900001],sum;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline bool cmp(line x,line y)
{
    return dep[x.lca]^dep[y.lca]? dep[x.lca]<dep[y.lca]:x.lca^y.lca? x.lca<y.lca:x.a^y.a? x.a>y.a:x.b>y.b;
}
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
void dfs(int k,int f,int deep)
{
    id[k]=++cnt;
    fa[k][0]=f;
    s[k]=1;
    dep[k]=deep;
    for(register int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs(e[i].to,k,deep+1);
        s[k]+=s[e[i].to];
    }
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(register int d=dep[x]-dep[y],i=0;d;d>>=1,++i)
        if(d&1)
            x=fa[x][i];
    if(x==y)
        return x;
    for(register int i=20;~i;--i)
        if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
inline int find(int x,int y)
{
    if(x==y)
        return ++num;
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(register int d=dep[x]-dep[y]-1,i=0;d;d>>=1,++i)
        if(d&1)
            x=fa[x][i];
    return x;
}
inline int lowbit(int x)
{
    return x&-x;
}
inline void update(int x)
{
    for(;x<=n;x+=lowbit(x))
        ++ans[x];
}
inline int query(int x)
{
    int res=0;
    for(;x;x-=lowbit(x))
        res+=ans[x];
    return res;
}
signed main()
{
    num=n=read();
    for(register int i=1;i<n;++i)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs(1,0,1);
    m=read();
    for(register int i=1;i<=m;++i)
    {
        q[i].x=read(),q[i].y=read();
        q[i].lca=LCA(q[i].x,q[i].y);
        q[i].a=find(q[i].x,q[i].lca);
        q[i].b=find(q[i].y,q[i].lca);
        if(q[i].a>q[i].b)
        {
            q[i].x^=q[i].y^=q[i].x^=q[i].y;
            q[i].a^=q[i].b^=q[i].a^=q[i].b;
        }
    }
    sort(q+1,q+m+1,cmp);
    for(register int i=1;i<=m;++i)
    {
        int j=i;
        while(j<m&&q[i].lca==q[j+1].lca)
            ++j;
        int res=0;
        for(register int k=i;k<=j;++k)
        {
            int l=k;
            while(l<j&&q[k].a==q[l+1].a)
                ++l;
            for(register int r=k;r<=l;++r)
                sum+=res-t[q[r].b];
            for(register int r=k;r<=l;++r)
            {
                ++t[q[r].a];
                ++t[q[r].b];
            }
            res+=l-k+1;
            k=l;
        }
        for(register int k=i;k<=j;++k)
        {
            t[q[k].a]=t[q[k].b]=0;
            sum+=query(id[q[k].lca]+s[q[k].lca]-1)-query(id[q[k].lca]-1);
            if(q[k].a<=n)
                sum-=query(id[q[k].a]+s[q[k].a]-1)-query(id[q[k].a]-1);
            if(q[k].b<=n)
                sum-=query(id[q[k].b]+s[q[k].b]-1)-query(id[q[k].b]-1);
        }
        for(register int k=i;k<=j;++k)
        {
            update(id[q[k].x]);
            update(id[q[k].y]);
        }
        i=j;
    }
    printf("%lld\n",sum);
    return 0;
}