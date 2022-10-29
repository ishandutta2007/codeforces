#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, ans, r, a[500001], T, o, an=0, b[500001], dp[300005][3];
vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i];
            dp[i][0]=1e18;
            dp[i][1]=1e18;
            dp[i][2]=1e18;
        }
        dp[n+1][0]=1e18;
        dp[n+1][1]=1e18;
        dp[n+1][2]=1e18;
        dp[1][0]=0;
        dp[1][1]=0;
        dp[1][2]=0;
        a[0]=-5;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 3; j++)
            {
                if (a[i-1]+j!=a[i])
                {
                    dp[i+1][0]=min(dp[i][j],dp[i+1][0]);
                }
                if (a[i-1]+j!=a[i]+1)
                {
                    dp[i+1][1]=min(dp[i+1][1],dp[i][j]+b[i]);
                }
                if (a[i-1]+j!=a[i]+2)
                {
                    dp[i+1][2]=min(dp[i+1][2],dp[i][j]+b[i]*2);
                }
            }
        cout << min(min(dp[n+1][0],dp[n+1][1]),dp[n+1][2]) << "\n";
    }
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