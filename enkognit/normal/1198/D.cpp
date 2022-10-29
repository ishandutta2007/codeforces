#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;
ll n, m, i, j, k, t, I, a[51][51], dp[51][51][51][51], pr[51][51];
vector <ll> v, q;
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            a[i][j+1]=(s[j]=='#');
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) pr[i][j]=pr[i-1][j]+pr[i][j-1]-pr[i-1][j-1]+a[i][j];

    for (int x2 = 1; x2 <= n; x2++)
        for (int y2 = 1; y2 <= n; y2++)
            for (int x1 = x2; x1 > 0; x1--)
                for (int y1 = y2; y1 > 0; y1--)
                {
                    if (pr[x2][y2]+pr[x1-1][y1-1]-pr[x2][y1-1]-pr[x1-1][y2]==0) continue;
                    dp[x1][y1][x2][y2]=max(x2-x1+1,y2-y1+1);
                    for (int i = 1; i <= n; i++)
                    {
                        if (i<x2 && i>=x1)dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],
                                               dp[x1][y1][i][y2]+dp[i+1][y1][x2][y2]);
                        if (i<y2 && i>=y1)dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],
                                               dp[x1][i+1][x2][y2]+dp[x1][y1][x2][i]);
                    }
                }
    cout << dp[1][1][n][n];
}