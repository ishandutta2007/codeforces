#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second


using namespace std;

const ll MOD=1e9+7;

ll n, m, k, l, r, i, j, a[100001], b[100001], c[100001], dp[200001][2][3];

ll gcd(ll x,ll y)
{
    if (x==0 || y==0) return x+y; else return __gcd(x,y);
}

int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    dp[1][0][1]=1;
    dp[1][1][1]=1;
    for (int i = 2; i <= 100005; i++)
    {
        dp[i][0][1]+=(dp[i-1][1][1]+dp[i-1][1][2])%MOD;
        dp[i][0][1]%=MOD;
        dp[i][0][2]+=dp[i-1][0][1]%MOD;
        dp[i][0][2]%=MOD;
        dp[i][1][1]+=(dp[i-1][0][1]+dp[i-1][0][2])%MOD;
        dp[i][1][1]%=MOD;
        dp[i][1][2]+=dp[i-1][1][1]%MOD;
        dp[i][1][2]%=MOD;
    }
    cout << (dp[m][0][1]+dp[m][0][2]+dp[m][1][1]+dp[m][1][2]+dp[n][0][1]+dp[n][0][2]+dp[n][1][1]+dp[n][1][2]-2)%MOD;
    return 0;
}