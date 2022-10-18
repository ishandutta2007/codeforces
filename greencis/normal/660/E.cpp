#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll MOD = 1000000007LL;

inline ll binpow(ll x, ll deg) {
    ll res = 1LL;
    while (deg) {
        if (deg & 1LL) (res *= x) %= MOD;
        (x *= x) %= MOD;
        deg >>= 1LL;
    }
    return res;
}

int n, m;
ll sum_deg[1001005], sum[2][1001005];

int main()
{
    cin >> n >> m;
    sum[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        sum[0][i] = sum[1][i] = (sum[0][i - 1] + sum[1][i - 1]) % MOD;
        sum[1][i] = ((sum[1][i] - sum_deg[i - 1]) % MOD + MOD) % MOD;
        sum_deg[i] = (sum_deg[i - 1] * (m - 1) + sum[0][i]) % MOD;
        sum[0][i] = (sum[0][i] * m) % MOD;
        sum[1][i] = (sum[1][i] * m) % MOD;
    }

    cout << (sum[0][n] + sum[1][n]) % MOD << endl;

    return 0;
}