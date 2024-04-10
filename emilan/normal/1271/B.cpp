#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int wcnt = count(all(s), 'W');

    vt<int> ans;
    if (wcnt & 1) {
        if (~n & 1) return cout << -1, 0;

        for (int i = 0; i < n - 1; i++) {
            if (s[i] != 'W') {
                ans.push_back(i + 1);
                s[i + 1] = s[i + 1] == 'W' ? 'B' : 'W';
            }
        }
    } else {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] != 'B') {
                ans.push_back(i + 1);
                s[i + 1] = s[i + 1] == 'W' ? 'B' : 'W';
            }
        }
    }

    cout << sz(ans) << '\n';
    for (int i : ans) cout << i << ' ';
}