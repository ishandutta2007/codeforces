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

const ll MOD = 1e9+7;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
//ll p1 = 31, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, a[1000001], b[1000001], dp[1000001];
//vector<ll> v[500001];

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
    //cout << l << "\n";
    return l;
}

void solve()
{
    ll n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
    {
        cin >> b[i];
        //tt[b[i]]=1;
        if (i>1 && a[b[i]]-a[b[i-1]]<b[i]-b[i-1])
        {
            cout << "-1\n";
            return;
        }
    }
    b[0]=0;
    a[0]=-1e18;
    b[k+1]=n+1;
    a[n+1]=1e18;
    ll ans=0;
    dp[0]=-1e18;
    for (int j = 1; j <= n; j++) dp[j]=1e18;
    for (int i = 0; i <= k; i++)
    {
        ll s=b[i]+1, f=b[i+1]-1, mx=0;
        dp[0]=a[b[i]]-b[i];
        for (int j = s; j <= f; j++)
            if (a[j]-a[s-1]>=j-s+1 && a[f+1]-a[j]>=f+1-j)
            {
                ll o=a[j]-j;
                ll l=0, r=mx;
                //cout << o << "\n";
                while (l<r)
                {
                    int w=(l+r+1)/2;
                    if (dp[w]<=o) l=w; else r=w-1;
                }
                if (l==0 && o<dp[0]) continue;
                mx=max(mx, l+1);
                dp[l+1]=min(dp[l+1], o);
                //cout << mx << " " << dp[1] << "-\n";
            }
        for (int j = 1; j <= mx; j++) dp[j]=1e18;
        ans+=(f-s+1)-mx;
    }
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("document.in","r",stdin);
    //freopen("document.out","w",stdout);
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
1 4
4 3
8 1
3
1
3
2
*/