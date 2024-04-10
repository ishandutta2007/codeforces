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

ll n, m, k, T;
pll a[1000001];
ll pr[1000001];
pll pp[1000001];

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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se=i;
    }
    if (n==1)
    {
        cout << a[1].fi;
        return;
    }
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
    {
        pr[i]=pr[i-1]+a[i].fi;
    }
    ll o=n%3, p=0, ans=-1e18;
    if (o==2) p=2; else
    if (o==0) p=1;
    for (int i = 1; i <= n; i++)
    {
        pp[i]=pp[i-1];
        if (a[i].se%2) pp[i].fi|=1;
        if (a[i].se%2==0) pp[i].se|=1;
    }
    for (int i = p; i <= n; i+=3)
    {
        if (n/2==i && pp[i].fi==0 && i<n)
        {
            ll u=pr[n]-2*pr[i-1];
            u-=a[i+1].fi*2;
            ans=max(ans, u);
            continue;
        }
        if ((n+1)/2==i && pp[i].se==0 && i<n)
        {
            ll u=pr[n]-2*pr[i-1];
            u-=a[i+1].fi*2;
            ans=max(ans, u);
            continue;
        }
        //cout << i << " " << pr[n]-2*pr[i] << "\n";
        ans=max(ans, pr[n]-2*pr[i]);
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
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

*/