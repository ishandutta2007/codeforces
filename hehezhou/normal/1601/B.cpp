#include <bits/stdc++.h>
using namespace std;
int n, a[300010], b[300010], c[300010];
pair < int, int > qwq[1200010];
inline void build(int x, int l, int r) {
    if (l == r) {
        qwq[x] = {c[l], l};
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    qwq[x] = min(qwq[x << 1], qwq[x << 1 | 1]);
}
inline pair < int, int > query(int x, int l, int r, int L, int R) {
    if (l > R || L > r) return {0x3f3f3f3f, 0};
    if (L <= l && r <= R) return qwq[x];
    int mid = l + r >> 1;
    return min(query(x << 1, l, mid, L, R), query(x << 1 | 1, mid + 1, r, L, R));
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i);
    for (int i = 1; i <= n; i++) c[i] = i + b[i] - a[i + b[i]];
    build(1, 1, n);
    vector < int > ans;
    int cur = n, lst = n - a[n];
    while (1) {
        if (lst == 0) break;
        cur = query(1, 1, n, lst, cur).second;
        ans.push_back(cur);
        cur += b[cur];
        int tmp = cur - a[cur];
        if (tmp == lst) return puts("-1"), 0;
        lst = tmp;
    }
    ans.push_back(0);
    printf("%d\n", ans.size());
    for (auto i : ans) printf("%d ", i);
    puts("");
}