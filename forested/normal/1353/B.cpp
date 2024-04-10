#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    
    vector<pair<int, int>> s(2 * n);
    rep(i, n) s[i] = pair<int, int>{a[i], 0};
    rep(i, n) s[i + n] = pair<int, int>{b[i], 1};
    sort(s.rbegin(), s.rend());
    int cnt = 0, ans = 0, now = 0;
    rep(i, n) {
        while (cnt == k && s[now].second == 1) ++now;
        ans += s[now].first;
        if (s[now].second == 1) ++cnt;
        ++now;
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}