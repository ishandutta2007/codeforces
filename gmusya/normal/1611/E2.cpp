#pragma GCC optimize("O3")

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int timer = 0;

void DFS(int v, vector<int>& tin, vector<int>& par, vector<int>& dep, vector<vector<int>>& g, int p = -1) {
    tin[v] = timer++;
    for (int u : g[v]) {
        if (u != p) {
            par[u] = v;
            dep[u] = dep[v] + 1;
            DFS(u, tin, par, dep, g, v);
        }
    }
}

int LCA(int u, int v, vector<int>& dep, vector<int>& lg, vector<vector<int>>& bin_up) {
    int n = (int) dep.size();
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    for (int p = 0; p <= lg[n]; ++p) {
        if ((1 << p) & (dep[u] - dep[v])) {
            u = bin_up[p][u];
        }
    }
    if (u == v) {
        return u;
    }
    for (int p = lg[n]; p >= 0; --p) {
        if (bin_up[p][u] != bin_up[p][v]) {
            u = bin_up[p][u];
            v = bin_up[p][v];
        }
    }
    return bin_up[0][u];
}

int Dist(int u, int v, vector<int>& dep, vector<int>& lg, vector<vector<int>>& bin_up) {
    if (dep[u] == 0 || dep[v] == 0) {
        return dep[u] + dep[v];
    }
    int w = LCA(u, v, dep, lg, bin_up);
    return dep[u] + dep[v] - 2 * dep[w];
}

struct SegmentTree {
    int n;
    vector<int> t;

    explicit SegmentTree(int size) {
        n = size;
        t.resize(n << 2, INF);
    }

    void Upd(int v, int tl, int tr, int l, int r, int val) {
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            t[v] = min(t[v], val);
            return;
        }
        int tm = (tl + tr) / 2;
        Upd(v * 2, tl, tm, l, min(r, tm), val);
        Upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    }

    int Get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        }
        t[v * 2] = min(t[v], t[v * 2]);
        t[v * 2 + 1] = min(t[v], t[v * 2 + 1]);
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            return Get(v * 2, tl, tm, pos);
        } else {
            return Get(v * 2 + 1, tm + 1, tr, pos);
        }
    }

    void Upd(int l, int r, int val) {
        Upd(1, 0, n - 1, l, r, val);
    }

    int Get(int pos) {
        return Get(1, 0, n - 1, pos);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(k);
        for (int i = 0; i < k; ++i) {
            cin >> x[i];
            --x[i];
        }
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> tin(n), par(n), dep(n);
        DFS(0, tin, par, dep, g);
        vector<int> lg(n + 1);
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i / 2] + 1;
        }
        vector<vector<int>> bin_up(lg[n] + 1, vector<int>(n));
        for (int v = 0; v < n; ++v) {
            bin_up[0][v] = par[v];
        }
        for (int p = 1; p <= lg[n]; ++p) {
            for (int v = 0; v < n; ++v) {
                bin_up[p][v] = bin_up[p - 1][bin_up[p - 1][v]];
            }
        }
        vector<int> leaves;
        for (int v = 1; v < n; ++v) {
            if (g[v].size() == 1) {
                leaves.push_back(v);
            }
        }
        sort(leaves.begin(), leaves.end(), [&](int i, int j) {
            return tin[i] < tin[j];
        });
        vector<int> times;
        times.reserve(leaves.size());
        for (int v : leaves) {
            times.push_back(tin[v]);
        }
        vector<pair<int, int>> segments;
        for (int v : x) {
            int b_left, b_right;
            {
                int L = 0;
                int R = (int) (lower_bound(times.begin(), times.end(), tin[v]) - times.begin());
                while (R >= leaves.size()) {
                    --R;
                }
                if (R == -1) {
                    ++R;
                }
                while (L < R) {
                    int M = (L + R) / 2;
                    int f1 = Dist(v, leaves[M], dep, lg, bin_up);
                    int f2 = Dist(0, leaves[M], dep, lg, bin_up);
                    if (f1 <= f2) {
                        R = M;
                    } else {
                        L = M + 1;
                    }
                }
                int f1 = Dist(v, leaves[L], dep, lg, bin_up);
                int f2 = Dist(0, leaves[L], dep, lg, bin_up);
                if (f1 > f2) {
                    ++L;
                }
                b_left = L;
            }
            {
                int L = (int) (lower_bound(times.begin(), times.end(), tin[v]) - times.begin());
                if (L == leaves.size()) {
                    --L;
                }
                if (L < 0) {
                    ++L;
                }
                int R = (int) leaves.size() - 1;
                while (L < R) {
                    int M = (L + R + 1) / 2;
                    int f1 = Dist(v, leaves[M], dep, lg, bin_up);
                    int f2 = Dist(0, leaves[M], dep, lg, bin_up);
                    if (f1 <= f2) {
                        L = M;
                    } else {
                        R = M - 1;
                    }
                }
                int f1 = Dist(v, leaves[L], dep, lg, bin_up);
                int f2 = Dist(0, leaves[L], dep, lg, bin_up);
                if (f1 > f2) {
                    --R;
                }
                b_right = R;
            }
            // cout << v + 1 << ' ' << b_left + 1 << ' ' << b_right + 1 << endl;
            segments.emplace_back(b_left, b_right);
        }
        sort(segments.begin(), segments.end());
        int sz = (int) leaves.size();
        SegmentTree segment_tree(sz + 1);
        segment_tree.Upd(0, 0, 0);
        for (auto& now : segments) {
            int l = now.first + 1, r = now.second + 1;
            // cout << l << ' ' << r << endl;
            int val = segment_tree.Get(l - 1);
            segment_tree.Upd(l, r, val + 1);
        }
        int res = segment_tree.Get(sz);
        if (res == INF) {
            res = -1;
        }
        cout << res << '\n';
    }
    return 0;
}

/*
1
15 14
2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
6 13
7 14
7 15

 */