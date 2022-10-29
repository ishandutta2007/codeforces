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

ll n, m, k, q, ans, sm[3005];
vector<ll> a[3005];
ll dp[20001][3005];

ll binpow(ll h, ll r, ll md=MOD)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h, l%=md;
        h*=h;
        h%=md;
        r /= 2;
    }
    //cout << l << "\n";
    return l;
}

void rec(int h,int l,int r)
{
    if (l==r)
    {
        ans=max(ans, dp[h][k]);
        ll o=0;
        for (int i = 0; i < min(k, (ll)a[l].size()); i++)
        {
            o+=a[l][i];
            ans=max(ans, dp[h][k-i-1]+o);
        }
        return;
    }
    int w=(l+r)/2;
    for (int i = 0; i <= k; i++) dp[h*2][i]=dp[h][i], dp[h*2+1][i]=dp[h][i];
    for (int i = l; i <= w; i++)
    {
        for (int j = k-(int)a[i].size(); j > -1; j--)
        {
            dp[h*2+1][j+(int)a[i].size()]=max(dp[h*2+1][j]+sm[i], dp[h*2+1][j+(int)a[i].size()]);
        }
    }
    for (int i = w+1; i <= r; i++)
    {
        for (int j = k-(int)a[i].size(); j > -1; j--)
        {
            dp[h*2][j+(int)a[i].size()]=max(dp[h*2][j]+sm[i], dp[h*2][j+(int)a[i].size()]);
        }
    }
    rec(h*2,l,w);
    rec(h*2+1,w+1,r);
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++) dp[1][i]=0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            ll y;
            cin >> y;
            if (j<=k)
            {
                a[i].pb(y);
                sm[i]+=y;
            }
        }
    }
    rec(1,1,n);
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*fact[0]=1;
    infact[0]=1;
    for (ll i = 1; i <= 300000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        infact[i]=binpow(fact[i],MOD-2);
    }*/
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}