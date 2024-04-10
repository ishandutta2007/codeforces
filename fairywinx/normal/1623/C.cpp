#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

bool check(int n, vector<long long> a, int val) {
    auto b = a;
    vector<long long> dp(n);
    for (int i = n - 1; i >= 2; --i) {
        long long cnt = min(a[i] / 3, max(0ll, b[i] - val) / 3);
        dp[i] = cnt;
        b[i - 1] += cnt;
        b[i - 2] += 2 * cnt;
        b[i] -= 3 * cnt;
    }
    for (int i = 2; i < n; ++i) {
        long long res = (i + 1 < n ? dp[i + 1] : 0) + (i + 2 < n ? 2 * dp[i + 2] : 0);
        long long tmp = min(a[i] / 3, max(0ll, res + a[i] - val) / 3);
        a[i - 1] += tmp;
        a[i - 2] += 2 * tmp;
        a[i] -= 3 * tmp;
    }
    for (auto i : a) {
        if (i < val)
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0, r = a.back() + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(n, a, mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    // check(n, a, 3);
    cout << l << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}