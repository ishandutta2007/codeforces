#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int n;
vector<bool> used;
vvi g, _g;

void dfs(int v, vi& ord, vvi& g) {
    used[v] = true;
    for (int u : g[v])
        if (!used[u])
            dfs(u, ord, g);
    ord.push_back(v);
}

int GetParity(int x) {
    int res = 0;
    for (int n = 1, p = 0; p <= 30; ++p, n *= 2) {
        if (x & n) {
            ++res;
        }
    }
    return res;
}

void AddEdge(int i1, int e1, int i2, int e2) {// [i1, e1, i2, e2] = [0, 1, 3, 0] <=> (x[0] | !x[3])
    int u1 = i1, u2 = i1 + n;
    int v1 = i2, v2 = i2 + n;
    if (e1 == 0)
        swap(u1, u2);
    if (e2 == 0)
        swap(v1, v2);
    g[u1].push_back(v2);
    g[v1].push_back(u2);
    _g[v2].push_back(u1);
    _g[u2].push_back(v1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<pair<int,int>>> G(N);
        n = N;
        g.assign(2 * n, {});
        _g.assign(2 * n, {});
        for (int I = 1; I < N; ++I) {
            int U, V, W;
            cin >> U >> V >> W;
            --U, --V;
            if (W != -1) {
                if (GetParity(W) & 1) {
                    AddEdge(U, 0, V, 0);
                    AddEdge(U, 1, V, 1);
                } else {
                    AddEdge(U, 0, V, 1);
                    AddEdge(U, 1, V, 0);
                }
            }
            G[U].push_back({W, V});
            G[V].push_back({W, U});
        }
        for (int I = 0; I < M; ++I) {
            int U, V, W;
            cin >> U >> V >> W;
            --U, --V;
            if (W) {
                AddEdge(U, 0, V, 0);
                AddEdge(U, 1, V, 1);
            } else {
                AddEdge(U, 0, V, 1);
                AddEdge(U, 1, V, 0);
            }
        }
        used.assign(2 * n, false);
        vi ord;
        for (int i = 0; i < 2 * n; i++)
            if (!used[i])
                dfs(i, ord, g);
        int cnt = 0;
        vi col(2 * n);
        used.assign(2 * n, false);
        for (int i = 2 * n - 1; i >= 0; i--) {
            int v = ord[i];
            if (used[v])
                continue;
            vi comp;
            dfs(v, comp, _g);
            for (int u : comp)
                col[u] = cnt;
            cnt++;
        }
        bool can = true;
        for (int v = 0; v < n; v++) {
            if (col[v] == col[v + n]) {
                can = false;
            }
        }
        if (can) {
            cout << "YES\n";
            vector<int> flag(n);
            for (int v = 0; v < n; ++v) {
                if (col[v] < col[v + n]) {
                    flag[v] = 1;
                }
            }
            for (int v = 0; v < n; ++v) {
                for (auto& now : G[v]) {
                    int& u = now.second;
                    int& w = now.first;
                    if (w != -1) {
                        continue;
                    }
                    w = (flag[v] ^ flag[u]);
                }
            }
            for (int v = 0; v < n; ++v) {
                for (auto& now : G[v]) {
                    int& u = now.second;
                    int& w = now.first;
                    if (u < v) {
                        cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
                    }
                }
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}