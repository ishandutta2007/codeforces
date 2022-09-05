#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        bool flag = 0;
        for (int i = 0; i < s.size(); i++) {
            int cur = 0;
            for (int j = i; j < s.size(); j++) {
                if (t[cur] ^ s[j]) break;
                cur++;
                if (cur == t.size()) flag = 1;
                int o = cur;
                for (int k = j - 1; ~k; k--) {
                    if (t[o] ^ s[k]) break;
                    o++;
                    if (o == t.size()) flag = 1;
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}