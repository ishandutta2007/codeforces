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
    vt<int> a(n);
    for (int &x : a) cin >> x;

    int mx = *max_element(all(a));
    if (count(all(a), mx) == n) return void(cout << "-1\n");

    for (int i = 0; i < n; i++) {
        if (a[i] == mx
                && (i && a[i - 1] != mx
                    || i != n - 1 && a[i + 1] != mx)
            ) {
            cout << i + 1 << '\n';
            break;
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