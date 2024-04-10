#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("-O3")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx2")
typedef long long ll;
typedef double ld;
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

ll n, m, k, sz, a[200005], dp[1005][1005];

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

bool is(ll n)
{
    ll x=n, o=0;
    while (x)
    {
        o+=x%10;
        x/=10;
    }
    return __gcd(n, o)>1;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j]=(i==1);
    ll sm=1+(n)*(k>1);
    for (int i = 2; i < k; i++)
    {
        if (i%2)
        {
            ll pr=0;
            for (int j = 1; j <= n; j++)
            {
                dp[i][j]=pr;
                sm=(sm+dp[i][j])%MOD;
                pr=(pr+dp[i-1][j])%MOD;
            }
        }else
        {
            ll pr=0;
            for (int j = n; j > 0; j--)
            {
                dp[i][j]=pr;
                sm=(sm+dp[i][j])%MOD;
                pr=(pr+dp[i-1][j])%MOD;
            }
        }
    }
    cout << sm << "\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("capitals.in","r",stdin);
    //freopen("capitals.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    cin >> t;
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