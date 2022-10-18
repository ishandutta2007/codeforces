#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll a[300300], b[300300];

int main() {
    ios_base::sync_with_stdio(false);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i] >> b[i];
        ll cur = a[0];
        for (int i = 1; i < n; ++i) {
            cur += max(0LL, a[i] - b[i - 1]);
        }
        ll ans = cur;
        for (int i = 1; i < n; ++i) {
            cur -= a[i - 1];
            cur += max(0LL, a[i - 1] - b[(i + n + n - 2) % n]);
            cur -= max(0LL, a[i] - b[i - 1]);
            cur += a[i];
            ans = min(ans, cur);
        }
        cout << ans << "\n";
    }
}