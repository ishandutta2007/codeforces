#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int ans = n + 1;
    for (char c = 'a'; c <= 'z'; c++) {
        string t(s);
        t.erase(remove(t.begin(), t.end(), c), t.end());

        if (t == string(t.rbegin(), t.rend())) {
            int cur = count(s.begin(), s.end(), c);
            for (int l = 0, r = n - 1; l <= r; l++, r--) {
                if (s[l] == c && s[r] == c) {
                    if (l == r) cur--;
                    else cur -= 2;
                } else {
                    while (s[l] == c) l++;
                    while (s[r] == c) r--;
                }
            }

            ans = min(ans, cur);
        }
    }

    if (ans == n + 1) cout << -1;
    else cout << ans;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}