#include <bits/stdc++.h>
using namespace std;

int q;
string s, t;

int main() {
    ios::sync_with_stdio(0);
    cin >> q;
    while (q--) {
        cin >> s >> t;
        bool flag = 0;
        for (int p : {0, 1}) {
            int lst, j = 0;
            for (int i = 0; i < s.size() && j < t.size(); i++) {
                if (s[i] == t[j]) {
                    if (!j && i % 2 != p) continue;
                    if (j && (i - lst) % 2 == 0) continue;
                    if (j == t.size() - 1 && (s.size() - i) % 2 == 0) continue;
                    j++, lst = i;
                }
            }
            if (j == t.size()) flag = 1;
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}