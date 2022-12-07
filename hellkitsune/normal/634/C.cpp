#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int st[2][1 << 19] = {};
const int off = 1 << 18;

void stUpdate(int t, int v, int val) {
    v += off;
    st[t][v] = val;
    for (v >>= 1; v >= 1; v >>= 1) {
        st[t][v] = st[t][2 * v] + st[t][2 * v + 1];
    }
}

int stGet(int t, int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r) {
        return st[t][v];
    }
    int mid = (L + R) >> 1;
    return stGet(t, 2 * v, L, mid, l, min(r, mid)) +
        stGet(t, 2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

int n, k, a, b, q;

int main() {
    scanf("%d%d%d%d%d", &n, &k, &a, &b, &q);
    REP(qq, q) {
        int qt, x, y;
        scanf("%d", &qt);
        if (qt == 1) {
            scanf("%d%d", &x, &y), --x;
            stUpdate(0, x, min(st[0][off + x] + y, b));
            stUpdate(1, x, min(st[1][off + x] + y, a));
        } else {
            scanf("%d", &x), --x;
            int ans = stGet(0, 1, 0, off - 1, 0, x - 1);
            ans += stGet(1, 1, 0, off - 1, x + k, n - 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}