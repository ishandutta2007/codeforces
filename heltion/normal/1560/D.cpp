#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        LL n;
        cin >> n;
        int ans = INT_MAX;
        for (LL k = 1; k <= (1LL << 61); k *= 2) {
            auto s = to_string(k), t = to_string(n);
            int pans = 0;
            for (int i = 0, j = 0; i < (int)s.size(); i += 1) {
                while (j < (int)t.size() and t[j] != s[i]) {
                    j += 1;
                    pans += 1;
                }
                if (j < (int)t.size()) j += 1;
                else pans += 1;
                if (i == (int)s.size() - 1) pans += (int)t.size() - j;
            }
            ans = min(ans, pans);
        }
        cout << ans << "\n";
    }
    return 0;
}