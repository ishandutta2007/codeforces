#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, q, C, T, Z;

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h;
        h*=h;
        r /= 2;
    }
    //cout << l << "\n";
    return l;
}

void solve()
{
    cin >> n >> m;
    if (n%m)
    {
        cout << n << "\n";
        return;
    }
    vector<pll> v;
    ll p=sqrt(m), x=m;
    for (int i = 2; i <= p; i++)
        if (x%i==0)
        {
            v.pb(mp(i, 0));
            while (x%i==0) x/=i, v.back().se++;
        }
    if (x>1) v.pb(mp(x, 1));
    ll ans=0;
    for (int i = 0; i < v.size(); i++)
    {
        ll x=n;
        while (x%v[i].fi==0) x/=v[i].fi;
        x*=binpow(v[i].fi,v[i].se-1);
       // cout << " " << v[i].fi << " " << v[i].se << " " << x << "\n";
        ans=max(ans, x);
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}