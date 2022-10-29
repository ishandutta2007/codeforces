#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
/*
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-avx2")
*/
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>
#define ld long double
#define pld pair<ld,ld>
#define pii pair<int,int>
#define all(v) v.begin(),v.end()

using namespace std;
//using namespace __gnu_pbds;

const ll MOD=998244353;
ll md1=MOD, md2=998244353, p1=621983, p2=751921;

mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

//using ord_set=tree<T,null_type,less<T>,,tree_order_statistics_node_update>;

ll n, m, k, l, r, ans, a[400001];
ll dp[501][501], b[501];

ll binpow(ll h,ll r)
{
    ll l=1;
    while (r)
    {
        if (r%2) l=(l*h)%MOD;
        h=(h*h)%MOD;
        h%=MOD;
        r/=2;
    }
    return l;
}

ll gcd(int x,int y)
{
    if (x==0 || y==0) return x+y; else return __gcd(x,y);
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i][i]=a[i];

    for (int u = 2; u <= n; u++)
        for (int i = 1; i <= n-u+1; i++)
            for (int j = i; j < i+u-1; j++)
                if (dp[i][j] && dp[i][j]==dp[j+1][i+u-1])
                {
                    dp[i][i+u-1]=dp[i][j]+1;
                }

    for (int i = 1; i <= n; i++)
    {
        b[i]=1e9;
        for (int j = 1; j <= i; j++)
            if (dp[j][i]!=0)
            {
                b[i]=min(b[i],b[j-1]+1);
            }
    }
    cout << b[n];
    //cout << dp[3][4].size() << "\n";

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
6 7
1 2
1 3
4 5
4 6
1 4
2 5
3 6

6 9
1 2
2 3
3 1
4 5
4 6
6 5
1 4
2 5
3 6
*/