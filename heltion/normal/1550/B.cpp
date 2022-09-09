#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, a, b;
        string s;
        cin >> n >> a >> b >> s;
        if (b > 0) cout << (a + b) * n << "\n";
        else {
            int m = 1;
            for (int i = 1; i < n; i += 1) m += s[i] != s[i - 1];
            cout << (m + 2) / 2 * b + n * a << '\n';
        }
    }
    return 0;
}