#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    int x = 1;
    while (n) {
        if (n % 10) {
            ans.push_back(n % 10 * x);
        }
        n /= 10;
        x *= 10;
    }
    cout << ans.size() << "\n";
    rep(i, ans.size()) {
        cout << ans[i];
        if (i == ans.size() - 1) cout << "\n";
        else cout << " ";
    }
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
    return 0;
}