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

    ll c1, c2, x, y;
    cin >> c1 >> c2 >> x >> y;
    ll L = 2, R = 1e18;
    while (L < R) {
        ll mid = (L + R) >> 1;
        ll k1 = mid / y - mid / (x * y);
        ll k2 = mid / x - mid / (x * y);
        ll num = mid - k1 - k2 - mid / (x * y);
        if (num >= max(0LL, c1 - k1) + max(0LL, c2 - k2))
            R = mid;
        else
            L = mid + 1;
    }
    cout << L << endl;
}