#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 1e9, right = 0;
    vector<int> cnt(3, 0);
    rep(left, s.size()) {
        while (!(cnt[0] && cnt[1] && cnt[2]) && right < s.size()) {
            ++cnt[s[right] - '1'];
            ++right;
        }
        if (cnt[0] && cnt[1] && cnt[2]) ans = min(ans, right - left);
        if (left == right) ++right;
        else --cnt[s[left] - '1'];
    }
    if (ans == 1e9) cout << 0 << "\n";
    else cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}