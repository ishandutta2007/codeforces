#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n, x[300000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", x + i);
    sort(x, x + n);
    int ans = 0;
    int mul = 1;
    forn(i, n) {
        ans = (ans + (LL)mul * x[i]) % MOD;
        mul = 2 * mul % MOD;
    }
    reverse(x, x + n);
    mul = 1;
    forn(i, n) {
        ans = (ans - (LL)mul * x[i]) % MOD;
        mul = 2 * mul % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}