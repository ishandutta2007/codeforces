#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

ll a[300000], dp[20][300000];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    bool flag = 1;
    for (ll i = 0; i < n; i++) {
        ll x; fin >> x;
        if (x == -1) flag = 0;
        else if (flag) a[i] = 0;
        else a[i-1] = x;
    }
    fill(&dp[0][0], &dp[0][0]+sizeof(dp)/sizeof(ll), inf_ll);
    dp[__builtin_ctz(n)][n-1] = 0;
    for (ll k = __builtin_ctz(n)-1; k >= 0; k--)
        for (ll i = n-2; i >= 0; i--) {
            dp[k][i] = dp[k][i+1];
            if (i >= (1<<(k+1))-2)
                dp[k][i] = min(dp[k][i], dp[k+1][i+1]+a[i]);
        }
    // for (int k = __builtin_ctz(n); k >= 0; k--)
    //     for (int i = n-2; i >= (1<<(k+1))-2; i--)
    //         debug(k, i, dp[k][i]);
    cout << dp[0][0] << "\n";
}