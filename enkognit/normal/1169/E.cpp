#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>

using namespace std;

//ll n, m, i, j, k, l, r, ans, T, Q, K, a[300001], b[100001];
//string s, d;
//vector <ll> c[300001], v;

ll n, m, i, j, ans, a[400001], st[400001], ls[21], dp[400001][21];
string s;
//bool t[x][y];

int main()
{
    //ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int j = 0; j < 20; j++)
    {
        ls[j]=n;
        if (j==0) st[j]=1; else st[j]=st[j-1]*2;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 20; j++) dp[i][j]=1e18;

    //cout << "1\n";

    for (int i = n; i > 0; i--)
    {
        //cout << (a[i]&st[0]) << "\n";
        for (int j = 0; j < 20; j++)
            if ((a[i] & st[j]))
            {
                for (int u = 0; u < 20; u++)
                    dp[i][u]=min(dp[i][u], dp[ls[j]][u]);
            }

        for (int j = 0; j < 20; j++)
            if ((a[i] & st[j])) ls[j]=i, dp[i][j]=min((ll)i, dp[i][j]);
    }

    for (int i = 0; i < m; i++)
    {
        ll x, y, ans=1e18;
        cin >> x >> y;
        for (int j = 0; j < 20; j++)
            if ((st[j] & a[y])) ans=min(ans, dp[x][j]);
        if (ans<=y) cout << "Shi\n"; else cout << "Fou\n";
    }
    return 0;
}
/*
10000 10000 2
1 4232
3 1 10000 4231 10000
*/