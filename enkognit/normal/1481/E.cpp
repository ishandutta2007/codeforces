#include <bits/stdc++.h>
//#include <random>
//#include <ctime>
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
#define cringe exit(0)
#define y1 Enkognit

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 1e9+7;
const ll md = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-10;
//mt19937_64 rnd(time(0));
ll p1 = 29, p2 = 17, p3 = 13, md1 = MOD, md2 = md, md3 = 998244353;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

int n, m, k, T, ans, q, p, Z, a[500005], kl[500005], in[500005], out[500005], dp[500005];
int prv[500005];

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

ll binpow(ll h, ll r)
{
    ll l = 1;
    while (r)
    {
        if (r & 1) l*=h;
        h*=h;
        r /= 2;
    }
    return l;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        kl[a[i]]++;
        prv[i]=kl[a[i]];
        if (in[a[i]]==0)
        {
            in[a[i]]=i;
        }
        out[a[i]]=i;
    }
    ll ans=n;
    for (int i = 1; i <= n; i++)
    {
        //cout << " " << dp[i-1] << " " << kl[a[i]] << " " << prv[i] << "\n";
        ans=min((int)ans, n-dp[i-1]-(kl[a[i]]-prv[i]+1));
        dp[i]=max(dp[i], dp[i-1]);
        if (1==prv[i])
            dp[out[a[i]]]=max(dp[i-1]+kl[a[i]], dp[out[a[i]]]);
        //cout << i << " " << dp[i] << "\n";
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //freopen("stones.in","r",stdin);
    //freopen("stones.out","w",stdout);
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

4
37 29 8 5
13 118 86 6 1000

*/