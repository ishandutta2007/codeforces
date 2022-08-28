#include <bits/stdc++.h>
#pragma pack(1)
using namespace std;
typedef long long ll;
int n, T[200010];
struct node {
    int ls, rs;
    int l, r, tag;
} t[200010 * 32 * 2 * 2];
int tot;
inline void down(int x, int l, int r) {
    int mid = l + r >> 1;
    if (t[x].ls == 0) t[++tot] = {0, 0, l, mid, 0}, t[x].ls = tot;
    if (t[x].rs == 0) t[++tot] = {0, 0, mid + 1, r, 0}, t[x].rs = tot;
    if (t[x].tag) {
        t[t[x].ls].tag += t[x].tag;
        t[t[x].ls].l += t[x].tag;
        t[t[x].ls].r += t[x].tag;
        t[t[x].rs].tag += t[x].tag;
        t[t[x].rs].l += t[x].tag;
        t[t[x].rs].r += t[x].tag;
        t[x].tag = 0;
    }
}
inline void up(int x) {
    t[x].l = t[t[x].ls].l;
    t[x].r = t[t[x].rs].r;
}
inline int query(int x, int l, int r, int k) {
    if (t[x].l > k) return l - 1;
    if (t[x].r <= k) return r;
    if (l == r) return l;
    int mid = l + r >> 1;
    if (t[x].ls) {
        down(x, l, r);
        return t[t[x].rs].l <= k ? query(t[x].rs, mid + 1, r, k) : query(t[x].ls, l, mid, k);
    }
    else return l + k - t[x].l;
}
inline int query_ans(int x, int l, int r, int k) {
    if (l == r) return t[x].l;
    int mid = l + r >> 1;
    if (t[x].ls) {
        down(x, l, r);
        return k <= mid ? query_ans(t[x].ls, l, mid, k) : query_ans(t[x].rs, mid + 1, r, k);
    }
    else return t[x].l + k - l;
}
inline void add(int x, int l, int r, int L, int R, int k) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) return t[x].tag += k, t[x].l += k, t[x].r += k, void();
    int mid = l + r >> 1;
    down(x, l, r);
    add(t[x].ls, l, mid, L, R, k);
    add(t[x].rs, mid + 1, r, L, R, k);
    up(x);
}
const int m = 1000000000;
int main() {
    t[tot = 1] = {0, 0, 0, m, 0};
    scanf("%d", &n);
    int lastans = 0;
    for (int i = 1; i <= n; i++) {
        int T;
        scanf("%d", &T);
        int pos1 = query(1, 0, m, T - 1), pos2 = query(1, 0, m, T) + 1;
        // cerr << pos1 << ' ' << pos2 << endl;
        add(1, 0, m, 0, pos1, 1), add(1, 0, m, pos2, m, -1);
        int k;
        scanf("%d", &k);
        while (k--) {
            int x;
            scanf("%d", &x);
            x = (x + lastans) % (m + 1);
            printf("%d\n", lastans = query_ans(1, 0, m, x));
        }
    }
}