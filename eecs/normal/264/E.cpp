#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, a[maxn], b[maxn], rt[maxn], f[maxn];
set<int> S;

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
struct {
    int mx[maxn << 2];

    void upd(int k, int l, int r, int p, int v) {
        if (l == r) { mx[k] = v; return; }
        mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
        mx[k] = max(mx[ls], mx[rs]);
    }
    int query(int k, int l, int r, int p) {
        if (l == r) return mx[k];
        return mid < p ? query(rs, mid + 1, r, p) : max(query(ls, l, mid, p), mx[rs]);
    }
} T1, T2;

int main() {
    scanf("%d %d", &n, &m);
    int U = max(n, m) + 10;
    for (int i = 1, op, x, y; i <= m; i++) {
        scanf("%d %d", &op, &x);
        if (op == 1) {
            scanf("%d", &y), y += m - i;
            a[x] = y, b[y] = x, S.insert(x);
            vector<int> st;
            for (int i = y - 10; i <= y; i++) if (b[i]) {
                st.push_back(i);
                if (i < y) T1.upd(1, 1, U, b[i], 0);
            }
            for (; !st.empty(); st.pop_back()) {
                int i = st.back();
                T1.upd(1, 1, U, b[i], f[b[i]] = T1.query(1, 1, U, b[i]) + 1);
                T2.upd(1, 1, U, i, f[b[i]]);
            }
        } else {
            vector<int> st;
            for (int i = 1; i <= x; i++) {
                int k = *S.begin();
                T2.upd(1, 1, U, a[k], 0), S.erase(k);
                if (i < x) st.push_back(k);
                else a[k] = b[a[k]] = 0, T1.upd(1, 1, U, k, 0);
            }
            for (; !st.empty(); st.pop_back()) {
                int i = st.back();
                T2.upd(1, 1, U, a[i], f[i] = T2.query(1, 1, U, a[i]) + 1);
                T1.upd(1, 1, U, i, f[i]), S.insert(i);
            }
        }
        printf("%d\n", T1.mx[1]);
    }
    return 0;
}