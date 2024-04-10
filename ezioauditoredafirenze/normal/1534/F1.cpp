#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define SZ(x)(int((x).size()))
#define ALL(x)(x).begin(), (x).end()

template <typename T> inline bool chkmin(T & a,
    const T & b) {
    return b < a ? a = b, 1 : 0;
}
template <typename T> inline bool chkmax(T & a,
    const T & b) {
    return a < b ? a = b, 1 : 0;
}

typedef long long LL;

const LL infinity = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;
const int M = 4e5 + 5;

vector <vector<int>> g(M);
vector <int> topo;
bool seen[M];

void _search(int node) {
    seen[node] = true;
    for (int i = 0; i < SZ(g[node]); i++) {
        if (!seen[g[node][i]]) {
            _search(g[node][i]);
        }
    }
}

void search(int node) {
    seen[node] = true;
    for (int i = 0; i < SZ(g[node]); i++) {
        if (!seen[g[node][i]]) {
            search(g[node][i]);
        }
    }
    topo.pb(node);
}

void solve() {
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    int grid[n][m];
    int down[n][m];
    memset(grid, -1, sizeof(grid));
    memset(down, -1, sizeof(down));
    int val = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == '#') {
                grid[i][j] = val;
                val += 1;
            }
        }
    }
    int N = val;
    vector <int> z(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; j++) {
            if (i + 1 < n) {
                down[i][j] = down[i + 1][j];
            }
            if (mat[i][j] == '#') {
                down[i][j] = grid[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != -1) {
                if (i > 0 && grid[i - 1][j] != -1) {
                    g[grid[i][j]].pb(grid[i - 1][j]);
                }
                if (j + 1 < m && down[i][j + 1] != -1) {
                    g[grid[i][j]].pb(down[i][j + 1]);
                }
                if (j > 0 && down[i][j - 1] != -1) {
                    g[grid[i][j]].pb(down[i][j - 1]);
                }
                if (i + 1 < n && down[i + 1][j] != -1) {
                    g[grid[i][j]].pb(down[i + 1][j]);
                }
            }
        }
    }
    memset(seen, false, sizeof(seen));
    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            search(i);
        }
    }
    memset(seen, false, sizeof(seen));
    reverse(ALL(topo));
    int result = 0;
    for (int j = 0; j < SZ(topo); j++) {
        if (!seen[topo[j]]) {
            _search(topo[j]);
            result += 1;
        }
    }
    cout << result;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}