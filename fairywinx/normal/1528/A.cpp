#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <numeric>
#include <vector>
#include <array>

#define all(a) a.begin(), a.end()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

const int N = 1e5 + 228;
vector<int> G[N];
pair<int, int> val[N];

pair<long long, long long> dfs(int v, int p) {
    pair<long long, long long> dp = {0, 0};
    for (int i : G[v]) {
        if (i == p)
            continue;
        auto z = dfs(i, v);
        dp.first += max(abs(val[i].first - val[v].first) + z.first, abs(val[i].second - val[v].first) + z.second);
        dp.second += max(abs(val[i].first - val[v].second) + z.first, abs(val[i].second - val[v].second) + z.second);
    }
    return dp;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> val[i].first >> val[i].second;
        G[i].clear();
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    auto z = dfs(0, 0);
    cout << max(z.first, z.second) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}