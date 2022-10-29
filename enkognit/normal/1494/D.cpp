#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
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

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, kl, T, ans=1, jj, zrp[2005], a[505][505];
bool tt[1001];
vector<pll> an;

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%md;
        h=(h*h)%md;
        r/=2;
    }
    return l;
}

ll rec(vector<ll> v,ll mx)
{
    if (v.size()==1)
    {
        zrp[v[0]]=a[v[0]][v[0]];
        return v[0];
    }
    for (int i = 0; i < v.size(); i++) tt[v[i]]=0;
    ll nw=++kl;
    //cout << nw << " " << v.size() << "\n";
    //for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    //cout << "\n";
    zrp[nw]=mx;
    vector<vector<ll> > u;
    vector<ll> e;
    for (int i = 0; i < v.size(); i++)
        if (!tt[v[i]])
        {
            ll o=a[v[i]][v[i]];
            u.pb({v[i]});
            for (int j = i+1; j < v.size(); j++)
                if (a[v[i]][v[j]]<mx)
                {
                    o=max(o, a[v[i]][v[j]]);
                    tt[v[j]]=1;
                    u.back().pb(v[j]);
                }
            e.pb(o);
        }
    for (int i = 0; i < u.size(); i++)
    {
        ll r=rec(u[i], e[i]);
        an.pb(mp(r, nw));
    }
    return nw;
}

void solve()
{
    cin >> n;
    kl=n;
    ll mx=0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            mx=max(mx, a[i][j]);
        }
    vector<ll> v;
    for (int i = 1; i <= n; i++) v.pb(i);
    ll r=rec(v, mx);
    cout << kl << "\n";
    for (int i = 1; i <= kl; i++) cout << zrp[i] << " ";
    cout << "\n";
    cout << r << "\n";
    for (int i = 0; i < an.size(); i++)
    {
        cout << an[i].fi << " " << an[i].se << "\n";
    }
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
    }
    return 0;
}
/*
4 2
30 40 50 60
30 40
50 60

4 4
25 25 30 50
10 40
20 30
70 100
50 50
*/