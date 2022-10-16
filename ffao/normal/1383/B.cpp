#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];

    for (int b = 29; b >= 0; b--) {
        int cnt = 0;
        for (int i = 0; i < n; i++) if (a[i] & (1<<b)) cnt++;

        if (cnt % 2 == 0) continue;
        
        if (cnt % 4 == 1) {
            cout << "WIN" << '\n';
            return;
        }
        
        cout << (((n-cnt) % 2 == 0) ? "LOSE" : "WIN") << '\n';
        return;
    }

    cout << "DRAW" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    for (cin >> t; t; t--) {
        solve();
    }

    return 0;
}