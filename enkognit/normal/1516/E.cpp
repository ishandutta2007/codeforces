#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()
#define sqr(a) ((a)*(a))
#define y1 Enkognit
#define y2 based

using namespace std;
using namespace __gnu_pbds;

mt19937_64 rnd(time(0));

const ll MOD=1e9+7;

ll n, m, k, sz, c[505][505], dd[505][505], ans[2], cc[505];

ll binpow(ll h,ll r,ll md)
{
    ll l=1;
    while (r)
    {
        if (r&1) l*=h, l%=md;
        h*=h;
        h%=md;
        r/=2;
    }
    return l;
}

ll dp[505][505];

void solve()
{
    cin >> m >> k;
    ll n=min(m,2*k);
    for (int i = 0; i <= n; i++)
    {
        c[i][0]=1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
        }
    }
    cc[0]=1;
    for (int i = 1; i <= n; i++)
        cc[i]=cc[i-1]*(m-i+1)%MOD*binpow(i,MOD-2,MOD)%MOD;
    dp[0][0]=1;
    /*for (int i = 0; i <= k; i++)
        dp[0][i]=1;*/
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
        {
            dp[i][j]=(dp[i-1][j]+(j>0?dp[i-1][j-1]*((ll)i-1)%MOD:0))%MOD;
            for (int f = 0; f <= i; f++)
            {
                if (f%2==0)
                {
                    dd[i][j]=(dd[i][j]+c[i][f]*dp[i-f][j]%MOD)%MOD;
                }else
                {
                    dd[i][j]=(dd[i][j]-c[i][f]*dp[i-f][j]%MOD);
                    if (dd[i][j]<0) dd[i][j]+=MOD;
                }
            }
            //cout << i << " " << j << " " << dp[i][j] << " " << dd[i][j] << "\n";
        }
    ans[0]=1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
            ans[i%2]=(ans[i%2]+cc[j]*dd[j][i])%MOD;
        cout << ans[i%2] << " ";
    }
    cout << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    //cin >> t;
    while (t--)
    {
        solve();
        //cout << "-\n";
    }
    return 0;
}
/*
6 6 1 12
1 2 1 1 1
2 4 1 1 1
1 3 1 1 2
3 5 1 1 2
5 4 1 1 1
5 6 1 1 1
1 5
3
5
*/