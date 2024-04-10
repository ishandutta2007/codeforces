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

ll n, m, k, h, T, ans, RR=0, b[1000001], pr[100001], pr1[1000001], c[1000001];
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
    ll m, q, a;
    cin >> n >> a >> q >> m;
    m=min(m,a+q);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];

    }
    sort(b+1,b+n+1);
    for (int i = 1; i <= n; i++)
    {
        pr[i]=pr[i-1]+b[i];
    }
    ll ans=1e18, sm=pr[n];
    ll p=sm/n;


    {
        ll u=sm%n, an=u*q;
        for (int i = 1; i <= n; i++) c[i]=b[i];
        for (int i = n; i > 0 && u>0; i--)
        {
            ll y=min(u,c[i]-p);
            c[i]-=y;u-=y;
        }
        for (int i = 1; i <= n; i++)
        {
            an+=max((c[i]-p),0ll)*m;
        }
        //cout << an << "\n";
        ans=min(ans,an);
    }
    if (sm%n!=0)
    {
        p++;
        ll u=(n-sm%n)%n, an=u*a;
        for (int i = 1; i <= n; i++) c[i]=b[i];
        for (int i = 1; i <= n && u>0; i++)
        {
            ll y=min(u,p-c[i]);
            c[i]+=y;u-=y;
        }
        for (int i = 1; i <= n; i++)
        {
            //cout << c[i] << " " << p << " " << m << "\n";
            an+=max((p-c[i]),0ll)*m;
        }
        //cout << an << "\n";
        ans=min(ans,an);
    }

    for (int i = 1; i <= n; i++)
    {
        ll l=i*b[i]-pr[i], r=pr[n]-pr[i]-(n-i)*b[i];
        if (l<r)
        {
            ans=min(ans, l*m+(r-l)*q);
        }else
        {
            ans=min(ans, r*m+(l-r)*a);
        }
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