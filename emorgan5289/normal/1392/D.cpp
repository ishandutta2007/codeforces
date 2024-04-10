#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e6;
ll dp[N][4];
vector<pair<string, int>> b = {{"LLR", 0}, {"LRR", 1}, {"LRL", 2}, {"RRL", 2}, {"RLL", 3}, {"RLR", 0}};
vector<vector<int>> g = {{0, 1}, {0, 1, 2}, {0, 1, 2}, {2, 3}, {0, 2, 3}, {0, 2, 3}};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        ll ans = inf;
        if (s.size() < 3) {
            cout << 0 << "\n"; continue;
        }
        // debug(s);
        for (int j = 0; j < 6; j++) {
            auto [q, y] = b[j];
            // debug(q);
            fill(dp[2], dp[2]+4, inf);
            dp[2][y] = 0;
            for (int i = 0; i < 3; i++)
                dp[2][y] += s[i] != q[i];
            for (int i = 3; i < n; i++) {
                dp[i][0] = (s[i] == 'L')+min(dp[i-1][2], dp[i-1][3]);
                dp[i][1] = (s[i] == 'L')+dp[i-1][0];
                dp[i][2] = (s[i] == 'R')+min(dp[i-1][0], dp[i-1][1]);
                dp[i][3] = (s[i] == 'R')+dp[i-1][2];
                // debug(i, vector(dp[i], dp[i]+4));
            }
            for (auto& i : g[j]) ans = min(ans, dp[n-1][i]);
        }
        cout << ans << "\n";
    }
}