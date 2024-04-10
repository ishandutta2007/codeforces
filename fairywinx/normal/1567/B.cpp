#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

int res[(int) 1e6];

void solve() {
    int a, b;
    cin >> a >> b;
    if (res[a - 1] == b) {
        cout << a << '\n';
    } else {
        if ((res[a - 1] ^ b) == a) {
            cout << a + 2 << '\n';
        } else {
            cout << a + 1 << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < (int) 1e6 - 1; ++i) {
        res[i + 1] = res[i] ^ (i + 1);
    }

    SOLVE
}