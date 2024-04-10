#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 1007;

vector <int> g[N];

vector <int> cmp;
int cmpnum = 0;

void dfs(int u) {
    cmp[u] = cmpnum;
    for (auto v : g[u]) {
        if (cmp[v] == -1) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m, W;
    cin >> n >> m >> W;
    vector <int> w(n), b(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cmp.resize(n, -1);
    for (int i = 0; i < n; ++i)  {
        if (cmp[i] == -1) {
            dfs(i);
            ++cmpnum;
        }
    }
    vector <vector <int>> girls(cmpnum);
    vector <pair <int, int>> a(cmpnum);
    for (int i = 0; i < n; ++i) {
        girls[cmp[i]].push_back(i);
        a[cmp[i]].first += w[i];
        a[cmp[i]].second += b[i];
    }
    vector <vector <int>> dp(cmpnum + 1, vector <int>(W + 1, 0));
    for (int i = 0; i < cmpnum; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i + 1][j] = dp[i][j];
            for (auto girl : girls[i]) {
                if (j >= w[girl]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - w[girl]] + b[girl]);
                }
            }
            if (j >= a[i].first) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - a[i].first] + a[i].second);
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= W; ++j) {
        ans = max(ans, dp[cmpnum][j]);
    }
    cout << ans << '\n';
}