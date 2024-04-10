#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, ans = 1;
        string s;
        cin >> n >> s;
        for (int L = 0, R = 0; L < n and ans; L = R += 1) if (s[L] != 'W') {
            while (R < n and s[R] != 'W') R += 1;
            if (*min_element(s.begin() + L, s.begin() + R) == *max_element(s.begin() + L, s.begin() + R))
                ans = 0;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}