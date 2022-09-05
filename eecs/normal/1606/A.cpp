#include <bits/stdc++.h>
using namespace std;

int T, f[110][110][2];
string s;

int main() {
    cin >> T;
    while (T--) {
        cin >> s;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (s[i] == 'a' && s[i + 1] == 'b') cnt1++;
            if (s[i] == 'b' && s[i + 1] == 'a') cnt2++;
        }
        if (cnt1 > cnt2) {
            if (s[0] == 'a') s[0] = 'b';
            else if (s.back() == 'b') s.back() = 'a';
        } else if (cnt1 < cnt2) {
            if (s[0] == 'b') s[0] = 'a';
            else if (s.back() == 'a') s.back() = 'b';
        }
        cout << s << endl;
    }
    return 0;
}