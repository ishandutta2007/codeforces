#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n, m, cnt;
int a[1000010], b[1000010];
int tmp[2000010];
int c[8000010], tag[8000010];
inline void up2(int x) {
    c[x] = min(c[x << 1], c[x << 1 | 1]) + tag[x];
}
inline void down(int x) {
    if (tag[x] == 0) return;
    tag[x << 1] += tag[x];
    tag[x << 1 | 1] += tag[x];
    c[x << 1] += tag[x];
    c[x << 1 | 1] += tag[x];
    tag[x] = 0;
}
void build(int x, int l, int r) {
    tag[x] = 0;
    c[x] = l;
    if (l == r) return;
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
}
inline void add(int x) {
    for (; x <= cnt; x += x & -x) c[x]++;
}
inline int query(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
}
inline ll calca() {
    for (int i = 1; i <= cnt; i++) c[i] = 0;
    ll ans = 0;
    for (int i = n; i > 0; i--) {
        add(a[i]);
        ans += query(a[i] - 1);
    }
    return ans;
}
int pos[1000010];
void add(int x, int l, int r, int L, int R, int v) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) {
        tag[x] += v, c[x] += v;
        return;
    }
    int mid = l + r >> 1;
    add(x << 1, l, mid, L, R, v);
    add(x << 1 | 1, mid + 1, r, L, R, v);
    up2(x);
}
inline ll calc() {
    build(1, 0, n);
    for (int i = 1; i <= n; i++) pos[i] = i;
    sort(pos + 1, pos + 1 + n, [](int x, int y) {
        return a[x] < a[y];
    });
    ll ans = 0;
    for (int i = 1, j = 1, k = 1; i <= m; i++) {
        while (j <= n && a[pos[j]] < b[i]) {
            add(1, 0, n, 0, pos[j] - 1, 1);
            j++;
        }
        while (k <= n && a[pos[k]] <= b[i]) {
            add(1, 0, n, pos[k], n, -1);
            k++;
        }
        ans += c[1];
        // cerr << i << ' ' << j << ' ' << k << ' ' << c[1] << endl;
    }
    return ans;
}
inline void rmain() {
    scanf("%d%d", &n, &m);
    cnt = 0;
    for (int i = 1; i <= n; i++) scanf("%d", a + i), tmp[++cnt] = a[i];
    for (int i = 1; i <= m; i++) scanf("%d", b + i);
    sort(b + 1, b + 1 + m);
    ll ans = calc();
    sort(tmp + 1, tmp + 1 + cnt);
    cnt = unique(tmp + 1, tmp + 1 + cnt) - tmp - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(tmp + 1, tmp + 1 + cnt, a[i]) - tmp;
    ans += calca();
    printf("%lld\n", ans);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}