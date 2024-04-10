#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        string s;
        cin >> s;
        int ans = 1e9;
        for (int rem = 0; rem < 4; ++rem) {
            int d1 = rem * 25 / 1 % 10;
            int d2 = rem * 25 / 10 % 10;
            int cur = 0;
            int i = s.size() - 1;
            int prv_i = i;
            while (i >= 0 && s[i] != d1 + '0')
                --i;
            if (i != -1) {
                cur += prv_i - i;
                --i;
                prv_i = i;
                while (i >= 0 && s[i] != d2 + '0')
                    --i;
                if (i != -1) {
                    cur += prv_i - i;
                    ans = min(ans, cur);
                }
            }
        }
        cout << ans << '\n';
    }
}