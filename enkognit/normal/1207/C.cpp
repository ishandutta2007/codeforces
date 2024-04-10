#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, dp[200001][3];
pll b[100001];
vector <ll> c[300001];
string s;

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a, b;
        cin >> n >> a >> b;
        cin >> s;
        for (int i = 0; i <= n; i++) dp[i][1]=1e18, dp[i][2]=1e18;
        dp[0][1]=b;
        for (int i = 0; i < n; i++)
            for (int j = 1; j < 3; j++)
            {
                if (s[i]=='0')
                {
                    if (j==1)
                    {
                        dp[i+1][j]=min(dp[i+1][j], dp[i][j]+a+b);
                        dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]+a*2+b*2);
                    }else
                    {
                        dp[i+1][j]=min(dp[i+1][j], dp[i][j]+a+b*2);
                        dp[i+1][j-1]=min(dp[i+1][j-1], dp[i][j]+a*2+b);
                    }
                }else
                {
                    if (j==2)
                    {
                        dp[i+1][j]=min(dp[i+1][j], dp[i][j]+a+b*2);
                    }
                }
                //cout << dp[i][j] << " ";
            }
            cout << dp[n][1] << "\n";
    }
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/