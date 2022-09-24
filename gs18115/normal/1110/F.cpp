#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MAXN=5e5+10;
struct seg
{
    LL mind[2000010],lazy[2000010];
    seg()
    {
        fill(mind,mind+200010,0LL);
        fill(lazy,lazy+200010,0LL);
    }
    inline void prop(const LL&N)
    {
        mind[N]+=lazy[N];
        lazy[N<<1]+=lazy[N];
        lazy[N<<1|1]+=lazy[N];
        lazy[N]=0;
        return;
    }
    void SS(LL N,LL s,LL e,LL S,LL E,LL x)
    {
        if(s>E||S>e)
            return;
        if(S<=s&&e<=E)
        {
            lazy[N]+=x;
            return;
        }
        prop(N);
        LL m=s+e>>1;
        SS(N<<1,s,m,S,E,x);
        SS(N<<1|1,m+1,e,S,E,x);
        mind[N]=min(mind[N<<1]+lazy[N<<1],mind[N<<1|1]+lazy[N<<1|1]);
        return;
    }
    LL SM(LL N,LL s,LL e,LL S,LL E)
    {
        if(s>E||S>e)
            return INF;
        if(S<=s&&e<=E)
            return mind[N]+lazy[N];
        prop(N);
        LL m=s+e>>1;
        return min(SM(N<<1,s,m,S,E),SM(N<<1|1,m+1,e,S,E));
    }
}ST;
vector<PL>adj[MAXN];
LL out[MAXN];
LL N;
void dfs1(LL x,LL d)
{
    out[x]=x;
    if(adj[x].empty())
    {
        ST.SS(1,0,N-1,x,x,d);
        return;
    }
    ST.SS(1,0,N-1,x,x,INF);
    for(LL i=0;i<adj[x].size();i++)
    {
        dfs1(adj[x][i].first,d+adj[x][i].second);
        out[x]=out[adj[x][i].first];
    }
    return;
}
struct query
{
    LL l,r,ind;
    query():l(0),r(0),ind(0){}
    query(LL x,LL y,LL z):l(x),r(y),ind(z){}
};
vector<query>que[MAXN];
LL ans[MAXN];
void dfs2(LL x,LL d)
{
    for(LL i=0;i<que[x].size();i++)
        ans[que[x][i].ind]=ST.SM(1,0,N-1,que[x][i].l,que[x][i].r)+d;
    for(LL i=0;i<adj[x].size();i++)
    {
        LL t=adj[x][i].first;
        LL w=adj[x][i].second;
        ST.SS(1,0,N-1,t,out[t],-w*2);
        dfs2(t,d+w);
        ST.SS(1,0,N-1,t,out[t],w*2);
    }
    return;
}
LL Q,i,s,e,V,L,R;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>Q;
    for(i=1;i<N;i++)
    {
        cin>>s>>e;
        adj[--s].emplace_back(i,e);
    }
    dfs1(0,0);
    for(i=0;i<Q;i++)
    {
        cin>>V>>L>>R;
        que[--V].emplace_back(--L,--R,i);
    }
    dfs2(0,0);
    for(i=0;i<Q;i++)
        cout<<ans[i]<<'\n';
    cout<<endl;
    return 0;
}