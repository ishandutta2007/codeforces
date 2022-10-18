#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int lst,n,m,q,cnt,dfn[300001],low[300001],col[300001],tot,st[300001],top,id[300001],num,dep[300001],fa[300001][21],bin[300001],w[300001];
bool vis[300001];
vector<int> v[300001],g[300001],node,res,tmp;
stack<int> t;
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
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
inline void tarjan(int k,int f)
{
    dfn[k]=low[k]=++cnt;
    vis[k]=1;
    t.emplace(k);
    bool flag=1;
    for(int i:v[k])
    {
        if(i==f&&flag)
        {
            flag=0;
            continue;
        }
        if(!dfn[i])
        {
            tarjan(i,k);
            low[k]=min(low[k],low[i]);
        }
        else if(vis[i])
            low[k]=min(low[k],dfn[i]);
    }
    if(low[k]==dfn[k])
    {
        col[k]=++tot;
        vis[k]=0;
        while(!t.empty()&&t.top()!=k)
        {
            col[t.top()]=tot;
            vis[t.top()]=0;
            t.pop();
        }
        if(!t.empty())
            t.pop();
    }
}
inline void dfs(int k,int f,int deep)
{
    id[k]=++num;
    dep[k]=deep;
    fa[k][0]=f;
    for(int i=1;i<=20;++i)
        fa[k][i]=fa[fa[k][i-1]][i-1];
    for(int i:g[k])
    {
        if(i==f)
            continue;
        dfs(i,k,deep+1);
    }
}
inline int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        x^=y^=x^=y;
    for(int d=dep[x]-dep[y],i=0;1<<i<=d;++i)
        if(d>>i&1)
            x=fa[x][i];
    if(x==y)
        return x;
    for(int i=20;~i;--i)
        if(fa[x][i]^fa[y][i])
        {
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];
}
int main()
{
    n=read(),m=read(),q=read();
    for(int i=1;i<=m;++i)
    {
        int x=read(),y=read();
        v[x].emplace_back(y);
        v[y].emplace_back(x);
    }
    for(int i=1;i<=n;++i)
        if(!dfn[i])
            tarjan(i,0);
    for(int i=1;i<=n;++i)
        for(int j:v[i])
            if(i<j&&col[i]!=col[j])
            {
                g[col[i]].emplace_back(col[j]);
                g[col[j]].emplace_back(col[i]);
                link(col[i],col[j]);
            }
    for(int i=1;i<=n;++i)
    {
        w[i]=col[i];
        v[i].clear();
        dfn[i]=low[i]=col[i]=0;
    }
    for(int i=1;i<=tot;++i)
        if(!id[i])
            dfs(i,0,1);
    for(int qwq=1;qwq<=q;++qwq)
    {
        node.clear();
        res.clear();
        tmp.clear();
        int p1=read(),p2=read();
        for(int i=1;i<=p1;++i)
        {
            int x=w[(read()+lst-1)%n+1];
            res.emplace_back(x);
            node.emplace_back(x);
        }
        for(int i=1;i<=p2;++i)
        {
            int x=w[(read()+lst-1)%n+1],y=w[(read()+lst-1)%n+1];
            if(x==y)
                continue;
            v[x].emplace_back(y);
            v[y].emplace_back(x);
            node.emplace_back(x);
            node.emplace_back(y);
        }
        sort(node.begin(),node.end());
        node.erase(unique(node.begin(),node.end()),node.end());
        sort(node.begin(),node.end(),[&](int x,int y){return id[x]<id[y];});
        int root=0;
        tmp=node;
        for(int i:node)
        {
            if(anc(i)^root)
            {
                while(top>1)
                {
                    v[st[top-1]].emplace_back(st[top]);
                    v[st[top]].emplace_back(st[top-1]);
                    --top;
                }
                top=0;
                root=anc(i);
            }
            if(!top)
            {
                st[++top]=i;
                continue;
            }
            int lca=LCA(st[top],i);
            tmp.emplace_back(lca);
            if(lca!=st[top])
            {
                while(id[lca]<id[st[top-1]])
                {
                    v[st[top-1]].emplace_back(st[top]);
                    v[st[top]].emplace_back(st[top-1]);
                    --top;
                }
                if(lca!=st[top-1])
                {
                    v[lca].emplace_back(st[top]);
                    v[st[top]].emplace_back(lca);
                    st[top]=lca;
                }
                else
                {
                    v[lca].emplace_back(st[top]);
                    v[st[top]].emplace_back(lca);
                    --top;
                }
            }
            st[++top]=i;
        }
        while(top>1)
        {
            v[st[top-1]].emplace_back(st[top]);
            v[st[top]].emplace_back(st[top-1]);
            --top;
        }
        cnt=tot=0;
        for(int i:node)
            if(!dfn[i])
                tarjan(i,0);
        bool flag=1;
        for(int i:res)
            flag&=col[i]==col[res[0]];
        lst=(lst+flag*qwq)%n;
        cout<<(flag? "YES":"NO")<<'\n';
        for(int i:tmp)
        {
            v[i].clear();
            dfn[i]=low[i]=col[i]=0;
        }
    }
    return 0;
}