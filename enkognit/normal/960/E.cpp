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
#define y1 Enkognit

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, T, i, kl, j, x, y, ans, a[1000001], dp[200001][2];
vector<ll> c[200001];

void dfs(int h,int p=-1)
{
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            dfs(c[h][i],h);
            dp[h][1]+=dp[c[h][i]][0]+1;
            dp[h][0]+=dp[c[h][i]][1];
        }
}

void dfs2(int h,int p0,int p1,int p=-1)
{
    ll sum[2], q=0;
    sum[0]=p0;
    sum[1]=p1;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
        {
            sum[0]+=dp[c[h][i]][1];
            sum[1]+=dp[c[h][i]][0]+1;
        }
    q+=n+sum[0]-sum[1];
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
    {
        ll sm0=sum[0]-dp[c[h][i]][1], sm1=sum[1]-dp[c[h][i]][0]-1;
        q+=(dp[c[h][i]][1]-dp[c[h][i]][0]-1)*(sm0+sm1);
    }
    q+=(p0-p1)*(sum[0]+sum[1]-p0-p1);
    ans+=((q%MOD)*a[h])%MOD;
    ans%=MOD;
    if (ans<0) ans+=MOD;
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=p)
    {
        dfs2(c[h][i],sum[1]-dp[c[h][i]][0]-1,sum[0]-dp[c[h][i]][1]+1,h);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    dfs2(1,0,0);
    if (ans<0) ans+=MOD;
    ans%=MOD;
    cout << ans << "\n";
    return 0;
}
/*
6 4
1 2
6 5
3 2
4 5
*/