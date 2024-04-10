#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int ans = 10;
        for (int t : {0, 1}) {
            int win = 0;
            for (int i = 0; i < 10; i++) {
                if (s[i] == '1') i % 2 == t ? win++ : win--;
                else if (s[i] == '?' && i % 2 == t) win++;
                int num = 0;
                for (int j = i + 1; j < 10; j++) {
                    if (j % 2 != t) num++;
                }
                if (win > num) { ans = min(ans, i + 1); break; }
                num = 0;
                for (int j = i + 1; j < 10; j++) {
                    if (j % 2 == t) num++;
                }
                if (-win > num) { ans = min(ans, i + 1); break; }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}