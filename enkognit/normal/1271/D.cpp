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

ll md1=1e9+7, md2=998244357, p1=31, p2=127;

ll n, m, k, f, l, r, i, j, a[100001], b[100001], c[100001];
vector <ll> v[10001], w[10001];
bool tt[1000001];
ll dp[5002][5002];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h;
        h*=h;
        r/=2;
    }
    return l;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> a[i] >> b[i] >> c[i];
    }
    vector <ll> z;
    z.pb(0);
    for (int i = 1; i <= n; i++)
    {
        if (k<a[i]) {cout << -1;exit(0);}
        z.pb(k-a[i]);
        k+=b[i];
    }
    for (int i = n-1; i > 0; i--) z[i]=min(z[i],z[i+1]);
    //cout << "\n";
    z.pb(1e18);
    //for (int i = 0; i < z.size(); i++) cout << z[i] << " ";
    //cout << "\n";
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++)
        if (v[i].size())
        {
            sort(v[i].begin(),v[i].end());
            reverse(v[i].begin(),v[i].end());
            w[v[i][0]].pb(c[i]);
            //cout << v[i][0] << "\n";
        }else w[i].pb(c[i]);
    for (int i = 1; i <= n; i++)
    {
        sort(w[i].begin(),w[i].end());
        reverse(w[i].begin(),w[i].end());
    }

    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++) dp[i][j]=-1e18;
    dp[1][0]=0;
    for (ll i = 1; i <= n; i++)
        for (ll j = 0; j <= min(i+1,z[i+1]); j++)
            if (dp[i][j]!=-1e18)
            {
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
                ll p=0;
                for (int u = 0; u < w[i].size(); u++)
                {
                    p+=w[i][u];
                    if (j+u+1<=z[i+1])
                    dp[i+1][j+u+1]=max(dp[i][j]+p,dp[i+1][j+u+1]);
                }
            }
    //cout << w[n].size() << "\n";
    ll ans=0;
    /*for (int i = 1 ;i <= n+1; i++)
    {
        cout << i << ": ";
        for (int j = 0; j <= n; j++) {if (dp[i][j]==-1e18) dp[i][j]=-1;cout << dp[i][j] << " ";}
        cout << "\n";
    }*/
    for (int i = 0; i <= n; i++)  ans=max(ans,dp[n+1][i]);
    cout << ans;
    return 0;
}
/*

*/