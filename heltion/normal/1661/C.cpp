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
        vector<LL> h(n);
        for (LL& hi : h) cin >> hi;
        auto f = [&](vector<LL> x, LL y) {
            LL p = 0, q = 0;
            for (LL xi : x) {
                xi = y - xi;
                p += xi / 2;
                q += xi & 1;
            }
            LL L = 0, R = 1E15;
            while (L < R) {
                LL M = (L + R) >> 1;
                LL g = M / 2, h = (M + 1) / 2;
                if (g * 2 + h >= p * 2 + q and h >= q)
                    R = M;
                else L = M + 1;
            }
            return L;
        };
        LL mx = ranges::max(h);
        cout << min(f(h, mx), f(h, mx + 1)) << "\n";
    }
    return 0;
}