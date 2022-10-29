#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 shue_ppsh
#define all(a) a.begin(),a.end()

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, a[1000001], dp[501][501];
string s, d;
ll tt[1001];
vector<ll> c[1001];

void solve()
{
    cin >> s;
    n=s.size();
    cin >> d;
    m=d.size();
    s=' '+s;
    d=' '+d;
    for (int it = 1; it <= m; it++)
    {
        for (int i = 0; i <= n; i++)
        {
            dp[i][0]=0;
            for (int j = 1; j <= it; j++) dp[i][j]=-1;
        }
        dp[0][0]=0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= it; j++)
                if (dp[i][j]!=-1)
                {
                    if (j<it && s[i+1]==d[j+1]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
                    if (it+dp[i][j]<m && s[i+1]==d[it+dp[i][j]+1])
                        dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1);
                    dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                }
        //if (it==4) cout << dp[n][it] << "\n";
        if (dp[n][it]==m-it) {cout << "YES\n";return;}
    }
    cout << "NO\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6 4
1 2
6 5
3 2
4 5
*/