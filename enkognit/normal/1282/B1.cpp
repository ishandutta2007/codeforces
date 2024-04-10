#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit
#define sqr(a) ((a)*(a))

using namespace std;

const ll MOD=1e9+7;
const ll N=1e6+1;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

const ll md1=1e9+7, md2=998244357, md3=rnd()%(ll)(1e8), p1=31, p2=37, p3=41;

//template <typename T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, k, l, T, ans, i, j, h, sum1, sum2, pr[1000001], pp=0, a[10000001], dp[1000001];
string s, d;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--)
    {
        ll n, p, k;
        cin >> n >> p >> k;
        dp[0]=0;
        for (int i = 1; i <= n; i++) {cin >> a[i];dp[i]=0;}
        sort(a+1,a+n+1);
        ll ans=0;
        pr[0]=0;
        for (int i = 1; i <= n; i++) pr[i]=pr[i-1]+a[i];
        ll l=0;
        for (ll i = 1; i <= n; i++)
        {
            l+=a[i];
            if (i>=k)
            {
                dp[i]=dp[i-k]+a[i];
                if (dp[i]<=p)
                {
                    ll l=0, r=i-i/k*k;
                    while (l<r)
                    {
                        ll w=(l+r+1)/2;
                        if (pr[w]+dp[i]<=p) l=w; else r=w-1;
                    }
                    ll lr=i, rr=n;
                    while (lr<rr)
                    {
                        ll w=(lr+rr+1)/2;
                        if (pr[w]-pr[i]+dp[i]+pr[l]<=p) lr=w; else rr=w-1;
                    }
                    if (pr[lr]-pr[i]+dp[i]+pr[l]<=p) ans=max(i/k*k+r+lr-i,ans);
                    //cout << dp[i]+pr[l] << "-\n";
                }
            }
            if (l<=p) ans=max(i,ans);
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
3
0 0 2
8 10 3
16 0 3

2
0 0 1
6 0 1

*/