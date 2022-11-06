#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#define N 200010
#define M 400010
#define inf 1000000000
using namespace std;
set<int>s[N];
vector<int>rd[N];
int ntot,val[N],num[N],n;
namespace slpf{
    int tree[N<<2];
    void build(int u,int l,int r)
    {
        if(l==r){tree[u]=num[l];return;}
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        tree[u]=min(tree[u<<1],tree[u<<1|1]);
    }
    void insert(int u,int l,int r,int p,int v)
    {
        if(l==r){tree[u]=v;return;}
        int mid=(l+r)>>1;
        if(p<=mid) insert(u<<1,l,mid,p,v);
        else insert(u<<1|1,mid+1,r,p,v);
        tree[u]=min(tree[u<<1],tree[u<<1|1]);
    }
    int answer(int u,int l,int r,int L,int R)
    {
        if(L<=l && r<=R) return tree[u];
        int mid=(l+r)>>1;
        if(R<=mid) return answer(u<<1,l,mid,L,R);
        if(L>mid) return answer(u<<1|1,mid+1,r,L,R);
        return min(answer(u<<1,l,mid,L,R),answer(u<<1|1,mid+1,r,L,R));
    }
    int id[N],nid[N],dep[N],fa[N],top[N],cnt;
    int siz[N],son[N];
    void dfs1(int u,int f)
    {
        siz[u]=1;
        fa[u]=f;
        dep[u]=dep[f]+1;
        for(int v:rd[u])
        if(v!=f)
        {
            dfs1(v,u);
            siz[u]+=siz[v];
            if(siz[v]>siz[son[u]]) son[u]=v;
        }
    }
    void dfs2(int u,int topp)
    {
        id[u]=++cnt;
        nid[cnt]=u;
        top[u]=topp;
        if(son[u]) dfs2(son[u],topp);
        for(int v:rd[u])
        if(v!=fa[u] && v!=son[u]) dfs2(v,v);
    }
    int line_answer(int x,int y)
    {
        int ans=inf;
        while(top[x]!=top[y])
        {
            if(dep[top[x]]<dep[top[y]]) swap(x,y);
            ans=min(ans,answer(1,1,ntot,id[top[x]],id[x]));
            x=fa[top[x]];
        }
        if(dep[x]>dep[y]) swap(x,y);
        ans=min(ans,answer(1,1,ntot,id[x],id[y]));
        if (x>n) ans=min(ans,val[fa[x]]);
        return ans;
    }
    void init()
    {
        dfs1(1,0);
        dfs2(1,1);
        for(int i=1;i<=n;i++) num[id[i]]=val[i];
        for(int i=n+1;i<=ntot;i++)
        {
            for(int v:rd[i])
            if(v!=fa[i]) s[i].insert(val[v]);
            if(s[i].empty()) val[i]=inf;
            else val[i]=*s[i].begin();
            num[id[i]]=val[i];
        }
        build(1,1,ntot);
    }
    void change(int u,int v)
    {
        int f=fa[u];
        if(f)
        {
            s[f].erase(val[u]);
            s[f].insert(v);
            val[f]=*s[f].begin();
            insert(1,1,ntot,id[f],val[f]);
        }
        val[u]=v;
        insert(1,1,ntot,id[u],v);
    }
}
int nxt[M],to[M],head[N],cnt;
void add(int u,int v)
{
    nxt[++cnt]=head[u];
    to[cnt]=v;
    head[u]=cnt;
}
int dfn[N],low[N],itot;
int q[N],ltot;
void tarjan(int u)
{
    dfn[u]=low[u]=++itot;
    q[++ltot]=u;
    for(int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])
            {
                int t;
                ++ntot;
                rd[u].push_back(ntot);
                rd[ntot].push_back(u);
                val[ntot]=val[u];
                do{
					t=q[ltot--];
                    rd[t].push_back(ntot);
                    rd[ntot].push_back(t);
				}while(t!=v);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
char opt[2];
int main()
{
    int m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    ntot=n;
    tarjan(1);
    slpf::init();
    while(q --> 0)
    {
        int x,y;
        scanf("%s%d%d",opt,&x,&y);
        if(opt[0]=='C') slpf::change(x,y);
        else printf("%d\n",slpf::line_answer(x,y));
    }
    return 0; 
}