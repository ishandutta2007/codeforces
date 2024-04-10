#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

void solve(int tc) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a * n != b * m) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        vt<int> cur(m);
        for (int j = 0; j < a; j++) cur[(i * a + j) % m] = 1;
        for (int j : cur) cout << j;
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) solve(tc);
}