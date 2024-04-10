#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    array<vector<int>, 2> acts;
    for (auto &v : acts) {
        int m;
        cin >> m;
        v.resize(m);
        for (auto &x : v) cin >> x;
    }

    array<vector<int>, 2> dp;
    array<vector<int>, 2> deg;
    queue<pii> q;
    for (int t = 0; t < 2; t++) {
        dp[t] = vector(n, 0);
        deg[t] = vector(n, SZ(acts[t]));
        dp[t][0] = -1;
        deg[t][0] = 0;
        q.emplace(t, 0);
    }
    while (!empty(q)) {
        auto [t, u] = q.front();
        q.pop();

        if (dp[t][u] == -1) {
            for (int d : acts[t ^ 1]) {
                if (int p = (u - d + n) % n; dp[t ^ 1][p] == 0) {
                    dp[t ^ 1][p] = 1;
                    q.emplace(t ^ 1, p);
                }
            }
        } else if (dp[t][u] == 1) {
            for (int d : acts[t ^ 1]) {
                if (int p = (u - d + n) % n; dp[t ^ 1][p] == 0) {
                    if (--deg[t ^ 1][p] == 0) {
                        dp[t ^ 1][p] = -1;
                        q.emplace(t ^ 1, p);
                    }
                }
            }
        }
    }

    for (int t = 0; t < 2; t++) {
        for (int u = 1; u < n; u++) {
            switch (dp[t][u]) {
                case -1: cout << "Lose"; break;
                case 0: cout << "Loop"; break;
                case 1: cout << "Win"; break;
            }
            cout << " \n"[u == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}