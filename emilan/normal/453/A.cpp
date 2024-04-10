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
    int m, n;
    cin >> m >> n;

    double sum = m;
    for (double i = 1; i < m; i++) {
        sum -= pow(i / m, n);
    }
    cout << setprecision(5) << fixed << sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}