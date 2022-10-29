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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, ans, a[100001];

ll binpow(ll h, ll r, ll md)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    return l;
}

ll inverse(ll h)
{
    return binpow(h, md-2, md);
}

void solve()
{
    cin >> n;
    ll f=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f^=a[i];
    }
    if (n%2==0 && f!=0)
    {
        cout << "NO\n";
        return;
    }
    if (n==3)
    {
        cout << "1\n1 2 3\n";
        return;
    }
    if (n%2)
    {
        cout << "YES\n";
        vector<pair<pii, int> > v;
        for (int i = 1; i <= n-2; i+=2)
        {
            v.pb(mp(mp(i, i+1), i+2));
        }
        for (int i = 1; i <= n-2; i+=2)
        {
            v.pb(mp(mp(i, i+1), n));
        }
        cout << v.size() << "\n";
        for (int i = 0; i < v.size(); i++) cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se << "\n";
    }else
    {
        cout << "YES\n";
        vector<pair<pii, int> > v;
        for (int i = 1; i <= n-3; i+=2)
        {
            v.pb(mp(mp(i, i+1), i+2));
        }
        for (int i = 1; i <= n-3; i+=2)
        {
            v.pb(mp(mp(i, i+1), n-1));
        }
        cout << v.size() << "\n";
        for (int i = 0 ;i < v.size(); i++) cout << v[i].fi.fi << " " << v[i].fi.se << " " << v[i].se << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("d.in","r",stdin);
    //freopen("d.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
2 2 1
ab
ba
ba
ab

2 2 1
ab
cd
dc
ba

3 3 1
abc
acc
adc
cda
acc
cba

*/