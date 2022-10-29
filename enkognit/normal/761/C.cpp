#include <bits/stdc++.h>
#pragma GCC optimise("-O3")
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>
#define y1 Enkognit
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll md1=1e9+7, md2=998244353, p1=4523231, p2=5463161;

ll n, m, T, k, i, j, l, r, ans, kl, o, OK=0, dp[100001][10];
vector <ll> c[100001];
pll w[100001];
bool tt[100001];
vector <ll> v[1000001];

int main()
{
    //freopen("travelator.in","r",stdin);
    //freopen("travelator.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int j = 1; j <= n; j++)
    {
        string s;
        cin >> s;
        for (int i = 0; i < m; i++) if (s[i]>='0' && s[i]<='9') v[j].pb(1); else
            if (s[i]=='#' || s[i]=='*' || s[i]=='&') v[j].pb(2); else v[j].pb(3);
    }
    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++) cout << v[i][j] << " ";
        cout << "\n";
    }*/
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 8; j++) dp[i][j]=1e18;
    dp[0][0]=0;
    for (int i = 0; i < n; i++)
    {
        vector <ll> lr(3,1e18);
        for (ll u = 0; u < m; u++)
            lr[v[i+1][u]-1]=min(min(u,m-u), lr[v[i+1][u]-1]);
        //cout << lr[0] << "-" << lr[1] << "-" << lr[2] << "\n";
        for (ll j = 0; j < 8; j++)
            if (dp[i][j]!=1e18)
        {
            //if (dp[i][j]==1e18) cout << "-1 "; else cout << dp[i][j] << " ";
            for (ll u = 0; u < 3; u++)
                if (lr[u]!=1e18)
            {
                dp[i+1][(ll)(j|((ll)pow(2,u)))]=min(dp[i+1][(ll)(j|((ll)pow(2,u)))],dp[i][j]+lr[u]);
            }
        }
        //cout << "\n";
    }
    cout << dp[n][7];
    return 0;
}