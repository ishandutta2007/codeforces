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

    cout << "2\n";
    if (n == 2) {
        cout << "1 2\n";
    } else {
        cout << n - 2 << ' ' << n << '\n';
        cout << n - 1 << ' ' << n - 1 << '\n';
        for (int i = n - 1; i >= 3; i--) {
            cout << i - 2 << ' ' << i << '\n';
        }
    }
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