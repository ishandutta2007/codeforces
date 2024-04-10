#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 999999001;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, k1, k2, T, K, TT, ans, a[1000001];
vector<pair<pll, ll> > v;

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

ll gcd(ll x,ll y)
{
    while (x>0 && y>0)
    {
        if (x>y) swap(x, y);
        y%=x;
    }
    return x+y;
}



void solve()
{
    cin >> n;
    vector<pll> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v1.pb(mp(x, i));
    }
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        v2.pb(mp(x, i));
    }
    sort(all(v1));
    sort(all(v2));
    for (int i = 0; i < v1.size(); i++)cout << v1[i].fi << " ";
    cout << "\n";
    swap(v1, v2);
    for (int i = 0; i < v1.size(); i++)cout << v1[i].fi << " ";
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}


/*
3
1 2 4
1 3 6

6
1 2 4
3 4 3
1 4 10
5 1 2
4 6 5
*/