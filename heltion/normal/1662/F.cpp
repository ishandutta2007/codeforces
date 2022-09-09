#include <bits/stdc++.h>
using namespace std;
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
struct Tree{
    int n;
    vector<vector<pair<int, int>>> vp;
    Tree(int n) : n(n), vp(n << 2) {
    }
    void init() {
        for (auto& v : vp) ranges::sort(v);
    }
    void add(int x, int y) {
        function<void(int, int, int)> DFS = [&](int v, int tl, int tr) {
            vp[v].emplace_back(y, x);
            if (tl == tr) return;
            else {
                if (x <= tm) DFS(ls, tl, tm);
                if (x > tm) DFS(rs, tm + 1, tr);
            }
        };
        DFS(1, 1, n);
    }
    vector<int> query(int L, int R, int p) {
        vector<int> res;
        function<void(int, int, int)> DFS = [&](int v, int tl, int tr) {
            if (tl >= L and tr <= R) {
                while (not vp[v].empty() and vp[v].back().first >= p) {
                    res.push_back(vp[v].back().second);
                    vp[v].pop_back();
                }
                return;
            }
            if (L <= tm) DFS(ls, tl, tm);
            if (R > tm) DFS(rs, tm + 1, tr);
        };
        DFS(1, 1, n);
        return res;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        int a, b;
        cin >> a >> b;
        vector<int> p(n + 1);
        Tree A(n), B(n);
        for (int i = 1; i <= n; i += 1) {
            cin >> p[i];
            A.add(i, i + p[i]);
            B.add(i, -i + p[i]);
        }
        A.init();
        B.init();
        vector<int> d(n + 1, n);
        queue<int> q;
        d[a] = 0;
        q.push(a);
        while (not q.empty()) {
            int u = q.front();
            q.pop();
            if (u > 1) {
                auto L = A.query(max(1, u - p[u]), u - 1, u);
                for (int v : L)
                    if (d[v] > d[u] + 1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
            }
            if (u < n) {
                auto R = B.query(u + 1, min(n, u + p[u]), -u);
                for (int v : R)
                    if (d[v] > d[u] + 1) {
                        d[v] = d[u] + 1;
                        q.push(v);
                    }
            }
        }
        cout << d[b] << "\n";
    }
}