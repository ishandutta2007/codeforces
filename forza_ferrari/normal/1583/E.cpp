#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int nxt,to;
}e[300001<<1];
int n,m,q,tot,h[300001],l[300001],r[300001],dep[300001],fa[300001][21];
bool a[300001],vis[300001];
vector<int> g[300001];
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
inline void add(int x,int y)
{
    e[++tot].nxt=h[x];
    h[x]=tot;
    e[tot].to=y;
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(register int d=dep[x]-dep[y],i=0;1<<i<=d;++i)
        if(d&(1<<i))
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
void dfs1(int k,int f,int deep)
{
    dep[k]=deep;
    fa[k][0]=f;
    for(register int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(register int i=h[k];i;i=e[i].nxt)
    {
        if(e[i].to==f)
            continue;
        dfs1(e[i].to,k,deep+1);
    }
}
void dfs2(int k,int f)
{
    vis[k]=1;
    for(auto i:g[k])
    {
        if(i==f||vis[i])
            continue;
        dfs2(i,k);
        add(i,k);
        add(k,i);
    }
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs2(1,0);
    dfs1(1,0,1);
    q=read();
    for(register int i=1;i<=q;++i)
    {
        l[i]=read(),r[i]=read();
        a[l[i]]^=1;
        a[r[i]]^=1;
    }
    int ans=0;
    for(register int i=1;i<=n;++i)
        ans+=a[i];
    if(!ans)
    {
        cout<<"YES"<<endl;
        for(register int i=1;i<=q;++i)
        {
            int lca=LCA(l[i],r[i]);
            vector<int> tmp1,tmp2;
            while(l[i]!=lca)
            {
                tmp1.push_back(l[i]);
                l[i]=fa[l[i]][0];
            }
            tmp1.push_back(lca);
            while(r[i]!=lca)
            {
                tmp2.push_back(r[i]);
                r[i]=fa[r[i]][0];
            }
            reverse(tmp2.begin(),tmp2.end());
            cout<<(int)tmp1.size()+(int)tmp2.size()<<" ";
            for(auto j:tmp1)
                cout<<j<<" ";
            for(auto j:tmp2)
                cout<<j<<" ";
            cout<<endl;
        }
        return 0;
    }
    cout<<"NO"<<endl<<ans/2<<endl;
    return 0;
}