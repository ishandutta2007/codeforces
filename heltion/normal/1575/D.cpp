#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 100000000; i += 25) {
        auto t = to_string(i);
        if (t.size() == s.size()) {
            int X = -1, ok = 1;
            for (int i = 0; i < (int)s.size(); i += 1) {
                if (s[i] == '_') continue;
                else if (s[i] == 'X') {
                    int Y = t[i] - '0';
                    if (X == -1 or Y == X) {
                        X = Y;
                    }
                    else ok = 0;
                }
                else ok &= s[i] == t[i];
            }
            //if (ok) cout << s << " " << t << "\n";
            ans += ok;
        }
    }
    cout << ans;
    return 0;
}