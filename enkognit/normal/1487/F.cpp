#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, dd, m, k, T, jj;
int dp[252][252][60], dp1[252][252][60];

ll gcd(ll x, ll y)
{
    while (x && y)
    {
        if (x<y) swap(x,y);
        x%=y;
    }
    //cout << x+y << "\n";
    return x+y;
}

void solve()
{
    string s;
    cin >> s;
    n=s.size();
    reverse(all(s));
    s=s+"0";
    for (int i = 0; i <= 5*n; i++)
        for (int j = 0; j <= 5*n; j++)
            for (int u = 0; u <= 57; u++) dp[i][j][u]=1e9;
    dp[n*5][n*5][28]=0;
    int it, i, j, u, nv, nu, p;
    for (it = 0; it < s.size(); it++)
    {
        for (i = 5*n; i > -1; i--)
            for (j = n*5; j > -1; j--)
                for (u = 0; u <= 57; u++)
                {
                    dp1[i][j][u]=1e9;
                }
        for (i = n*5; i > -1; i--)
            for (j = n*5; j > -1; j--)
                for (u = 0; u <= 57; u++)
                    if (dp[i][j][u]!=1e9)
                    {
                        if (i>0) dp[i-1][j][u]=min(dp[i-1][j][u], dp[i][j][u]);
                        if (j>0) dp[i][j-1][u]=min(dp[i][j-1][u], dp[i][j][u]);
                        nv=u-28+i-j;
                        p=nv%10;
                        if (p<0) p+=10;
                        nu=nv/10;
                        if (nv<0 && p>0) nu--;
                        if (s[it]-'0'==p)dp1[i][j][nu+28]=min(dp1[i][j][nu+28], dp[i][j][u]+i+j);
                    }
        /*cout << it << "\n";
        for (int i = 0; i <= n*5; i++)
            for (int j = 0; j <= n*5; j++)
                for (int u = 0; u <= 59; u++)
                    if (dp1[i][j][u]!=1e18)
                {
                    cout << " " << i << " " << j << " " << u-29 << " " << dp1[i][j][u] << "\n";
                }
                */
        swap(dp, dp1);
    }
    ll ans=1e18;
    for (int i = 0; i <= 5*n; i++)
        for (int j = 0; j <= 5*n; j++) ans=min(ans, (ll)dp[i][j][28]);
    cout << ans << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

10
4 1 7 6 5 5 4 2 3 1
*/