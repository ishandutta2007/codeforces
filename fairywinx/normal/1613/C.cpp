#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    long long a;
    cin >> n >> a;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    long long l = 0, r = 1e18 + 228;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        long long val = 0;
        for (int i = 0; i < n - 1; ++i) {
            val += min((long long) b[i + 1] - b[i], mid);
        }
        val += mid;
        if (val >= a)
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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