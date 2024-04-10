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
    
    if (n < 5) {
        if (n == 3) cout << "1 0 0\n";
        else cout << "-1\n";
    } else {
        int r = n % 3;
        if (r == 0) cout << n / 3 << " 0 0";
        if (r == 1) cout << (n - 7) / 3 << " 0 1";
        if (r == 2) cout << (n - 5) / 3 << " 1 0";
        cout << '\n';
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