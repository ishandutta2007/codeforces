#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e3+7;

int n,a[N],st[N],ed[N],dc,q;

vector<int>g[N];

int anc[N][21],dep[N];

void dfs(int x,int f)
{
    st[x]=++dc;
    anc[x][0]=f;
    for(int j=1;j<=18;j++)
        anc[x][j]=anc[anc[x][j-1]][j-1];
    dep[x]=dep[f]+1;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
    }
    ed[x]=dc;
}

int lca(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=18;i>=0;i--)
        if(dep[x]-(1<<i)>=dep[y])
            x=anc[x][i];
    if(x==y)
        return x;
    for(int i=18;i>=0;i--)
        if(anc[x][i]!=anc[y][i])
            x=anc[x][i],y=anc[y][i];
    return anc[x][0];
}

int c[N];

void add(int x,int v)
{
    while(x<=n)
    {
        c[x]+=v;
        x+=x&-x;
    }
}

void change(int l,int r,int v)
{
    add(l,v);
    add(r+1,-v);
}

int query(int x)
{
    int ret=0;
    while(x)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

signed main()
{
    scanf("%lld%lld",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),a[i]=abs(a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        change(st[i],ed[i],a[i]);
    while(q--)
    {
        int op,x,y;
        scanf("%lld%lld%lld",&op,&x,&y);
        if(op==1)
        {
            change(st[x],ed[x],-a[x]);
            a[x]=abs(y);
            change(st[x],ed[x],a[x]);
        }
        else
        {
            int p=lca(x,y);
            // printf("%lld\n",p);
            int ans=(query(st[x])+query(st[y])-query(st[p])-query(st[anc[p][0]]))*2;
            ans-=a[x]+a[y];
            printf("%lld\n",ans);
        }
    }
}