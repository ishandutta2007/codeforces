#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 103;

vector <pair<int, char>> g[N];

int dp[26][N][N];

int get(int u, int v, int c = 0) {
    int &cur = dp[c][u][v];
    if (cur == -1) {
        cur = 0;
        for (auto &p : g[u]) {
            int nv = p.first;
            int nc = p.second - 'a';
            if (nc >= c && !get(v, nv, nc)) {
                return cur = 1;
            }
        }
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u, --v;
        g[u].push_back(make_pair(v, c));
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int c = 0; c < 26; ++c) {
                dp[c][i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (get(i, j)) {
                cout << 'A';
            }
            else {
                cout << 'B';
            }
        }
        cout << endl;
    }
}