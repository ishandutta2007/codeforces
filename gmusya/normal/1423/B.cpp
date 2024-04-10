#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>

#define ar array
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()
#define range(i, n) for (int i=0; i < n; ++i)

typedef long long ll;
using namespace std;

const int maxN = 2e4 + 10;
const int maxM = 4e5 + 10;

int n, m, start, finish, mxc;
vector<ar<int, 3>> g[maxN];
int c[maxM], f[maxM], rev[maxM], d[maxN], nxt[maxN];

bool bfs() {
    memset(d, -1, sizeof(d));
    d[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &[v, id, xc]: g[u]) {
            if (xc > mxc) continue;
            if (d[v] == -1 && f[id] < c[id]) {
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return d[finish] != -1;
}

int dfs(int v, int fl) {
    if (v == finish || !fl) return fl;
    for (int &i = nxt[v]; i < g[v].size(); ++i) {
        auto[u, id, xc] = g[v][i];
        if (xc > mxc) continue;
        if (d[u] != d[v] + 1) continue;
        int fld = dfs(u, min(fl, c[id] - f[id]));
        if (fld) {
            f[id] += fld;
            f[rev[id]] -= fld;
            return fld;
        }
    }
    return 0;
}

const int INFi = 2e9;

int find_max_flow() {
    memset(f, 0, sizeof(f));
    int res = 0;
    while (bfs()) {
        memset(nxt, 0, sizeof(nxt));
        int nfl = dfs(start, INFi);
        while (nfl) {
            res += nfl;
            nfl = dfs(start, INFi);
        }
    }
    return res;
}

void solve() {
    int N, M; cin >> N  >> M;
    range(i, M) {
        int u, v, dd; cin >> u >> v >> dd;
        u--; v--;
        v += N;
        g[u].push_back({v, i*2, dd});
        g[v].push_back({u, i*2+1, dd});
        rev[i*2] = i*2+1;
        rev[i*2+1] = i*2;
        c[i*2] = 1;
    }
    start = N * 2;
    finish = N * 2 + 1;
    int edge = M * 2;
    range(i, N) {
        g[start].push_back({i, edge, 0});
        g[i].push_back({start, edge+1, 0});
        rev[edge] = edge+1;
        c[edge] = 1;
        rev[edge+1] = edge;
        edge += 2;
    }
    for(int i = N; i < N * 2; ++i) {
        g[finish].push_back({i, edge+1, 0});
        g[i].push_back({finish, edge, 0});
        rev[edge] = edge+1;
        c[edge] = 1;
        rev[edge+1] = edge;
        edge += 2;
    }
    int l = 0, r = 1e9+1;
    while(r - l > 1) {
        int mid = (r+l) / 2;
        mxc = mid;
        if (find_max_flow() >= N) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if(r == 1e9+1) {
        cout << -1;
    } else {
        cout << r << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}