#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        //x = (m - p) / 3 <= em
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            int m = 0, p = 0, em = 0, lm = 0;
            for (int j = i; j < n; j += 1) {
                if (s[j] == '+') p += 1, lm = 0;
                else {
                    m += 1;
                    if (lm) em += 1, lm = 0;
                    else lm = 1;
                }
                if (m >= p and (m - p) % 3 == 0 and (m - p) / 3 <= em)
                    ans += 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}