#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> c(n);
    for (LL& x : c) cin >> x;
    LL ans = 0;
    for (int i = 0; i < n; i += 2) {
        LL sum = 0, msum = 0;
        for (int j = i + 1; j < n; j += 1) {
            if (j & 1) {
                LL L = max(1LL, -msum);
                LL R = min({c[i], c[j] - sum});
                if (L <= R) ans += (R - L + 1);
                //cout << i << " " << j << " " << L << " " << R << '\n';
            }
            if (j & 1) sum -= c[j];
            else sum += c[j];
            msum = min(sum, msum);
        }
    }
    cout << ans;
    return 0;
}