#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first

using namespace std;

ll n, m, k, l, r, i, j, a[1000001], d[10000001], ans[1000001];
bool tt[1000001];
vector <vector<ll> > dp;
string s[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector <vector<ll> > dp(n+1, vector<ll>(m+1, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for (int j = 1; j <= m; j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+
            (s[i][j-1]=='X');
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }
    ll l=0, r=(min(n,m)-1)/2;
    while (l<r)
    {
        ll w=(l+r+1)/2;
        //cout << w << "\n";
        vector <vector<ll> > tt(n+1, vector<ll>(m+1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (i>w && j>w && i<=n-w && j<=m-w && dp[i+w][j+w]-dp[i+w][j-w-1]-dp[i-w-1][j+w]+dp[i-w-1][j-w-1]==(w*2+1)*(w*2+1)) {tt[i][j]=1;}
                tt[i][j]+=tt[i][j-1]+tt[i-1][j]-tt[i-1][j-1];
            }
        bool t=1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                //cout << tt[i][j] << " ";
                bool o=tt[min(i+w,n)][min(j+w,m)]-
                        tt[min(i+w,n)][max(j-w-1,0ll)]-
                        tt[max(i-w-1,0ll)][min(j+w,m)]+
                        tt[max(i-w-1,0ll)][max(j-w-1,0ll)];
                if (s[i][j-1]=='X' && o==0) {t=0;}
            }
            //cout << "\n";
        }
        if (t) l=w; else r=w-1;
    }
    cout << l << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            {
                if (i>l && j>l && i<=n-l && j<=m-l && dp[i+l][j+l]-dp[i+l][j-l-1]-dp[i-l-1][j+l]+dp[i-l-1][j-l-1]==(l*2+1)*(l*2+1)) cout << "X"; else cout << ".";
            }
        cout << "\n";
    }
    return 0;
}