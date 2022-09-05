#include <bits/stdc++.h>
using namespace std;

int T, mark[200010][26];
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        memset(mark[s.size()], 0, sizeof(mark[s.size()]));
        for (int i = s.size() - 1; ~i; i--) {
            memcpy(mark[i], mark[i + 1], sizeof(mark[i]));
            mark[i][s[i] - 'a'] = 1;
        }
        for (int i = 0; i < s.size(); i++) if (!mark[i + 1][s[i] - 'a']) {
            cout << s.substr(i) << "\n"; break;
        }
    }
    return 0;
}