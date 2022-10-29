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
#define all(v) v.begin(),v.end()

using namespace std;

const ll MOD=1e9+7;

ll n, m, k, T, a[5005], b[5005], kl[5005], q;
ll dp[5005][5005];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r&1) l=(l*h)%MOD;
        h=(h*h)%MOD;
        r/=2;
    }
    return l;
}

void solve()
{
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= k; i++) b[i]=binpow(2, i);
    for (int i = 1; i <= n; i++) dp[i][0]=1;
    for (int j = 0; j < k; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i>1) dp[i-1][j+1]=(dp[i-1][j+1]+dp[i][j])%MOD;
            if (i<n) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
            kl[i]=(kl[i]+dp[i][j]*dp[i][k-j])%MOD;
    }
    ll ans=0;
    //for (int i = 1; i <= n; i++) cout << kl[i] << " ";
    //cout << "\n";
    for (int i = 1; i <= n; i++) ans=(ans+a[i]*kl[i]%MOD)%MOD;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        ans=(ans-kl[x]*a[x]%MOD);
        if (ans<0) ans+=MOD;
        a[x]=y;
        ans=(ans+kl[x]*a[x]%MOD)%MOD;
        cout << ans << "\n";
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
3 2
0 1
1 2
1 2
2 3
2 3
3 4
1 2
2 3

3 4
0 0 0 0
1 1 1 1
1 1 1 1
2 2 2 2
0 0 0 0
2 3 2 3
1 3
2 3
*/
/*

}


*/