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
#define do_anal exit(0)

using namespace std;
//using namespace __gnu_pbds;

const ll MOD = 998244353;
const ll md = 11234549;
const ld PI = acosl(-1.0);
const ld E = 1e-15;
mt19937_64 rnd(time(0));
ll p1 = 227, p2 = 29 + rnd() % 100, md1 = MOD, md2 = MOD - rnd() % 1000;


//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, T, dp[1000001];
vector<pair<pll, ll> > v;

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

void solve()
{
    cin >> n >> k;
    v.pb(mp(mp(0,0), 0));
    for (int i = 1; i <= n; i++)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        v.pb(mp(mp(l,r), x));
        if ((r-l+1)*k<x)
        {
            cout << "-1\n";
            return;
        }
    }
    v.pb(mp(mp(1e18,1e18+5), 0));
    for (int i = 2; i <= n+1; i++) dp[i]=1e18;
    for (int i = 1; i <= n; i++)
        if (dp[i]!=1e18)
        {
            ll o=k, sm=0;
            for (int j = i; j <= n; j++)
            {
                if (v[j].se-o>(v[j].fi.se-v[j].fi.fi)*k) break;
                ll p=max((v[j].se-o+k-1)/k, 0ll);
                sm+=v[j].se;
                o=(k-sm%k)%k;
                if (v[j].fi.fi+p<v[j+1].fi.fi) dp[j+1]=min(dp[j+1], dp[i]+sm+(j!=n?o:0));
            }
        }
    if (dp[n+1]==1e18) cout << "-1\n"; else cout << dp[n+1] << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("subsequence.in","r",stdin);
    //freopen("subsequence.out","w",stdout);
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
9 0
1 1
3 1
5 1
5 2
3 2
3 3
2 3
2 2
1 2
*/