#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vi> a(n, vi(m));
    for (auto& i : a) for (int& j : i) cin >> j;

    rep(i, 10) {
        int res = 0;
        rep(j, n) res ^= a[j][0] >> i & 1;

        rep(j, n) {
            int can = -1;
            rep(k, m) {
                if (a[j][0] >> i & 1 ^ a[j][k] >> i & 1) {
                    can = k;
                    break;
                }
            }

            if (res || can != -1) {
                cout << "TAK\n";
                rep(k, j) cout << "1 ";
                cout << (res ? 1 : can + 1);
                for (int k = j + 1; k < n; k++) cout << " 1";
                return 0;
            }
        }

    }
    cout << "NIE";
}