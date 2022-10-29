#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define y1 Enkognit
#define ld long double
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll INF=1e18;
const ll MOD=1e9+7;

template<typename T>
using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, l, r, dist[200001], kl[200001], a[200001];
vector<ll> c[200001];
string s;

ll binpow(ll h,ll r,ll md=MOD)
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

void dij(int h)
{
    set<pair<ll,ll> > s;
    for (int i = 1; i <= n; i++) dist[i]=1e18;
    dist[h]=0;
    //kl[h]=1;
    s.insert(mp(0,h));
    while (s.size())
    {
        ll x=(*s.begin()).se, h=(*s.begin()).fi;
        s.erase(s.begin());
        for (int i = 0; i < c[x].size(); i++)
            if (dist[c[x][i]] > h+1)
            {
                s.erase(mp(dist[c[x][i]],c[x][i]));
                //kl[c[x][i]]=1;
                dist[c[x][i]]=h+1;
                s.insert(mp(dist[c[x][i]],c[x][i]));
            }
    }
}

void solve()
{
    cin >> n >> m;
    vector<pll> v;
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[y].pb(x);
        v.pb(mp(y,x));
    }
    ll p;
    cin >> p;
    for (int i = 1; i <= p; i++) cin >> a[i];
    dij(a[p]);
    for (int i = 0; i <v.size(); i++)
        if (dist[v[i].fi]+1==dist[v[i].se]) kl[v[i].se]++;

    ll mx=0, mn=0;
    for (int i = 1; i < p; i++)
    {
        //cout << a[i] << " " << dist[a[i]] << " " << p-i << "\n";
        if (dist[a[i]]==dist[a[i+1]]+1)
        {
            if (kl[a[i]]>1) mx++;
        }else
        mn++, mx++;
    }
    cout << mn << " " << mx << "\n";
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}