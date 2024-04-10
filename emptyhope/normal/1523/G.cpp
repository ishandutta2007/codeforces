#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
constexpr int N = 50000, M = 100000;
int n, m;
struct Node {
    Node *lc, *rc;
    int mn;
    Node() : lc(nullptr), rc(nullptr), mn(M + 1) {}
};
Node *t[N];
void query(Node *t, int l, int r, int x, int &v) {
    if (t == nullptr || r <= x || t->mn > v) {
        return;
    }
    if (l >= x) {
        v = t->mn;
        return;
    }
    int m = (l + r) / 2;
    query(t->rc, m, r, x, v);
    query(t->lc, l, m, x, v);
}
void add(Node *&t, int l, int r, int x, int v) {
    if (t == nullptr) {
        t = new Node;
    }
    t->mn = std::min(t->mn, v);
    if (r - l == 1) {
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        add(t->lc, l, m, x, v);
    } else {
        add(t->rc, m, r, x, v);
    }
}
void add(int y, int x, int v) {
    for (int i = x + 1; i <= n; i += i & -i) {
        add(t[i - 1], 0, n, y, v);
    }
}
int query(int l, int r) {
    int v = M + 1;
    for (int i = r; i; i &= i - 1) {
        query(t[i - 1], 0, n, l, v);
    }
    return v;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    std::vector<int> l(m), r(m);
    std::vector<std::vector<int>> p(n);
    for (int i = 0; i < m; i++) {
        std::cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        p[r[i] - l[i]].push_back(i);
    }
    std::vector<int> ans(n);
    for (int x = n - 1; x >= 0; x--) {
        for (auto i : p[x]) {
            add(l[i], r[i], i);
        }
        std::function<int(int, int)> solve = [&](int L, int R) {
            if (R - L <= x) {
                return 0;
            }
            int i = query(L, R);
            if (i >= m) {
                return 0;
            }
            return r[i] - l[i] + 1 + solve(L, l[i]) + solve(r[i] + 1, R);
        };
        ans[x] = solve(0, n);
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << "\n";
    }
    return 0;
}