#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n, st, cnt;
int l[500010], r[500010];
int tmp[1000010];
int tag[4000010];
inline void down(int x) {
    if (tag[x] == 0) return;
    tag[x << 1] += tag[x];
    tag[x << 1 | 1] += tag[x];
    tag[x] = 0;
}
void add(int x, int l, int r, int L, int R, int v) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) {
        tag[x] += v;
        return;
    }
    down(x);
    int mid = l + r >> 1;
    add(x << 1, l, mid, L, R, v);
    add(x << 1 | 1, mid + 1, r, L, R, v);
}
int query(int x, int l, int r, int k) {
    if (l == r) return tag[x];
    down(x);
    int mid = l + r >> 1;
    if (k <= mid) return query(x << 1, l, mid, k);
    return query(x << 1 | 1, mid + 1, r, k);
}
vector < int > t1[1000010], t2[1000010];
int ans[1000010];
int main() {
    scanf("%d%d", &n, &st);
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", l + i);
        tmp[++cnt] = l[i];
        scanf("%d", r + i);
        tmp[++cnt] = r[i];
    }
    tmp[++cnt] = st;
    sort(tmp + 1, tmp + 1 + cnt);
    cnt = unique(tmp + 1, tmp + 1 + cnt) - tmp - 1;
    for (int i = 1; i <= n; i++) l[i] = lower_bound(tmp + 1, tmp + 1 + cnt, l[i]) - tmp;
    for (int i = 1; i <= n; i++) r[i] = lower_bound(tmp + 1, tmp + 1 + cnt, r[i]) - tmp;
    st = lower_bound(tmp + 1, tmp + 1 + cnt, st) - tmp;
    int delta = 0;
    for (int i = 1; i <= n; i++) {
        if (l[i] < r[i]) t1[l[i]].push_back(r[i]);
        else {
            t2[r[i]].push_back(l[i]);
            if (r[i] <= st && l[i] >= st) delta++;
        }
    }
    for (int i = cnt; i > 0; i--) {
        ans[i] = i < cnt ? ans[i + 1] + query(1, 1, cnt, i + 1) : 0;
        for (auto j : t1[i]) {
            ans[i] = max(ans[i], ans[j] + query(1, 1, cnt, j) + 1);
        }
        for (auto j : t2[i]) {
            add(1, 1, cnt, i, j, 1);
        }
        if (i == st) return printf("%d\n", ans[i] + delta), 0;
    }
}