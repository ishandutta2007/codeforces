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

ll n, m, T, a[1000001], pr[200005][2], sf[200005][2];

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
    pr[0][0]=0;
    pr[0][1]=0;
    sf[n+1][0]=0;
    sf[n+1][1]=0;
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i&1) ans+=a[i];
        pr[i][0]=pr[i-1][0];
        pr[i][1]=pr[i-1][1];
        pr[i][i&1]+=a[i];
    }
    for (int i = n; i > 0; i--)
    {
        sf[i][0]=sf[i+1][0];
        sf[i][1]=sf[i+1][1];
        sf[i][i&1]+=a[i];
    }
    for (int i = 1; i < n; i++)
    {
        //cout << i << " " << a[i] << " " << a[i+1] << " " << pr[i-1][i&1] << " " <<
        ans=max(ans, a[i]+a[i+1]+pr[i-1][i&1]+sf[i+2][(i+1)&1]);
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
    while (t--)
    {
        solve();
    }
    return 0;
}

/*
3
4 2
1 1
1 0
3 2
2 2

3 1
1 1
1 0
3 2

3 2
1 1
1 0
3 2
*/