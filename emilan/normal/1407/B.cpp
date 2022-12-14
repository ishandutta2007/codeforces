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
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &i : a) cin >> i;

    vt<int> ans(n);
    int g = 0;
    for (int i = 0; i < n; i++) {
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (!a[j]) continue;

            if (!~idx || __gcd(g, a[j]) > __gcd(g, a[idx])) {
                idx = j;
            }
        }

        g = __gcd(g, a[idx]);
        ans[i] = a[idx];
        a[idx] = 0;
    }

    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve(tc);
    }
}