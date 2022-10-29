#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 998244353;
const ll INF = 1e18;
const ld E = 1e-18;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, fact[300005], infact[300005];

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l%=md;
        h *= h;
        h %= md;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x==0 || y==0) return x+y;
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}

ll C(ll n,ll k)
{
    return fact[n]*infact[n-k]%MOD*infact[k]%MOD;
}

ll f[2000001];

void upd(int h)
{
    for (int i = h; i <= n*3; i+=(i&-i)) f[i]++;
}

ll get(int h)
{
    ll ans=0;
    for (int i = h; i > 0; i-=(i&-i)) ans+=f[i];
    return ans;
}

void solve()
{
    ll k;
    cin >> n >> k;
    vector<pll> v;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
    }
    sort(all(v));
    vector<pair<pll, ll>> q;
    for (int i = 0; i < n; i++)
    {
        q.pb(mp(mp(v[i].fi, i), 0));
        q.pb(mp(mp(v[i].se, i), 1));
    }
    sort(all(q));
    ll kk=0, ans=0;
    for (int i = 0; i < q.size(); i++)
    {
        if (i==0 || q[i-1].fi.fi!=q[i].fi.fi) kk++;
        if (q[i].se==0) v[q[i].fi.se].fi=kk; else v[q[i].fi.se].se=kk;
    }
    for (int i = 0; i < v.size(); i++)
    {
        ll o=i-get(v[i].fi-1);
        //cout << v[i].fi << " " << v[i].se << " " << o << "\n";
        if (o>=k-1) ans=(ans+C(o, k-1))%MOD;
        upd(v[i].se);
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 3e5; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i], MOD-2);
    }
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/