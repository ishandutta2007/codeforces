#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, m;
const int MOD = 1e9 + 7;
int ans = 0;

int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int inv2 = MOD / 2 + 1;
    for (LL i = 1; i <= m; ) if (n / i != n / (i + 1)) {
        ans = (ans + n % i) % MOD;
        ++i;
    } else {
        LL j = n < i ? m : min(m, n / (n / i));
        ans = (ans + n % MOD * ((j - i + 1) % MOD) - (i + j) % MOD * ((j - i + 1) % MOD) % MOD * inv2 % MOD * (n / i % MOD)) % MOD;
        i = j + 1;
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}