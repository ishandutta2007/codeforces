#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        int ans = -1;
        for (char c = 'a'; c <= 'z'; c += 1) {
            int pans = 0;
            int L = 0, R = n - 1;
            while (L < R) {
                if (s[L] == s[R]) {
                    L += 1;
                    R -= 1;
                }
                else if (s[L] == c) {
                    pans += 1;
                    L += 1;
                }
                else if (s[R] == c) {
                    pans += 1;
                    R -= 1;
                }
                else {
                    pans = -1;
                    break;
                }
            }
            if (pans != -1 and (ans == -1 or pans < ans)) ans = pans;
        }
        cout << ans << "\n";
    }
    return 0;
}