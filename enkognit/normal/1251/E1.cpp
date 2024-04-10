#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, dp[5001][5001];

string s;
string v1, v0;

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector <pll> v;
        v.pb(mp(0,0));
        for (int i = 0; i < n; i++)
        {
            ll x, y;
            cin >> x >> y;
            v.pb(mp(x,y));
        }
        sort(v.begin(),v.end());
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) dp[i][j]=1e18;
        dp[0][0]=0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++)
                if (dp[i][j]!=1e18)
        {
            dp[i+1][j+max(0ll,v[i+1].fi-i-j)]=min(dp[i+1][j+max(0ll,v[i+1].fi-i-j)],dp[i][j]);
            dp[i+1][j]=min(dp[i][j]+v[i+1].se,dp[i+1][j]);
            if (j) dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+v[i+1].se);
        }
        ll ans=dp[n][0];
        cout << ans << "\n";
    }
    return 0;
}