#include <bits/stdc++.h>

using namespace std;

const int MAXN = 57;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int pos = -1;
    for (int i = 1; i < n; ++i) {
        if (s.substr(i, n - i) == s.substr(0, n - i)) {
            pos = i;
            break;
        }
    }
        
    if (pos == -1) {
        for (int i = 0; i < k; ++i) cout << s;
        cout << '\n';
    } 
    else {
        int len = n - pos;
        string add = s.substr(len, n - len);
        cout << s;
        for (int i = 0; i < k - 1; ++i) cout << add;
        cout << '\n';
    }

    return 0;
}