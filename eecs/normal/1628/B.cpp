#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n;
string s[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        cin >> n;
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            if (s[i].size() == 1) flag = 1;
        }
        set<string> S, T;
        for (int i = 1; i <= n && !flag; i++) {
            string t = s[i];
            reverse(t.begin(), t.end());
            if (s[i] == t) flag = 1;
            if (S.count(t)) flag = 1;
            if (s[i].size() == 3) {
                string t;
                t.push_back(s[i][2]), t.push_back(s[i][1]);
                if (T.count(t)) flag = 1;
                S.insert(string(s[i].begin(), s[i].begin() + 2));
                S.insert(s[i]);
            } else {
                S.insert(s[i]), T.insert(s[i]);
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}