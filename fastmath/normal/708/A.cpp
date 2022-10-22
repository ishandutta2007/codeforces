#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int p = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'a') {
            p = i;
            break;
        }
    }

    if (p == -1) {
        for (int i = 0; i < n - 1; ++i) cout << 'a';
        cout << 'z';
        cout << '\n';
        exit(0);
    }

    for (int i = p; i < n; ++i) {
        if (s[i] == 'a') break;
        --s[i];
    }

    cout << s << '\n';
    return 0;
}