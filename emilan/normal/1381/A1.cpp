#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int tcs;
    cin >> tcs;
    while (tcs--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        vi ops;
        rep(i, n) {
            if (a[0] == b[n - i - 1]) {
                a[0] = a[0] == '1' ? '0' : '1';
                ops.pb(1);
            }

            for (int j = 0; j < (n - i) / 2; j++) {
                swap(a[j], a[n - i - j - 1]);
            }
            rep(j, n - i) a[j] = a[j] == '1' ? '0' : '1';
            ops.pb(n - i);
        }

        cout << sz(ops);
        for (int i : ops) cout << ' ' << i;
        cout << '\n';
    }

    return 0;
}