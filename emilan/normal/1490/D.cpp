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

    vt<int> d(n, -1);
    vt<bool> l(n), r(n);
    for (int i = n; i; i--) {
        int p = 0;
        while (a[p] != i) p++;

        for (int j = p - 1; ~j; j--) {
            if (~d[j]) {
                if (!r[j]) {
                    r[j] = true;
                    d[p] = d[j] + 1;
                }

                break;
            }
        }
        if (~d[p]) continue;

        for (int j = p + 1; j < n; j++) {
            if (~d[j]) {
                if (!l[j]) {
                    l[j] = true;
                    d[p] = d[j] + 1;
                }

                break;
            }
        }
        if (~d[p]) continue;

        d[p] = 0;
    }

    for (int x : d) cout << x << ' ';
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