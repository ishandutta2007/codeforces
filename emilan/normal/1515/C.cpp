#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(n);
    for (int &y : a) cin >> y;

    priority_queue<pii> pq;
    for (int i = 0; i < m; i++) {
        pq.emplace(0, i + 1);
    }

    cout << "YES\n";
    for (int y : a) {
        auto [h, p] = pq.top();
        h = -h;
        pq.pop();

        pq.emplace(-(h + y), p);
        cout << p << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}