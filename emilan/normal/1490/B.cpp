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
    vt<int> f(3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        f[x % 3]++;
    }

    int ans = 0;
    for (int i = 0; i < 6; i++) {
        if (f[i % 3] > n / 3) {
            int d = f[i % 3] - n / 3;
            f[(i + 1) % 3] += d;
            f[i % 3] -= d;
            ans += d;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}