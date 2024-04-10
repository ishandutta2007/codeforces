#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 500000;

ll a[N + 1];

const int K = 750;
ll val[K][K];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            a[x] += y;
            for (int j = 1; j < K; ++j) {
                val[j][x % j] += y;
            }
        } else {
            int x, y;
            cin >> x >> y;
            if (x < K) {
                cout << val[x][y] << '\n';
            } else {
                ll ans = 0;
                for (int i = y; i <= N; i += x) {
                    ans += a[i];
                }
                cout << ans << '\n';
            }
        }
    }
}