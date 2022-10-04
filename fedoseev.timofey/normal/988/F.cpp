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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, n, m;
    cin >> a >> n >> m;
    vector <pair <int, int>> y(m);
    vector <int> bad;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        for (int j = u + 1; j <= v; ++j) {
            bad.push_back(j);
        }
    }
    sort(bad.begin(), bad.end());
    bad.resize(unique(bad.begin(), bad.end()) - bad.begin());
    for (int i = 0; i < m; ++i) {
        cin >> y[i].first >> y[i].second;
    }
    sort(y.begin(), y.end());
    y.push_back({a + 1, 0});
    ++m;
    if (y[0].first >= *bad.begin()) {
        cout << -1 << '\n';
        return 0;
    }
    vector <int> dp(m, 1e9);
    dp[0] = 0;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            int x = y[j].first;
            int p = y[j].second;
            auto it = upper_bound(bad.begin(), bad.end(), y[i].first);
            if (it == bad.begin()) {
                dp[i] = min(dp[i], dp[j]);
            }
            else {
                --it;
                int last = *it;
                dp[i] = min(dp[i], dp[j] + max(0, last - x) * p);
            }
        }
    }
    cout << dp[m - 1] << '\n';
}