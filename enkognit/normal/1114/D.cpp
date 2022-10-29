#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

int n, m, i, j, k, b, r, ans, a[5001];
int dp[5001][5001][2];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int u = 0; u < 2; u++) dp[i][j][u]=1e9;

    for (int i = n-1; i >= 0; i--)
        for (int j = i; j < n; j++)
    {
        if (i)dp[i-1][j][0]=min(dp[i-1][j][0],min(dp[i][j][0]+(a[i-1]!=a[i]),dp[i][j][1]+(a[i-1]!=a[j])));
        if (j<n-1)dp[i][j+1][1]=min(dp[i][j+1][1],min(dp[i][j+1][1],min(dp[i][j][0]+(a[j+1]!=a[i]),dp[i][j][1]+(a[j+1]!=a[j]))));
    }
    cout << min(dp[0][n-1][0],dp[0][n-1][1]);
    return 0;
}