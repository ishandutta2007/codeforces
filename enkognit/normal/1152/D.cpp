#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, dp[3005][2005][2];
vector <ll> v, ans;

bool lo(ll h)
{
    while (h%2==0) h/=2;
    return (h==1);
}

ll gcd(ll x,ll y)
{
    if (x==0) return y; else
    if (y==0) return x; else
    return __gcd(x,y);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    dp[0][0][0]=1;
    ll ans=0, ans1=0;
    for (int i = 0; i < n*2; i++)
        for (int j = 0; j <= min((ll)i,n*2-i); j++)
            for (int u = 0; u < 2; u++)
            {
                dp[i][j][u]%=MOD;
                bool tt=1;
                if (j>0)
                {
                    if (u==1)dp[i+1][j-1][0]+=dp[i][j][u];
                    if (u==0)
                    {
                        ans+=tt*dp[i][j][u];
                        dp[i+1][j-1][tt]+=dp[i][j][u];
                        tt=0;
                    }
                    dp[i+1][j-1][0]%=MOD;
                    dp[i+1][j-1][1]%=MOD;
                }
                if (j+1<=n*2-i-1)
                {
                    if (u==1)dp[i+1][j+1][0]+=dp[i][j][u];
                    if (u==0)
                    {
                        ans+=tt*dp[i][j][u];
                        dp[i+1][j+1][tt]+=dp[i][j][u];
                        tt=0;
                    }
                    dp[i+1][j+1][0]%=MOD;
                    dp[i+1][j+1][1]%=MOD;
                }
                ans%=MOD;
            }
    cout << ans;
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/