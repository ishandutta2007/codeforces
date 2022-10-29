#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const ll MOD = 998244353;

ll n, m, k, dp[200001][4], q, p, ans, l, r, i, j, x, y;
char c[4];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll q;
    c[0]='R';
    c[1]='G';
    c[2]='B';
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        cin >> s;
        ll p=0, ans=1e18;
        p=0;
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < 3; j++) dp[i][j]=1e18;
        for (int j = 0; j < 3; j++) dp[k-1][j]=0;
        for (int i = 0; i < k; i++)
        {
            if (s[i]!=c[p]) dp[k-1][0]++;
            p++;
            p%=3;
        }
        p=1;
        for (int i = 0; i < k; i++)
        {
            if (s[i]!=c[p]) dp[k-1][1]++;
            p++;
            p%=3;
        }
        p=2;
        for (int i = 0; i < k; i++)
        {
            if (s[i]!=c[p]) dp[k-1][2]++;
            p++;
            p%=3;
        }
        ans=min(dp[k-1][0],min(dp[k-1][1],dp[k-1][2]));

        for (int i = k; i < s.size(); i++)
            for (int j = 0; j < 3; j++)
            {
                ll o=j-1, w=(j+k-1)%3;
                if (o<0) o+=3;
                dp[i][j]=dp[i-1][o]-(s[i-k]!=c[o])+(s[i]!=c[w]);
                ans=min(ans,dp[i][j]);
            }
        cout << ans << "\n";
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