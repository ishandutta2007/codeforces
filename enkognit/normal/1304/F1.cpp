#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define pld pair<ld,ld>
#define OO 1000000000000000000

using namespace std;

ll n, kl, m, T, k, nm, dp[61][40001], pr[61][40001], a[61][20001];

struct segment_tree
{
    ll d[100001];

    void build(int h,int l,int r)
    {
        if (l==r) {d[h]=dp[nm][l];return;}
        int w=(l+r)/2;
        build(h*2,l,w);
        build(h*2+1,w+1,r);
        d[h]=max(d[h*2],d[h*2+1]);
    }

    ll get(int h,int l,int r,int x,int y)
    {
        if (x>y) return 0;
        if (l==x && y==r) return d[h];
        int w=(l+r)/2;
        return max(get(h*2,l,w,x,min(y,w)),get(h*2+1,w+1,r,max(x,w+1),y));
    }
};

segment_tree g[51];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) {cin >> a[i][j];pr[i][j]=pr[i][j-1]+a[i][j];}
    }
    //cout << "\n";

    for (ll i = 1; i <= n; i++)
    {
        nm=i;
        g[i].build(1,1,m-k+1);

        for (ll j = 1; j <= m-k+1; j++)
        {
            dp[i+1][j]=pr[i][min(j+k-1,m)]-pr[i][j-1]+pr[i+1][min(j+k-1,m)]-pr[i+1][j-1]+max(g[i].get(1,1,m-k+1,1,j-k),g[i].get(1,1,m-k+1,j+k,m-k+1));
            for (ll u = max(j-k+1,1ll); u <= min(j+k-1,m-k+1); u++)
            {
                ll l=max(u,j), r=min(u+k-1,j+k-1);
                dp[i+1][j]=max(dp[i+1][j],pr[i][min(j+k-1,m)]-pr[i][j-1]+pr[i+1][min(j+k-1,m)]-pr[i+1][j-1]+dp[i][u]-max(pr[i][r]-pr[i][l-1],0ll));
            }
            //cout << dp[i+1][j] << " ";
        }
       // cout << "\n";
    }
    ll ans=0;
    for (int i = 1; i <= m-k+1; i++) ans=max(ans,dp[n+1][i]);
    cout << ans << "\n";
    return 0;
}
/*
*/