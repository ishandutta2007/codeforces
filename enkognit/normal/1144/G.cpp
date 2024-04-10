#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
//#pragma GCC optimize("-Otime")
//#pragma GCC optimize("unr")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

ll n, m, i, j, k, l, r, a[300001];
pll dp[200001][2];

int main()
{
    //freopen("tickets.in","r",stdin);
    //freopen("tickets.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i][0]=mp(-1,-1);
        dp[i][1]=mp(1e18,-1);
    }
    dp[0][1]=mp(-1,0);
    dp[0][0]=mp(1e18,0);
    for (int i = 1; i < n; i++)
    {
        if (dp[i-1][0].se!=-1 && a[i-1]<a[i]) dp[i][0]=mp(dp[i-1][0].fi, 0);
        if (dp[i-1][1].se!=-1 && a[i]>dp[i-1][1].fi && a[i-1]>dp[i][0].fi) dp[i][0]=mp(a[i-1], 1);
        if (dp[i-1][0].se!=-1 && dp[i-1][0].fi>a[i]) dp[i][1]=mp(a[i-1], 0);
        if (dp[i-1][1].se!=-1 && a[i]<a[i-1] && dp[i-1][1].fi<dp[i][1].fi) dp[i][1]=mp(dp[i-1][1].fi, 1);
        //cout << i << ": " << dp[i][0].fi << " " << dp[i][0].se << " - " << dp[i][1].fi << " " << dp[i][1].se << "\n";
    }
    vector <ll> v, z;
    if (dp[n-1][0].se!=-1)
    {
        z.pb(0);
        for (int i = n - 1; i > 0; i--)
        z.pb(dp[i][z[z.size()-1]].se);
        reverse(z.begin(),z.end());
        cout << "YES\n";
        for (int i = 0; i < z.size(); i++) cout << z[i] << " ";
        cout << "\n";
        exit(0);
    }
    if (dp[n-1][1].se!=-1)
    {
        z.pb(1);
        for (int i = n - 1; i > 0; i--)
        z.pb(dp[i][z[z.size()-1]].se);
        reverse(z.begin(),z.end());
        cout << "YES\n";
        for (int i = 0; i < z.size(); i++) cout << z[i] << " ";
        cout << "\n";
        exit(0);
    }
    cout << "NO\n";
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