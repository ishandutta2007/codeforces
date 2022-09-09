#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<LL> L(c), R(c), Y(c);
        constexpr LL inf = 1'000'000'000'000'000'000LL + 1;
        for (int i = 0; i < c; i += 1) {
            cin >> L[i] >> R[i];
            Y[i] = i ? Y[i - 1] : n;
            Y[i] = min(Y[i] + R[i] - L[i] + 1, inf);
        }
        for (int qi = 0; qi < q; qi += 1) {
            LL k;
            cin >> k;
            for (int i = c - 1; i >= 0; i -= 1) {
                LL p = i ? Y[i - 1] : n;
                if (k > p)
                    k = L[i] + k - p - 1;
            }
            cout << s[k - 1] << "\n";
        }
    }
}