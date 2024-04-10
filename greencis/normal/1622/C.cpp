#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(all(a));
        ll sum = 0;
        for (int i = 1; i < n; ++i)
            sum += a[i];
        ll ans = max(0LL, sum + a[0] - k);
        for (int m = n - 2; m >= 0; --m) {
            sum -= a[m + 1];
            ll upper = k - sum;
            ll rem = upper % (n - m);
            if (rem < 0) rem += n - m;
            upper = (upper - rem) / (n - m);
            ans = min(ans, max(0LL, a[0] - upper) + n - m - 1);
        }
        cout << ans << '\n';
    }
}