#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

LL n, m, k;

int binPow(LL x, LL p) {
    LL res = 1;
    while (p) {
        if (p & 1) res = res * x % MOD;
        p >>= 1;
        if (p) x = x * x % MOD;
    }
    return (int)res;
}

int main() {
    cin >> n >> m >> k;
    if (k == -1 && n % 2 != m % 2) {
        cout << 0 << endl;
        return 0;
    }
    int ans = 1;
    if (n > 1 && m > 1) {
        ans = binPow(binPow(2, n - 1), m - 1);
    }
    cout << ans << endl;
    return 0;
}