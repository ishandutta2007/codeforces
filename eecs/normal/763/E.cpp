#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, q, ans[maxn];
int L[maxn][5], R[maxn][5], cntl[maxn], cntr[maxn], fa[maxn];
bool G[maxn][6];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %*d %d", &n, &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        G[u][v - u] = 1;
    }
    scanf("%d", &q);
    vector<tuple<int, int, int>> Q;
    for (int i = 1, l, r; i <= q; i++) {
        scanf("%d %d", &l, &r);
        if (l == r) ans[i] = 1;
        else Q.emplace_back(l, r, i);
    }
    function<void(int, int, vector<tuple<int, int, int>>)> solve =
        [&](int l, int r, vector<tuple<int, int, int>> Q) {
        if (Q.empty()) return;
        int mid = (l + r) >> 1;
        cntl[mid + 1] = cntr[mid] = 0;
        for (int i = mid; i >= l; i--) {
            fa[i] = i, cntl[i] = cntl[i + 1] + 1;
            for (int j = i + 1; j <= mid && j <= i + 5; j++) if (G[i][j - i]) {
                int u = find(i), v = find(j);
                if (u > v) swap(u, v);
                if (u ^ v) fa[u] = v, cntl[i]--;
            }
            for (int j = 0; j < 5; j++) {
                if (mid - j >= i) L[i][j] = find(mid - j);
                else L[i][j] = 0;
            }
        }
        for (int i = mid + 1; i <= r; i++) {
            fa[i] = i, cntr[i] = cntr[i - 1] + 1;
            for (int j = i - 1; j > mid && j >= i - 5; j--) if (G[j][i - j]) {
                int u = find(i), v = find(j);
                if (u < v) swap(u, v);
                if (u ^ v) fa[u] = v, cntr[i]--;
            }
            for (int j = 0; j < 5; j++) {
                if (mid + j + 1 <= i) R[i][j] = find(mid + j + 1);
                else R[i][j] = 0;
            }
        }
        vector<tuple<int, int, int>> Q1, Q2;
        for (auto p : Q) {
            int l = get<0>(p), r = get<1>(p);
            if (l <= mid && r > mid) {
                ans[get<2>(p)] = cntl[l] + cntr[r] - 10;
                iota(fa + 1, fa + 11, 1);
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; i + j < 5; j++) {
                        if (L[l][i] && R[r][j] && G[mid - i][i + j + 1]) {
                            fa[find(mid - L[l][i] + 1)] = find(R[r][j] - mid + 5);
                        }
                    }
                }
                for (int i = 1; i <= 10; i++) {
                    if (i == find(i)) ans[get<2>(p)]++;
                }
            } else if (r <= mid) {
                Q1.push_back(p);
            } else {
                Q2.push_back(p);
            }
        }
        solve(l, mid, Q1), solve(mid + 1, r, Q2);
    };
    solve(1, n, Q);
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}