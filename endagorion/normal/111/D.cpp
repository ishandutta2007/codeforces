#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

const long long MOD = 1000000007;

long long deg(long long x, int d) {
    if (d == 0) {
        return 1;
    }

    long long res = deg(x, d / 2);
    res = (res * res) % MOD;
    if (d % 2) {
        res = (res * x) % MOD;
    }
    return res;
}

long long inverse(long long x) {
    return deg(x, MOD - 2);
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector< long long > fact(k + 1), tcaf(k + 1);
    fact[0] = tcaf[0] = 1;
    for (int i = 1; i <= k; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        tcaf[i] = inverse(fact[i]);
    }

    vector< vector< long long > > K(n + 1, vector< long long > (n + 1, 0));
    K[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            K[i][j] = (j * K[i - 1][j] + j * K[i - 1][j - 1]) % MOD;
        }
    }

    long long ans = 0;
    if (m == 1) {
        ans = deg(k, n);
    } else 
    for (int l = 1; l <= n && l <= k; ++l) {
        for (int p = 0; p <= l; ++p) {
            if (2 * l - p > k) {
                continue;
            }
            long long res = fact[k];
            res = (res * tcaf[l - p]) % MOD;
            res = (res * tcaf[l - p]) % MOD;
            res = (res * tcaf[p]) % MOD;
            res = (res * tcaf[k - (2 * l - p)]) % MOD;
            res = (res * deg(p, n * (m - 2))) % MOD;
            res = (res * K[n][l]) % MOD;
            res = (res * K[n][l]) % MOD;
            ans = (ans + res) % MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}