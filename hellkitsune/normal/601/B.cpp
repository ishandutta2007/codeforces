#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
int a[100000], s[100000], lo[100000], hi[100000];

int main() {
    scanf("%d%d", &n, &q);
    REP(i, n) scanf("%d", a + i);
    --n;
    REP(i, n) a[i] = abs(a[i] - a[i + 1]);
    REP(query, q) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        int m = to - from;
        REP(i, m) s[i] = a[from + i];
        REP(i, m) {
            lo[i] = i;
            while (lo[i] > 0 && s[lo[i] - 1] <= s[i]) lo[i] = lo[lo[i] - 1];
        }
        for (int i = m - 1; i >= 0; --i) {
            hi[i] = i;
            while (hi[i] < m - 1 && s[hi[i] + 1] < s[i]) hi[i] = hi[hi[i] + 1];
        }
        LL ans = 0;
        REP(i, m) ans += (LL)(hi[i] - i + 1) * (i - lo[i] + 1) * s[i];
        printf("%I64d\n", ans);
    }
    return 0;
}