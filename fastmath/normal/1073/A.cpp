#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i + 1]) {
            cout << "YES\n";
            cout << s[i] << s[i + 1] << '\n';
            exit(0);
        }
    }

    cout << "NO\n";

    return 0;
}