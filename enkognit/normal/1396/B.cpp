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
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define sqr(a) ((a)*(a))
#define all(v) v.begin(),v.end()
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

ll MOD = 1e9+7;
const ll INF = 1e18;
const ld E = 1e-10;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, a[1000001], b[1000001];

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h;
        h *= h;
        r /= 2;
    }
    return l;
}

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    while (x && y)
    {
        x %= y;
        swap(x, y);
    }
    return x + y;
}


template<typename Z>
pair<Z,Z> operator + (pair<Z,Z> x, pair<Z,Z> y)
{
    return mp(x.fi+y.fi,x.se+y.se);
}
template<typename Z>
pair<Z,Z> operator - (pair<Z,Z> x, pair<Z,Z> y)
{
    return mp(x.fi-y.fi,x.se-y.se);
}
template<typename Z>
istream& operator >> (istream& in,pair<Z, Z>& x)
{
    in >> x.fi >> x.se;
    return in;
}
template<typename Z>
bool operator == (pair<Z,Z> x,pair<Z,Z> y)
{
    return x.fi==y.fi && y.se==x.se;
}

void solve()
{
    cin >> n;
    ll p=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p+=a[i];
    }
    p=p%2;
    sort(a+1,a+n+1);
    //reverse(a+1,a+n+1);
    ll o=0;
    for (int i = 1; i < n; i++)
        o+=a[i];
    if (o<a[n]) cout << "T\n"; else
    {
        if (p==0) cout << "HL\n"; else cout << "T\n";
    }
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
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}