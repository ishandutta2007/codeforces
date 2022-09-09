#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n, x, ans = 0;
        cin >> n >> x;
        vector<LL> a(n);
        for (LL& ai : a)
            cin >> ai;
        for (int i = 1; i < n; i += 1)
            ans += abs(a[i] - a[i - 1]);
        LL mx = *max_element(a.begin(), a.end()), mn = *min_element(a.begin(), a.end());
        LL p = mx < x ? (x - mx) * 2 : 0, q = (mn - 1) * 2;
        p = min({p, abs(x - a[0]), abs(x - a.back())});
        q = min({q, abs(1 - a[0]), abs(1 - a.back())});
        ans += p + q;
        cout << ans << "\n";
    }
}