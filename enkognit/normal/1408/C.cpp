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
const ld E = 1e-7;
const ld PI=acos(-1);
mt19937_64 rnd(time(0));
ll p1 = 31, p2 = 37, p3 = 7, p4 = rnd() % 100 + 1, md1 = MOD, md2 = 998244353, md3 = 998244357, md4 = rnd() % 1000000000;

//using ord_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

ll n, m, a[1000001];
ld pr[100001], sf[100001];

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

void solve()
{
    cin >> n >> m;
    sf[n+1]=0;
    for (int i = 1; i <= n; i++)
    {
        pr[i]=0;
        sf[i]=0;
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pr[i]=pr[i-1]+((ld)(a[i]-a[i-1]))/((ld)i);
    }
    a[n+1]=m;
    for (int i = n; i > 0; i--)
    {
        sf[i]=sf[i+1]+((ld)(a[i+1]-a[i]))/((ld)(n-i+1));
    }
    ld l=0, r=m;
    while ((r-l)>E)
    {
        ld w=(l+r)/2;
        ll lr=0, rr=n;
        while (lr<rr)
        {
            int wr=(lr+rr+1)/2;
            //cout << lr << " " << rr  << "\n";
            if (a[wr]<=w) lr=wr; else rr=wr-1;
        }
        ll p=lr;
        //cout << w << " " << a[p] << " " <<  pr[p]+(w-a[p])/(ld)p << " " << sf[p+1]+(a[p+1]-w)/(n-p+1) << "\n";
        if (pr[p]+(w-a[p])/(ld)(p+1)<sf[p+1]+(a[p+1]-w)/(n-p+1)) l=w; else r=w;
    }
    cout.precision(10);
    ll lr=0, rr=n;
        while (lr<rr)
        {
            int wr=(lr+rr+1)/2;
            //cout << lr << " " << rr  << "\n";
            if (a[wr]<=l) lr=wr; else rr=wr-1;
        }
    cout <<fixed<< pr[lr]+(l-a[lr])/((ld)lr+1) << "\n";
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
/*
1
4
1 2 9 13
5 6 10 14
3 7 11 15
4 8 12 16
*/