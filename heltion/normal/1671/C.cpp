#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, x;
        cin >> n >> x;
        vector<LL> a(n);
        for (LL& ai : a) cin >> ai;
        LL ans = 0, s = 0, c = 0;
        sort(a.begin(), a.end());
        for (LL ai : a) {
            s += ai;
            c += 1;
            if (x >= s) ans += (x - s) / c + 1;
        }
        cout << ans << "\n";
    }
}