#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const unsigned ll MOD=1e17+7;

ll ans=0, n, p;
ll dp[1001][1001];
vector <ll> c[200001];
string s;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    s=' '+s;
    for (int r = 1; r <= n; r++)
    {
        dp[r][r]=1;
        for (int l = r-1; l > 0; l--)
        {
            dp[l][r]=dp[l+1][r]+1;
            ll last=l+1;
            for (int i = l+1; i <= r; i++)
                if (s[i]==s[l]) dp[l][r]=min(dp[l][r],dp[l+1][i-1]+dp[i][r]);
        }
    }
    cout << dp[1][n] << "\n";
    return 0;
}