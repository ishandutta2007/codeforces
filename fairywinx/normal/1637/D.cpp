#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    long long val = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        val += (n - 2) * a[i] * a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum += b[i];
        val += (n - 2) * b[i] * b[i];
    }
    
    const long long inf = 1e18 + 228;
    long long ans = inf;
    const int N = 100 * 100 + 228;
    bitset<N> can;
    can[0] = 1;
    for (int i = 0; i < n; ++i) {
        can = (can << a[i]) | (can << b[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (can[i])
            ans = min(ans, 1ll * i * i + 1ll * (sum - i) * (sum - i));
    }
    cout << ans + val << '\n';
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