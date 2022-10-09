#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto i : s) {
        if (i == 'L' || i == 'R') {
            cout << i;
        } else {
            if (i == 'D')
                cout << 'U';
            else
                cout << 'D';
        }
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE
}