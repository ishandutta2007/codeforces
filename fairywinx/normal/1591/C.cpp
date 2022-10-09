#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

long long solve(int n, int k, vector<int> a) {
    long long ans = 0;
    for (int i = (int) a.size() - 1; i >= 0; --i) {
        ans += 2 * a[i];
        int it = 0;
        while (it < k - 1) {
            --i;
            ++it;
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a = {0}, b = {0};
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (c >= 0) {
            a.push_back(c);
        } else {
            b.push_back(-c);
        }
    }
    sort(all(a));
    sort(all(b));
    long long ans1 = solve(n, k, a), ans2 = solve(n, k, b);
    cout << ans1 + ans2 - max(a.back(), b.back()) << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}