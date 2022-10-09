#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans;
    ans.resize(n);
    if (s[0] == '?') {
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'B' || s[j] == 'R') {
                int type;
                if (s[j] == 'B')
                    type = 0;
                else
                    type = 1;
                for (int p = j - 1; p >= 0; --p) {
                    if (type)
                        ans[p] = 'B';
                    else
                        ans[p] = 'R';
                    type ^= 1;
                }
                break;
            }
        }
        if (ans[0] != 'B' && ans[0] != 'R') {
            for (int i = 0; i < n; ++i) {
                if (i % 2 == 0) {
                    ans[i] = 'B';
                } else {
                    ans[i] = 'R';
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            ans[i] = 'B';
            int type = 0;
            ++i;
            while (i < n && s[i] == '?') {
                if (type)
                    ans[i] = 'B';
                else
                    ans[i] = 'R';
                type ^= 1;
                ++i;
            }
            --i;
        } else if (s[i] == 'R') {
            ans[i] = 'R';
            int type = 1;
            ++i;
            while (i < n && s[i] == '?') {
                if (type)
                    ans[i] = 'B';
                else
                    ans[i] = 'R';
                type ^= 1;
                ++i;
            }
            --i;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}