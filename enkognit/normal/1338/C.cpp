#include <bits/stdc++.h>
#include <random>
#include <ctime>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
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
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, k, d, h, T, P, mn=1, mx=0, a[1000001], pr[1000001], in[1000001], out[1000001], hh[1000001];
vector<ll> v;
vector<ll> c[1000001];
ll bn[1000001][20];
ll tt[1000001];

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
    cin >> n;
    ll pp=n%3;
    n--;
    n/=3;
    n++;
    ll p=0, l=1, u=0;
    while (p+l<n)
    {
        p+=l;
        l*=4;
        u++;
    }
    vector<ll> v;
    ll o=n-p;
    while (u--)
    {
        v.pb(o%4);
        o--;
        o/=4;
        o++;
    }
    reverse(all(v));
    ll a=1, b=2, c=3;
    for (int i = 0; i < v.size(); i++)
    {
        a*=4;
        b*=4;
        c*=4;
        if (v[i]==2) a++, b+=2, c+=3; else
        if (v[i]==3) a+=2, b+=3, c++; else
        if (v[i]==0) a+=3, b++, c+=2;
    }
    if (pp==1) cout << a << "\n"; else
    if (pp==2) cout << b << "\n"; else
    if (pp==0) cout << c << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    //for (ll i = 1; i <= 60; i++) pr[i]=pr[i-1]+(1ll<<(i-1));
    ll t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

ghlaz
azjgh

*/