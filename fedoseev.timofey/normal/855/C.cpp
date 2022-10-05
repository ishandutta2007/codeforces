#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int N = 123456;

vector <int> g[N];

int n, m, k, x;

long long dp[3][N][11];
long long tmp[3][11];

const long long md = 1e9 + 7;

long long add(long long a, long long b) {
    return (a + b) % md;
}

void dfs(int u, int p) {
    dp[0][u][0] = k - 1;
    dp[1][u][1] = 1;
    dp[2][u][0] = m - k;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j <= x; ++j)
                tmp[i][j] = 0;
        for (int i = 0; i <= x; ++i) {
            for (int j = 0; j + i <= x; ++j) {
                tmp[0][i + j] = add(tmp[0][i + j], (dp[0][u][i] * (dp[1][v][j] + dp[0][v][j] + dp[2][v][j])));
                tmp[1][i + j] = add(tmp[1][i + j], dp[1][u][i] * dp[0][v][j]);
                tmp[2][i + j] = add(tmp[2][i + j], dp[2][u][i] * (dp[0][v][j] + dp[2][v][j]));
            }
        }
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j <= x; ++j)
                dp[i][u][j] = tmp[i][j];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k >> x;
    long long ans = 0;
    dfs(0, -1);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j <= x; ++j)
            ans = add(ans, dp[i][0][j]);
    cout << ans << endl;
}