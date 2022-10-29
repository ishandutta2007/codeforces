#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

const ll MOD=998244353;

ll n, m, k, T, mx, ans, a[1000001], dp[1000001];

void solve()
{
    cin >> n;
    dp[1]=1;
    ll sm=1;
    for (int i = 2; i <= n; i++)
    {
        dp[i]=(sm+a[i])%MOD;
        sm=(sm+dp[i])%MOD;
    }
    cout << dp[n] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t=1;
    for (int i = 1; i <= 1e6; i++)
        for (int j = i; j <= 1e6; j+=i) a[j]++;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
4 5
1 2 3 4
1 2
2 3
3 4
4 1
1 3
5
1 1
3 2
4 1
1 4
2 3
*/