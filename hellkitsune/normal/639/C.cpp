#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[200111] = {}, bits[200111];

int main() {
    scanf("%d%d", &n, &k), ++n;
    REP(i, n) scanf("%d", a + i);
    REP(times, 2) {
        int val = 0;
        REP(i, n + 100) {
            val += a[i];
            bits[i] = abs(val % 2);
            val = (val - bits[i]) / 2;
        }
        if (val == 0) break;
        REP(i, n) a[i] *= -1;
    }
    int earliest = 0;
    while (!bits[earliest]) ++earliest;
    earliest = min(earliest, n - 1);
    LL val = 0;
    int ans = 0;
    for (int i = n + 100; i >= 0; --i) {
        val = 2 * val + bits[i];
        if (val > 2.1e9) break;
        if (i <= earliest && abs(a[i] - val) <= k && (i != n - 1 || a[i] - val != 0)) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}