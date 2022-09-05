#include <bits/stdc++.h>
using namespace std;

int T, n, m;

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        string s;
        cin >> s;
        while (m--) {
            string t = s;
            for (int i = 0; i < n; i++) if (t[i] == '0') {
                if ((i && s[i - 1] == '1') + (i < n - 1 && s[i + 1] == '1') == 1) t[i] = '1';
            }
            if (s == t) break;
            s = t;
        }
        cout << s << endl;
    }
    return 0;
}