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

#define die return void(cout << "-1\n")

struct op {
    int i, j, x;
};

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    int split = accumulate(all(a), 0);
    if (split % n) die;
    split /= n;
    if (count(all(a), a[0]) == n) return void(cout << "0\n");

    vt<op> ops;
    for (int i = n - 1; i > 0; i--) {
        if (a[i] > i) {
            ops.push_back({i + 1, 1, a[i] / (i + 1)});
            a[0] += a[i] / (i + 1) * (i + 1);
            a[i] %= i + 1;
            break;
        }
    }

    for (int i = 1; i < n; i++) {
        int r = a[i] % (i + 1);
        if (r && a[0] >= i + 1 - r) {
            ops.push_back({1, i + 1, i + 1 - r});
            a[0] -= i + 1 - r;
            a[i] += i + 1 - r;
        }

        ops.push_back({i + 1, 1, a[i] / (i + 1)});
        a[0] += a[i] / (i + 1) * (i + 1);
        a[i] %= i + 1;
    }

    if (*max_element(1 + all(a)) > split) die;

    for (int i = 1; i < n; i++) {
        ops.push_back({1, i + 1, split - a[i]});
        a[0] -= split - a[i];
        a[i] += split - a[i];
    }

    cout << sz(ops) << '\n';
    for (op &x : ops) {
        cout << x.i << ' ' << x.j << ' ' << x.x << '\n';
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