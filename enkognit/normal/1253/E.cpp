#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back
#define pii pair<int,int>

using namespace std;

const ll MOD=1e9+7;

ll n, s, m, T, k, l, r, i, j, mn, mx, kol=0, ans, dp[5000001];
vector <pll> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x,y));
    }
    for (int i = 1; i <= m; i++) dp[i]=1e18;
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < v.size(); j++)
        {
            ll p=max(0ll, v[j].fi-v[j].se-i);
            dp[min(m, v[j].fi+v[j].se+p)]=min(dp[min(m, v[j].fi+v[j].se+p)], dp[i-1]+p);
        }
    ll ans=1e18;
    for (int i = 0; i <= m; i++) ans=min(ans, dp[i]+m-i);
    cout << ans;
    return 0;
}