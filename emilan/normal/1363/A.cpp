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
    int n, x;
    cin >> n >> x;

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a & 1) odd++;
        else even++;
    }

    if (x == n) cout << (odd & 1 ? "Yes" : "No");
    else if (x & 1) cout << (odd ? "Yes" : "No");
    else cout << (odd && even ? "Yes" : "No");
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}