#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> a(n);
        for (LL& ai : a) cin >> ai;
        LL ans = 0;
        for (int i = 0, p = 0; i + 1 < n; i += 1) {
            ans += a[i];
            if (not a[i]) ans += p;
            else p = 1;
        }
        cout << ans << "\n";
    }
}