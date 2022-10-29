#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, ans, r, a[400001], T, o, an=0, dp[1000001], z[1000001];
vector <ll> c[300001];
bool tt[500001];

void dfs(ll h,ll k)
{
    tt[h]=1;
    dp[h]=max(k+a[h],dp[h]);
    for (int i = 0; i < c[h].size(); i++)
    {
        if (!tt[c[h][i]] && c[h][i]!=o && z[c[h][i]]==2) dfs(c[h][i], dp[h]); else
        if (!tt[c[h][i]] && c[h][i]!=o) dp[c[h][i]]=max(dp[c[h][i]],dp[h]+a[c[h][i]]), z[c[h][i]]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {cin >> a[i];}
    for (int i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y), c[y].pb(x);
    }
    cin >> o;
    for (int i = 1; i <= n; i++) z[i]=c[i].size();
    ll mx=0;
    for (int i = 1; i <= n; i++)
        if (i!=o)
    {
        if (c[i].size()==1) dfs(i,0);
    }
    mx=0;
    for (int i = 1; i <= n; i++)
    {
        //cout << tt[i] << " " << a[i] << " " << dp[i] << "\n";
        if (!tt[i]) ans+=a[i]; else mx=max(mx,dp[i]);
    }
    cout << ans+mx;
    return 0;
}
/*
8 7
1 1 30 5 5 1 1 1
1 2
2 3
2 4
4 5
2 6
6 7
6 8
2
*/