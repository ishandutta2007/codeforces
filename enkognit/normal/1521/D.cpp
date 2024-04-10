#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
#define ld long double
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ld E=1e-12;
const ll MOD=998244353;

ll n, m, k, T, w, pp[100005], dp[100005][3];
ll o1[100005];
pll o2[100005];
vector<ll> e[100005];
vector<pll> v1, v2, q;
vector<ll> c[100005], g[100005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1)  l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

ll d[1000001];

void make_sets(int h)
{
    for (int i = 1; i <= h; i++) d[i]=i;
}

ll find_set(int h)
{
    if (h==d[h]) return h; else return d[h]=find_set(d[h]);
}

void unite_sets(int x,int y)
{
    x=find_set(x);
    y=find_set(y);
    d[x]=y;
}

void dfs(int h,int p=-1)
{
    pp[h]=p;
    if (c[h].size()-(h!=1)==0)
    {
        dp[h][1]=1;
        //cout << h << " - " << dp[h][1] << " " << dp[h][2] << "\n";
        return;
    }
    pll o=mp(0, 0);
    ll sm=0;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            g[h].pb(c[h][i]);
            ll u=c[h][i];
            dfs(u, h);
            sm+=min(dp[u][1], dp[u][2]);
            if (o.fi==0 || dp[u][1]-min(dp[u][1],dp[u][2])<dp[o.fi][1]-min(dp[o.fi][1],dp[o.fi][2]))
                swap(o.fi, o.se), o.fi=u; else
            if (o.se==0 || dp[u][1]-min(dp[u][1],dp[u][2])<dp[o.se][1]-min(dp[o.se][1],dp[o.se][2]))
                o.se=u;
        }

    if (o.fi)
    {
        o1[h]=o.fi;
        dp[h][1]=sm+dp[o.fi][1]-min(dp[o.fi][1],dp[o.fi][2]);
    }

    if (o.se)
    {
        o2[h]=mp(o.fi, o.se);
        dp[h][2]=sm+dp[o.fi][1]-min(dp[o.fi][1],dp[o.fi][2])+dp[o.se][1]-min(dp[o.se][1],dp[o.se][2])-1;
    }

    //cout << h << " " << dp[h][1] << " " << dp[h][2] << "\n";
}

void dfs2(int h,int k,int p=-1)
{
    if (p!=-1) unite_sets(h, p);
    if (k==1)
    {
        if (o1[h]) dfs2(o1[h], 1, h); else
            e[find_set(h)].pb(h);
        for (int i = 0; i < g[h].size(); i++)
            if (g[h][i]!=o1[h])
            {
                v1.pb(mp(g[h][i], h));
                if (dp[g[h][i]][1]<dp[g[h][i]][2]) e[g[h][i]].pb(g[h][i]), dfs2(g[h][i], 1, -1); else
                    dfs2(g[h][i], 2, -1);
            }
    }else
    {
        dfs2(o2[h].fi, 1, h);
        dfs2(o2[h].se, 1, h);
        for (int i = 0; i < g[h].size(); i++)
            if (g[h][i]!=o2[h].fi && g[h][i]!=o2[h].se)
            {
                v1.pb(mp(g[h][i], h));
                if (dp[g[h][i]][1]<dp[g[h][i]][2]) e[g[h][i]].pb(g[h][i]), dfs2(g[h][i], 1, -1); else
                    dfs2(g[h][i], 2, -1);
            }
    }
}

void solve()
{
    cin >> n;
    q.clear();
    v1.clear();
    for (int i = 0; i <= n; i++)
        dp[i][1]=1e18, dp[i][2]=1e18, c[i].clear(), g[i].clear(), e[i].clear(), pp[i]=0, o1[i]=0, o2[i]=mp(0,0);
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1,0);
    make_sets(n);
    //cout << dp[1][1] << " " << dp[1][2] << "\n";
    if (dp[1][1]<dp[1][2]) e[1].pb(1), dfs2(1, 1); else dfs2(1, 2);
    for (int i = 1; i <= n; i++)
    {
        //cout << i << " - " << e[i].size() << "\n";
        if (e[i].size()==2)
        {
            //cout << "! " << e[i][0] << " " << e[i][1] << "\n";
            q.pb(mp(e[i][0], e[i][1]));
        }
    }
    assert(q.size()==v1.size()+1);
    cout << v1.size() << "\n";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i].fi << " " << v1[i].se << " " << q[i].se << " " << q[i+1].fi << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
3 5 20
1 3 5
1
1 1
*/