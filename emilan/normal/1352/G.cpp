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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n < 4) {
            cout << "-1\n";
            continue;
        }

        vi a;
        for (int i = 0; i < n / 4; i++) {
            a.insert(a.end(), {i * 4 + 2, i * 4 + 4, i * 4 + 1, i * 4 + 3});
        }

        int r = n % 4, c = n - r;
        if (r >= 1) a.pb(c + 1);
        if (r >= 2) a.insert(a.end() - 4, c + 2);
        if (r >= 3) a.pb(c + 3);

        rep(i, n) cout << a[i] << " \n"[i == n - 1];
    }

    return 0;
}