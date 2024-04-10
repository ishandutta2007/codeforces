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

ll n, m, a[1000001], dp[1000001];

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

ll d[1000001];

void update(int h,int l,int r,int x,int k)
{
    if (l==r)
    {
        d[h]=k;
        return;
    }
    int w=(l+r)/2;
    if (x<=w) update(h*2,l,w,x,k); else update(h*2+1,w+1,r,x,k);
    d[h]=(d[h*2]+d[h*2+1])%MOD;
}

ll get(int h,int l,int r,int x,int y)
{
    if (x>y) return 0;
    if (l==x && y==r) return d[h];
    int w=(l+r)/2;
    return (get(h*2,l,w,x,min(y,w))+get(h*2+1,w+1,r,max(x,w+1),y))%MOD;
}

void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        a[i]=min(i-1,n-i);
    }
    ll sm0=1, sm1=0;
    for (int i = 1; i <= n; i++)
    {
        if (i%2)
        {
            dp[i]=sm0;
            sm1=(sm1+dp[i])%MOD;
        }else
        if (i%2==0)
        {
            dp[i]=sm1;
            sm0=(sm0+dp[i])%MOD;
        }
    }
    ll p=dp[n], o=binpow(2, n, MOD);
    o=binpow(o, MOD-2, MOD);
    cout << (p*o)%MOD << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/