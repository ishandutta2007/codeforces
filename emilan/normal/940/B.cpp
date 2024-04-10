#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    if (k == 1) {
        cout << ll(n - 1) * a;
        return 0;
    }

    ll ans = 0;
    while (n > 1) {
        if (n % k) {
            ans += ll(n % k) * a;
            n -= n % k;
        }

        if (b > ll(n - n / k) * a) {
            ans += ll(n - 1) * a;
            n = 1;
        } else {
            ans += b;
            n /= k;
        }
    }

    cout << ans;
}