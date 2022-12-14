#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    vt<int> g(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            g[j] = max(i, g[j]);
        }
    }

    priority_queue<pii> q;
    for (int i = 2; i <= n; i++) {
        q.emplace(-g[i], i);
    }

    for (int i = 1; i < n; i++) {
        cout << -q.top().fi << ' ';
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}