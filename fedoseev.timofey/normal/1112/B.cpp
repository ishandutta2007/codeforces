#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 150 * 1000 + 7;
                                                         
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> st(k), wh(k, -1);
    int cnt = 0;
    int ans = 0;
    int uk = 0;
    vector <int> ok(n);
    for (int t = 0; t < N; ++t) {
        for (int i = 0; i < k; ++i) {
            if (wh[i] != -1 && st[i] + a[wh[i]] == t) {
                wh[i] = -1;
                ++cnt;
            } 
        }
        for (int i = 0; i < k; ++i) {
            if (wh[i] == -1) {
                if (uk < n) {
                    st[i] = t;
                    wh[i] = uk;
                    ++uk;
                }
            }
        } 
        int cr = (100 * (double)cnt / n) + 0.5;
        for (int i = 0; i < k; ++i) {
            if (wh[i] == -1) continue;
            int tst = t - st[i] + 1;
            if (cr == tst) {
                ok[wh[i]] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) ans += ok[i];
    cout << ans << '\n';
}