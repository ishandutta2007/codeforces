#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int mod = 1'000'000'007;
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}
inline int mul(int x, int y) {
    return x * (ll)y % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> deg2(n + 1);
    deg2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        deg2[i] = mul(2, deg2[i - 1]);
    }
    int ans = deg2[n];
    add(ans, mod - 1);

    vector<int> cnt(30);
    int overall = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int cur = 0;
        while (x % 2 == 0) {
            x /= 2;
            ++cur;
        }
        if (cur) {
            ++cnt[cur];
            ++overall;
        }
    }
    for (int i = 1; i < 30; ++i) {
        if (cnt[i]) {
            overall -= cnt[i];
            int cur = mul(deg2[cnt[i] - 1], deg2[overall]);
            add(ans, mod - cur);
        }
    }
    cout << ans << endl;
}