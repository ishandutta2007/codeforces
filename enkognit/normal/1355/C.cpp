#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll INF=1e18;
const ld E=1e-8;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, h, T, ans, RR=0, a[1000001];
string s;

ll binpow(ll h, ll r, ll md = MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l *= h, l %= md;
        h *= h;
        h %= md;
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

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans=0;
    for (int i = a; i <= b; i++)
    {
        ll p=c-i+1;
        if (p>c) continue;
        ll o=c;
        if (p<b) o+=(b-p),p=b;
        o=min(o,d);
        ll u=d-o;
        //cout << i << " " << o << " " << p << "\n";
        if (p+u>=c)
        {
            ll r=o+(c-p);
            ans+=(r-c+1)*(r-c+2)/2-(o-c+1)*(o-c)/2;
        }else
        {
            ll r=d;
            ans+=(r-c+1)*(r-c+2)/2-(o-c+1)*(o-c)/2;
            p+=u;
            ans+=(c-p)*(d-c+1);
        }
        //cout << ans << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input3.txt","r",stdin);
    //freopen("output3.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cout << "-\n";
    while (t--)
    {
        solve();
    }
    return 0;
}