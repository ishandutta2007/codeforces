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
    vt<int> a(3), b(3);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    auto get_win = [](vt<int> a1, vt<int> b1) {
        return min(a1[0], b1[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
    };

    int mx = get_win(a, b);

    int mn = n;
    vt<int> p(3);
    iota(all(p), 0);
    do {
        function<int(vt<int>, vt<int>, int)> f =
        [&](vt<int> a1, vt<int> b1, int idx) {
            if (idx == 3) return get_win(a1, b1);
            
            int mn1 = min(a1[p[idx]], b1[p[idx]]);
            int mn2 = min(a1[p[idx]], b1[(p[idx] + 2) % 3]);

            int ret = n;

            a1[p[idx]] -= mn1, b1[p[idx]] -= mn1;
            ret = min(ret, f(a1, b1, idx + 1));
            a1[p[idx]] += mn1, b1[p[idx]] += mn1;

            a1[p[idx]] -= mn2, b1[(p[idx] + 2) % 3] -= mn2;
            ret = min(ret, f(a1, b1, idx + 1));

            return ret;
        };

        mn = min(mn, f(a, b, 0));
    } while (next_permutation(all(p)));

    cout << mn << ' ' << mx;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}