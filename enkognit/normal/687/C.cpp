#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, q, ans, l, r, i, j, dp[600][600];
ll a[501];

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n >> m;
    ll x;
    dp[0][0]=1;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        for (int j = m; j > -1; j--)
            for (int u = m; u > -1; u--)
              if (dp[j][u])
            {

                if (j+x<=m) dp[j+x][u]=1;
                if (u+x<=m) dp[j][u+x]=1;
            }
    }
    vector <ll> v;
    for (int i = 0; i <= m; i++)
    {
        if (dp[i][m-i]==1) v.pb(i);
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    return 0;
}