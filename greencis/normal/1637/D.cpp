//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        vector<char> dp{1};
        vector<char> nxt;
        for (int i = 0; i < n; ++i) {
            nxt.assign(2 * 100 * (i + 1) + 1, 0);
            int delta = a[i] - b[i];
            for (int j = -100 * i; j <= 100 * i; ++j) {
                if (dp[100 * i + j]) {
                    nxt[100 * (i + 1) + j - delta] = 1;
                    nxt[100 * (i + 1) + j + delta] = 1;
                }
            }
            swap(nxt, dp);
        }
        int can = -1;
        for (int i = 0; i <= 100 * n; ++i) {
            if (dp[100 * n - i] || dp[100 * n + i]) {
                can = i;
                break;
            }
        }

        ll sum = 0;
        ll sumSq = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            sumSq += (ll)a[i] * a[i];
            sum += b[i];
            sumSq += (ll)b[i] * b[i];
        }

        ll z1 = (sum + can) / 2;
        ll z2 = (sum - can) / 2;
        ll ans = z1 * z1 + z2 * z2 + sumSq * (n - 2);
        cout << ans << '\n';
    }
}