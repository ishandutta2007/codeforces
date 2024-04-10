#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
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

const ll MOD=998244353;

ll n, m, k, sz, s, t, a[500001], dist[5005];
vector<ll> c[5005];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

struct edge
{
    ll x, y, cap, flow;
    edge():x(0),y(0),cap(0),flow(0){};
    edge(ll x,ll y,ll cap):x(x),y(y),cap(cap),flow(0){};
};

vector<edge> edges;

bool bfs()
{
    for (int i = 0; i <= t; i++) dist[i]=1e18;
    dist[s]=0;
    queue<pll> q;
    q.push(mp(0, s));
    while (!q.empty())
    {
        ll x=q.front().se;
        //cout << x << " " << dist[x] << "\n";
        q.pop();
        for (int i = 0; i < c[x].size(); i++)
            if (edges[c[x][i]].cap>edges[c[x][i]].flow && dist[edges[c[x][i]].y]>dist[x]+1)
            {
                dist[edges[c[x][i]].y]=dist[x]+1;
                q.push(mp(dist[x]+1, edges[c[x][i]].y));
            }
    }
    return (dist[t]<1e17);
}

ll dfs(int h,ll k)
{
    if (h==n*2+1)
    {
        return k;
    }
    for (int i = 0; i < c[h].size(); i++)
        if (edges[c[h][i]].cap>edges[c[h][i]].flow && dist[edges[c[h][i]].y]==dist[h]+1)
        {
            ll p=dfs(edges[c[h][i]].y,
                     min(k, edges[c[h][i]].cap-edges[c[h][i]].flow));
            if (p>0)
            {
                edges[c[h][i]].flow+=p;
                edges[c[h][i]^1].flow-=p;
                return p;
            }
        }
    return 0;
}

void solve()
{
    cin >> n;
    s=n*2, t=n*2+1;
    ll ans=0;
    vector<pll> v;
    map<pll, int> q;
    for (int i = 0; i < n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        c[i*2].pb(edges.size());
        edges.pb(edge(i*2, i*2+1, z));
        c[i*2+1].pb(edges.size());
        edges.pb(edge(i*2+1, i*2, 0));
        v.pb(mp(x, y));
        q[mp(x,y)]=i;
        ans+=z;
    }

    for (int i = 0; i < v.size(); i++)
    {
        ll x=v[i].fi, y=v[i].se;
        if (x%2==0)
        {
            if (y%2==0)
            {
                for (int yy = y-1; yy <= y+1; yy+=2)
                    if (q.find(mp(x, yy))!=q.end())
                    {
                        ll o=q[mp(x, yy)];
                        c[i*2+1].pb(edges.size());
                        edges.pb(edge(i*2+1, o*2, 1e9));
                        c[o*2].pb(edges.size());
                        edges.pb(edge(o*2, i*2+1, 0));
                    }
            }else
            {
                for (int xx = x-1; xx <= x+1; xx+=2)
                    if (q.find(mp(xx, y))!=q.end())
                    {
                        ll o=q[mp(xx, y)];
                        c[i*2+1].pb(edges.size());
                        edges.pb(edge(i*2+1, o*2, 1e9));
                        c[o*2].pb(edges.size());
                        edges.pb(edge(o*2, i*2+1, 0));
                    }
            }
        }else
        {
            if (y%2==0)
            {
                c[s].pb(edges.size());
                edges.pb(edge(s, i*2, 1e9));
                c[i*2].pb(edges.size());
                edges.pb(edge(i*2, s, 0));

                for (int xx = x-1; xx <= x+1; xx+=2)
                    if (q.find(mp(xx, y))!=q.end())
                    {
                        ll o=q[mp(xx, y)];
                        c[i*2+1].pb(edges.size());
                        edges.pb(edge(i*2+1, o*2, 1e9));
                        c[o*2].pb(edges.size());
                        edges.pb(edge(o*2, i*2+1, 0));
                    }
            }else
            {
                c[i*2+1].pb(edges.size());
                edges.pb(edge(i*2+1, t, 1e9));
                c[t].pb(edges.size());
                edges.pb(edge(t, i*2+1, 0));
            }
        }
    }

    while (bfs())
    {
        //cout << "!\n";
        while (1)
        {
            ll p=dfs(n*2,1e9);
            if (p==0) break;
            ans-=p;
        }
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/