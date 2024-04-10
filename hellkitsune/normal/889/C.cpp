#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, k;
int a[1000005];
int inv[1000005];

int main() {
    cin >> n >> k;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inv[i] = (MOD - LL(MOD / i) * inv[MOD % i] % MOD) % MOD;
    }
    a[1] = 1;
    int mul = 1;
    for (int i = 2; i <= n; ++i) {
        a[i] = (LL)i * a[i - 1] % MOD;
        if (i == k + 2) {
            forn(j, k) {
                mul = (LL)mul * (i - 2 - j) % MOD;
            }
        } else if (i > k + 2) {
            mul = (LL)mul * (i - 2) % MOD;
            mul = (LL)mul * inv[i - 2 - k] % MOD;
        }
        if (i >= k + 2) {
            a[i] = (a[i] - (LL)mul * a[i - k - 1]) % MOD;
            if (a[i] < 0) {
                a[i] += MOD;
            }
        }
    }
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans = (LL)ans * i % MOD;
    }
    ans -= a[n];
    if (ans < 0) {
        ans += MOD;
    }
    cout << ans << endl;
    return 0;
}