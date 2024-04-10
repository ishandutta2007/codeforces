#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void solve() {
    int s;
    cin >> s;
    int sum = 0;
    for (int i = 1;; ++i) {
        sum += i * 2 - 1;
        if (sum >= s) {
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}