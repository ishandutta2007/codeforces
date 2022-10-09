#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

bool check(vector<int> a, int val) {
    for (int i = 0; i < (int) a.size(); ++i) {
        if (abs(val + i - a[i]) > 1) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = -1; i <= 1; ++i) {
        if (check(a, a[0] + i)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    #ifdef DEBUG
        freopen( "main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}