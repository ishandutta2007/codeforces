#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=998244353;

ll n, m, w, l, r, T, k, sum, dp[1005][55][55];
string s, d, q;
ll to[2][1001][101];

void build(string g, bool p)
{
    ll m=g.size()-1;
    for (int i = 1; i <= m; i++)
        for (char c = 'a'; c <= 'z'; c++)
            for (int j = 1; j <= i; j++)
                if (g[j]==c)
                {
                    //if (c=='c' && i==1) {cout << "1\n";}
                    bool tt=1;
                    for (int w = i-j+2, u = 1; w <= i, u < j; w++, u++)
                        if (g[u]!=g[w]) tt=0;
                    if (tt) to[p][i][c-'a']=max(to[p][i][c-'a'], (ll)j);
                }
}

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> q;
    cin >> s;
    cin >> d;
    ll n=q.size();
    for (int i = 0; i <= n+1; i++)
        for (int j = 0; j <= s.size()+1; j++)
            for (int u = 0; u <= d.size()+1; u++)
            {
                dp[i][j][u]=-1e18;
            }

    s=' '+s;
    d=' '+d;

    build(s, 0);
    build(d, 1);

    dp[1][1][1]=0;
    q=' '+q;
    //cout << to[0][2][0];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < s.size(); j++)
            for (int u = 1; u < d.size(); u++)
            {
                for (char c = 'a'; c <= 'z'; c++)
                    if (q[i]=='*' || q[i]==c)
                {
                    ll l=j, r=u, p=0;

                    if (c==s[l])
                    {
                        l++;
                    }else
                        l=to[0][l-1][c-'a']+1;

                    if (c==d[r])
                    {
                        r++;
                    }else
                        r=to[1][r-1][c-'a']+1;

                    if (l==s.size())
                    {
                        p++;
                        l=to[0][l-2][c-'a']+1;
                    }

                    if (r==d.size())
                    {
                        p--;
                        r=to[1][r-2][c-'a']+1;
                    }

                    dp[i+1][l][r]=max(dp[i+1][l][r], dp[i][j][u] + p);
                }
            }

    ll ans=-1e18;
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < d.size(); j++)
            ans=max(ans, dp[n+1][i][j]);
    cout << ans;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/