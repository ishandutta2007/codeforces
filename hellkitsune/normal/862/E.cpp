#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const LL INF64 = LL(1e18);

int n, m, q;
int a[100005], b[100005];
set<LL> se;

int main() {
    scanf("%d%d%d", &n, &m, &q);
    forn(i, n) scanf("%d", a + i);
    forn(i, m) scanf("%d", b + i);
    LL off = 0;
    int sgn = 1;
    forn(i, n) {
        off += sgn * a[i];
        sgn *= -1;
    }
    LL cur = 0;
    sgn = -1;
    forn(i, n) {
        cur += sgn * b[i];
        sgn *= -1;
    }
    se.insert(cur);
    sgn *= -1;
    for (int i = n; i < m; ++i) {
        cur += b[i - n];
        cur *= -1;
        cur += sgn * b[i];
        se.insert(cur);
    }
    forn(i, q + 1) {
        if (i != 0) {
            int from, to, x;
            scanf("%d%d%d", &from, &to, &x);
            if ((to - from) % 2 == 0) {
                if (from % 2 == 1) {
                    off += x;
                } else {
                    off -= x;
                }
            }
        }
        auto it = se.lower_bound(-off);
        LL ans = INF64;
        if (it != se.end()) {
            ans = min(ans, abs(off + *it));
        }
        if (it != se.begin()) {
            --it;
            ans = min(ans, abs(off + *it));
        }
        printf("%I64d\n", ans);
    }
    return 0;
}