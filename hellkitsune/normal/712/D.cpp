#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int d[420000] = {};
int sum[420001];
const int OFF = 210000;
const int MOD = 1e9 + 7;
int a, b, k, t;

int main() {
    scanf("%d%d%d%d", &a, &b, &k, &t);
    int from, to;
    from = to = OFF + a - b;
    d[from] = 1;
    forn(times, 2 * t) {
        from -= k;
        to += k;
        sum[from - k] = 0;
        for (int i = from - k; i <= to + k; ++i) {
            sum[i + 1] = sum[i] + d[i];
            if (sum[i + 1] >= MOD) {
                sum[i + 1] -= MOD;
            }
        }
        for (int i = from; i <= to; ++i) {
            d[i] = sum[i + k + 1] - sum[i - k];
            if (d[i] < 0) {
                d[i] += MOD;
            }
        }
    }
    int ans = 0;
    for (int i = OFF + 1; i <= to; ++i) {
        ans += d[i];
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}