#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        int m = k & 1;
        string s;
        cin >> s;
        vector<int> f(n);
        for (int i = 0; i + 1 < n; i += 1)
            if ((s[i] - '0') == m and k) {
                f[i] = 1;
                k -= 1;
            }
        f.back() = k;
        for (int i = 0; i < n; i += 1)
            cout << ((s[i] - '0') ^ m ^ (f[i] & 1));
        cout << "\n";
        for (int fi : f) cout << fi << " ";
        cout << "\n";
    }
}