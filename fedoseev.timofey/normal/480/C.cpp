#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;

void add(int &a, int b) {
    a += b;
    if (a >= md) a -= md;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += md;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    --a, --b;
    vector <int> dp(n);
    dp[a] = 1;
    for (int j = 0; j < k; ++j) {
        vector <int> ndp(n);
        auto ad = [&] (int l, int r, int x) {
            if (r < l) return;
            add(ndp[l], x);
            if (r + 1 < n) sub(ndp[r + 1], x);
        };
        for (int i = 0; i < n; ++i) {
            int d = abs(i - b) - 1;
            int l = max(0, i - d);
            int r = min(n - 1, i + d);
            ad(l, i - 1, dp[i]);
            ad(i + 1, r, dp[i]);
        }
        for (int i = 1; i < n; ++i) {
            add(ndp[i], ndp[i - 1]);
        }
        dp = ndp;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) add(ans, dp[i]);
    cout << ans << '\n';
}