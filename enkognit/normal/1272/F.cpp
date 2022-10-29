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
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, j, h, sum, dp[202][202][410];
pair<pii,pair<int,char> > e[202][202][410];
string s, d;

int main()
{
    //freopen("b.in","r",stdin);
    //freopen("b.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> d;
    n=s.size()+d.size();
    for (int i = 0; i <= s.size(); i++)
        for (int j = 0; j <= d.size(); j++)
            for (int u = 0; u <= n*2; u++) dp[i][j][u]=1e18;
    for (int i = 0; i < 201; i++) {dp[0][0][i]=i;e[0][0][i]=mp(mp(0,0),mp(i-1,'('));}
    for (int i = 0; i <= s.size(); i++)
        for (int j = 0; j <= d.size(); j++)
            for (int u = 0; u <= n; u++)
                if (dp[i][j][u]!=1e18)
            {
                //cout << i << " " << j << " " << u << " " << s[i] << " " << d[j] << "\n";
                ll x=i, y=j;
                if (x<s.size() && s[x]=='(' && y<d.size() && d[y]=='(')
                {
                    if (dp[x+1][y+1][u+1]>dp[x][y][u]+1)
                    {
                        //cout << x+1 << " " << y+1 << " " << u+1 << "\n";
                        dp[x+1][y+1][u+1]=min(dp[x+1][y+1][u+1], dp[x][y][u]+1);
                        e[x+1][y+1][u+1]=mp(mp(x,y),mp(u,'('));
                    }
                }
                if (x<s.size() && s[x]=='(' && (y<d.size() && d[y]==')' || y==d.size()))
                {
                    if (dp[x+1][y][u+1]>dp[x][y][u]+1)
                    {
                        dp[x+1][y][u+1]=dp[x][y][u]+1;
                        e[x+1][y][u+1]=mp(mp(x,y),mp(u,'('));
                    }
                }
                if (y<d.size() && d[y]=='(' && (x<s.size() && s[x]==')' || x==s.size()))
                {
                    if (dp[x][y+1][u+1]>dp[x][y][u]+1)
                    {
                        dp[x][y+1][u+1]=min(dp[x][y+1][u+1], dp[x][y][u]+1);
                        e[x][y+1][u+1]=mp(mp(x,y),mp(u,'('));
                    }
                }
                if (x<s.size() && s[x]==')' && y<d.size() && d[y]==')' && u>0)
                {
                    if (dp[x+1][y+1][u-1]>dp[x][y][u]+1)
                    {
                        dp[x+1][y+1][u-1]=min(dp[x+1][y+1][u-1], dp[x][y][u]+1);
                        e[x+1][y+1][u-1]=mp(mp(x,y),mp(u,')'));
                    }
                }
                if (x<s.size() && s[x]==')' && (y<d.size() && d[y]=='(' || y==d.size()) && u>0)
                {
                    if (dp[x+1][y][u-1]>dp[x][y][u]+1)
                    {
                        dp[x+1][y][u-1]=min(dp[x+1][y][u-1], dp[x][y][u]+1);
                        e[x+1][y][u-1]=mp(mp(x,y),mp(u,')'));
                    }
                }
                if (y<d.size() && d[y]==')' && (x<s.size() && s[x]=='(' || x==s.size()) && u>0)
                {
                    if (dp[x][y+1][u-1]>dp[x][y][u]+1)
                    {
                        dp[x][y+1][u-1]=min(dp[x][y+1][u-1], dp[x][y][u]+1);
                        e[x][y+1][u-1]=mp(mp(x,y),mp(u,')'));
                    }
                }
            }
    ll ans=1e18, st=0;
    for (int i = 0; i <= n; i++)
    {
        if (ans>dp[s.size()][d.size()][i]+i)
        {
            ans=dp[s.size()][d.size()][i]+i;
            st=i;
        }
    }
    //cout << ans << " " << st << " " << n << "\n";
    string w;
    ll x=s.size(), y=d.size(), o=st;
    //cout << x << "-" << y << "-" << o << "-\n";
    while (!(x==0 && y==0 && o==0))
    {
        //cout << x << "-" << y << "-" << o << "\n";
        w+=(char)e[x][y][o].se.se;
        ll x1=0, y1=0, o1=0;
        x1=e[x][y][o].fi.fi;
        y1=e[x][y][o].fi.se;
        o1=e[x][y][o].se.fi;
        x=x1, y=y1, o=o1;
    }
    reverse(w.begin(),w.end());
    cout << w;
    if (st>0) for (int i = 0; i < st; i++) cout << ")";
    return 0;
}