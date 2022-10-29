#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

ll n, l, m, k, a[100002],dp[100002][6];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    cin >> s;
    string d="hard";
    for (int i = 0; i < n; i++) {cin >> a[i];for (int j = 0; j < 5; j++) dp[i][j]=1e18;}
    for (int j = 0; j < 5; j++) dp[n][j]=1e18;
    dp[0][0]=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 4; j++)
        {
            if (s[i]!=d[j]) dp[i+1][j]=min(dp[i+1][j],dp[i][j]); else
            {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
            }
        }
    cout << min(min(dp[n][0],dp[n][1]),min(dp[n][2],dp[n][3]));
    return 0;
}