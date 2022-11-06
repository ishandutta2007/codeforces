#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector f(n, vector(n, 0));
    for (int i = 0; i + 1 < n; i++) {
        f[i][i + 1] = (s[i] == s[i + 1]) ? 0 : 1;
    }
    auto work = [&](int l, int r, char c) {
        int d = min(f[l + 1][r], f[l][r - 1]);
        if (d != 0) {
            return d;
        }
        d = 1;
        if (f[l + 1][r] == 0) {
            if (s[l] < c) {
                d = min(d, -1);
            } else if (s[l] == c) {
                d = min(d, 0);
            }
        }
        if (f[l][r - 1] == 0) {
            if (s[r] < c) {
                d = min(d, -1);
            } else if (s[r] == c) {
                d = min(d, 0);
            }
        }
        return d;
    };
    for (int len = 4; len <= n; len += 2) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            f[l][r] = max(work(l + 1, r, s[l]), work(l, r - 1, s[r]));
        }
    }
    vector<string> ans = {"Bob", "Draw", "Alice"};
    puts(ans[f[0][n - 1] + 1].c_str());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}