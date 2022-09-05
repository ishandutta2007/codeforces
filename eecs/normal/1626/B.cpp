#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> s;
        bool flag = 0;
        for (int i = s.size() - 2; ~i; i--) {
            if (s[i] - '0' + s[i + 1] - '0' >= 10) {
                int x = s[i] - '0' + s[i + 1] - '0';
                s[i] = x / 10 + '0', s[i + 1] = x % 10 + '0';
                cout << s << '\n';
                flag = 1; break;
            }
        }
        if (!flag) {
            int x = s[0] - '0' + s[1] - '0';
            s.erase(s.begin());
            s[0] = x + '0';
            cout << s << '\n';
        }
    }
    return 0;
}