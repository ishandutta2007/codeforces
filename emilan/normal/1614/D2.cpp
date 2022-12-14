#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int M = 2e7 + 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    array<int, M> f{};
    for (int x : a) {
        for (int i = 1; i * i <= x; i++) if (x % i == 0) {
            f[i]++;
            if (i * i < x) f[x / i]++;
        }
    }

    ll ans = 0;
    bitset<M> vis;
    array<ll, M> dp{};
    for (int s : a) {
        vector<int> fact;
        {
            int x = s;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    fact.push_back(i);
                    x /= i;
                    while (x % i == 0) x /= i;
                }
            }
            if (x != 1) fact.push_back(x);
        }

        vector<int> rm;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            rm.push_back(u);

            dp[u] += ll(u) * f[u];

            for (int p : fact) if (u % p == 0) {
                dp[u / p] = max(dp[u / p], dp[u] - ll(u / p) * f[u]);
                q.push(u / p);
            }
        }

        ans = max(ans, dp[1]);
        for (int i : rm) {
            dp[i] = 0;
            vis[i] = false;
        }
    }

    cout << ans << "\n";
}