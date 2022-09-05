#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q;
char s[maxn];

struct SEG {
#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
    int mn1[maxn << 2], mn2[maxn << 2], tag1[maxn << 2], tag2[maxn << 2], ans[maxn << 2];

    void apply(int k, int v1, int v2) {
        mn1[k] += v1, tag1[k] += v1;
        mn2[k] += v2, tag2[k] += v2;
        ans[k] += v1 + v2;
    }
    void pushdown(int k) {
        apply(ls, tag1[k], tag2[k]);
        apply(rs, tag1[k], tag2[k]), tag1[k] = tag2[k] = 0;
    }

    void add(int k, int l, int r, int ql, int qr, int v1, int v2) {
        if (l >= ql && r <= qr) { apply(k, v1, v2); return; }
        pushdown(k);
        if (mid >= ql) add(ls, l, mid, ql, qr, v1, v2);
        if (mid < qr) add(rs, mid + 1, r, ql, qr, v1, v2);
        mn1[k] = min(mn1[ls], mn1[rs]);
        mn2[k] = min(mn2[ls], mn2[rs]);
        ans[k] = min({ans[ls], ans[rs], mn1[ls] + mn2[rs]});
    }
} T;

int main() {
    scanf("%d %d %s", &n, &q, s + 1);
    int C = 0;
    auto add = [&](int i, char ch, int coef) {
        if (ch == 'a') {
            T.add(1, 0, n + 1, i, n + 1, coef, 0);
        } else if (ch == 'b') {
            T.add(1, 0, n + 1, i, n + 1, -coef, coef);
        } else {
            C += coef;
            T.add(1, 0, n + 1, i, n + 1, 0, -coef);
        }
    };
    for (int i = 1; i <= n; i++) {
        add(i, s[i], 1);
    }
    while (q--) {
        int i;
        char c[2];
        scanf("%d %s", &i, c);
        add(i, s[i], -1);
        add(i, s[i] = c[0], 1);
        printf("%d\n", T.ans[1] + C);
    }
    return 0;
}