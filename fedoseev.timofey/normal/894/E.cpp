#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 7;

vector <vector <int>> g(N);
vector <vector <int>> gr(N);
vector <vector <pair <int, int>>> gw(N);
vector <vector <int>> g2(N);
vector <vector <pair <int, int>>> g2r(N);

vector <int> tpsort;
vector <bool> used(N);
vector <int> color(N, -1);
vector <long long> cost(N);
vector <long long> dp(N, -1);

int n;

void dfs1(int u) {
    used[u] = true;
    for (auto v : g[u]) {
        if (used[v]) continue;
        dfs1(v);
    }
    tpsort.push_back(u);
}

void dfs2(int u, int col) {
    color[u] = col;
    for (auto v : gr[u])
        if (color[v] == -1)
            dfs2(v, col);
}

void dfs3(int u) {
    used[u] = true;
    for (auto v : g2[u])
        if (!used[v])
            dfs3(v);
    tpsort.push_back(u);
}

long long t(long long k) {
    return (k * (k + 1)) / 2;
}

long long s(long long k) {
    return (k * (k + 1) * (k + 2)) / 6;
}

long long f(long long w) {
    long long l = 0;
    long long r = 1e5;
    while (r - l > 1) {
        long long m = (r + l) >> 1;
        if (t(m) <= w) l = m;
        else r = m;
    }
    return w * (l + 1) - s(l);
}
template <typename T>
void db(const T &a) {
    cout << '#';
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].push_back(v);
        gr[v].push_back(u);
        gw[u].push_back({v, w});
    }
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign(N, false);
    reverse(tpsort.begin(), tpsort.end());
    // db(tpsort);
    int col = 0;
    for (auto u : tpsort) {
        if (color[u] == -1) {
            dfs2(u, col);
            ++col;
        }
    }
    // db(color);
    for (int u = 0; u < n; ++u) {
        for (auto pr : gw[u]) {
            if (color[u] != color[pr.first]) {
                g2[color[u]].push_back(color[pr.first]);
                g2r[color[pr.first]].push_back({color[u], pr.second});
            }
            else {
                cost[color[u]] += f(pr.second);
            }
        }
    }
    tpsort.clear();
    int s;
    cin >> s;
    --s;
    s = color[s];
    dfs3(s);
    dp[s] = cost[s];
    // cout << dp[s] << endl;
    reverse(tpsort.begin(), tpsort.end());
    for (auto u : tpsort) {
        dp[u] = cost[u];
        for (auto pr : g2r[u])
            if (dp[pr.first] != -1)
                dp[u] = max(dp[u], dp[pr.first] + pr.second + cost[u]);
    }
    long long ans = -1;
    for (int i = 0; i < n; ++i) ans = max(ans, dp[i]);
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}