#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
ll v,e,i;
ll bcc[200010];
ll dp[200010];
ll w[200010],w2[200010];
ll sz[200010];
ll disc[200010];
ll dct;
bool vis[200010],v2[200010],v3[200010];
bool flag[200010];
ll bct;
ll pa[200010];
vector<pl>adj[200010];
vector<ll>adb[200010],ad2[200010];
ll par(ll x)
{
    if(pa[x]==-1)
        return x;
    return pa[x]=par(pa[x]);
}
inline void uni(ll x,ll y)
{
    x=par(x);
    y=par(y);
    if(x==y)
        return;
    pa[x]=y;
    w2[y]+=w2[x];
    sz[y]+=sz[x];
    return;
}
ll cut(ll x,ll p)
{
    ll ret=disc[x]=++dct;
    for(pi t:adj[x])
    {
        ll n=t.fi;
        if(n==p)
            continue;
        else if(disc[n]>0)
            ret=min(ret,disc[n]);
        else
        {
            ll rt=cut(n,x);
            if(rt>disc[x])
                flag[t.se]=true;
            ret=min(ret,rt);
        }
    }
    return ret;
}
void ff(ll x,ll v)
{
    w2[bcc[x]=v]+=w[x];
    sz[v]++;
    vis[x]=true;
    for(pl t:adj[x])
        if(!vis[t.fi]&&!flag[t.se])
            ff(t.fi,v);
    return;
}
void dfs(ll x,ll d)
{
    dp[x]=d+w2[x];
    v2[x]=true;
    for(ll t:adb[x])
        if(!v2[t])
            dfs(t,dp[x]);
    return;
}
ll merge(ll x)
{
    ll ret=sz[par(x)];
    v3[x]=true;
    for(ll t:ad2[x])
    {
        if(v3[t])
            continue;
        ll rt=merge(t);
        if(rt>1)
            uni(x,t);
        ret=max(ret,rt);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>v>>e;
    fill(pa,pa+v+1,-1);
    for(i=0;i<v;i++)
        cin>>w[i];
    for(i=0;i<e;i++)
    {
        ll ss,ee;
        cin>>ss>>ee;
        adj[--ss].eb(--ee,i);
        adj[ee].eb(ss,i);
    }
    ll S;
    cin>>S;
    S--;
    cut(S,-1);
    for(i=0;i<v;i++)
        if(!vis[i])
            ff(i,++bct);
    for(i=0;i<v;i++)
    {
        for(pl t:adj[i])
        {
            ll p=bcc[i];
            ll q=bcc[t.fi];
            if(p==q)
                continue;
            ad2[p].eb(q);
            ad2[q].eb(p);
        }
    }
    for(i=0;i++<bct;)
    {
        sort(all(ad2[i]));
        ad2[i].erase(unique(all(ad2[i])),ad2[i].end());
    }
    merge(bcc[S]);
    for(i=0;i++<bct;)
        if(!v3[i]&&sz[i]>1)
            merge(i);
    for(i=0;i<v;i++)
    {
        for(pl t:adj[i])
        {
            ll p=bcc[i];
            ll q=bcc[t.fi];
            p=par(p);
            q=par(q);
            if(p==q)
                continue;
            adb[p].eb(q);
            adb[q].eb(p);
        }
    }
    for(i=0;i++<bct;)
    {
        sort(all(adb[i]));
        adb[i].erase(unique(all(adb[i])),adb[i].end());
    }
    dfs(par(bcc[S]),0);
    ll ans=0;
    for(i=0;i++<bct;)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}