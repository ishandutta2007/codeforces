#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

const int N = 3e5 + 7;
int n, m;
string s;

vector <int> g[N];

vector <int> tpsort;

bool is_cycle = false;

int ans = 1;

int used[N];

void dfs(int u) {
    used[u] = 1;
    for (auto v : g[u]) {
        if (used[v] == 0) dfs(v);
        else if (used[v] == 1) is_cycle = true;
    }
    used[u] = 2;
}

int dp[26][N];

void get_tpsort(int u) {
    used[u] = 1;
    for (auto v : g[u]) {
        if (!used[v]) get_tpsort(v);
    }
    tpsort.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> s;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }
    if (is_cycle) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) used[i] = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) get_tpsort(i);
    }
    reverse(tpsort.begin(), tpsort.end());
    for (int i = 0; i < n; ++i) used[i] = 0;
    for (int i = 0; i < n; ++i) {
        int u = tpsort[i];
        ++dp[s[u] - 'a'][u];
        for (auto v : g[u]) {
            for (int i = 0; i < 26; ++i) {
                dp[i][v] = max(dp[i][v], dp[i][u]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            ans = max(ans, dp[j][i]);
        }
    }
    cout << ans << endl;
}