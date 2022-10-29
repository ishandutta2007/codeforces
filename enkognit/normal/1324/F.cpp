#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

ll n, T, kl=0, m, a[300001], dp[300001], ans[300001];
vector<pll> v;
vector<ll> c[300001];

void dfs(int h, int p = -1)
{
    dp[h] = a[h];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i] != p)
        {
            dfs(c[h][i], h);
            if (dp[c[h][i]] > 0) dp[h] += dp[c[h][i]];
        }
}

void dfs2(int h, int k, int p = -1)
{
    ll o = 0;
    for (int i = 0;i < c[h].size(); i++)
        if (c[h][i]!=p)
    {
        if (dp[c[h][i]] > 0) o += dp[c[h][i]];
    }
    //cout << h << " " << k << " " << o << "\n";
    ans[h] = k + o;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i] != p)
        {
            dfs2(c[h][i], max(k + o - max(0ll, dp[c[h][i]]) + a[c[h][i]], a[c[h][i]]), h);
        }
}

int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; if (a[i] == 0) a[i] = -1; }
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    //cout << a[1] << "\n";
    dfs2(1,a[1]);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}
/*
6
add 1
sum 1 1
add 3
add 1
sum 2 3
sum 1 2
*/