#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string> a(3);
        for (auto &x : a) cin >> x;

        vector<int> f(3);
        for (int i = 0; i < 3; i++) {
            f[i] = count(a[i].begin(), a[i].end(), '0');
        }

        string ans;

        auto go = [&](string &s, string &t) -> void {
            for (int i = 0, j = 0; i < 2 * n || j < 2 * n; i++, j++) {
                while (i < 2 * n && s[i] != '1') {
                    ans += '0';
                    i++;
                }

                while (j < 2 * n && t[j] != '1') {
                    ans += '0';
                    j++;
                }

                if (i < 2 * n || j < 2 * n) ans += '1';
            }
        };

        for (int i = 0, j = 1; i < 3; i++, j = (j + 1) % 3) {
            if (f[i] <= n && f[j] <= n) { // more 1
                string s = a[i], t = a[j];
                go(s, t);

                break;
            } else if (f[i] > n && f[j] > n) { // more 0
                string s = a[i], t = a[j];
                for (char &c : s) c ^= 1;
                for (char &c : t) c ^= 1;
                go(s, t);
                for (char &c : ans) c ^= 1;

                break;
            }
        }

        cout << ans << '\n';
    }
}