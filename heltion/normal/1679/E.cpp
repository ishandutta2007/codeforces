#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 998244353;
void add(int& x, int y) {
    if ((x += y) >= mod)
        x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    string s;
    cin >> n >> s >> q;
    int m = ranges::count(s, '?');
    vector ans(18, vector<int>(1 << 17));
    vector pow(18, vector<int>(m + 1));
    for (int i = 1; i <= 17; i += 1)
        for (int j = 0; j <= m; j += 1)
            pow[i][j] = j ? (LL)pow[i][j - 1] * i % mod : 1;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0, x = 0, y = m; i - j >= 0 and i + j < n; j += 1) {
            if (s[i - j] != s[i + j] and s[i - j] != '?' and s[i + j] != '?')
                break;
            if (s[i - j] == '?' and s[i + j] != '?')
                x |= 1 << (s[i + j] - 'a');
            if (s[i - j] != '?' and s[i + j] == '?')
                x |= 1 << (s[i - j] - 'a');
            if (j and (s[i - j] == '?' or s[i + j] == '?'))
                y -= 1;
            for (int k = 1; k <= 17; k += 1)
                add(ans[k][x], pow[k][y]);
        }
    }
    for (int i = 0; i + 1 < n; i += 1) {
        vector<int> res(18, 1);
        for (int j = 0, x = 0, y = m; i - j >= 0 and i + j + 1 < n; j += 1) {
            if (s[i - j] != s[i + j + 1] and s[i - j] != '?' and s[i + j + 1] != '?')
                break;
            if (s[i - j] == '?' and s[i + j + 1] != '?')
                x |= 1 << (s[i + j + 1] - 'a');
            if (s[i - j] != '?' and s[i + j + 1] == '?')
                x |= 1 << (s[i - j] - 'a');
            if (s[i - j] == '?' or s[i + j + 1] == '?')
                y -= 1;
            for (int k = 1; k <= 17; k += 1)
                add(ans[k][x], pow[k][y]);
        }
    }
    if (0) for (int k = 1; k <= 17; k += 1)
        for (int j = 0; j < (1 << 17); j += 1)
            if (ans[k][j])
                cout << k << " " << j << " " << ans[k][j] << "\n";
    for (int k = 1; k <= 17; k += 1)
        for (int i = 0; i < 17; i += 1)
            for (int j = 0; j < (1 << 17); j += 1)
                if ((j >> i) & 1)
                    add(ans[k][j], ans[k][j ^ (1 << i)]);
    for (int i = 0; i < q; i += 1) {
        string t;
        cin >> t;
        int j = 0;
        for (char c : t) j |= 1 << (c - 'a');
        cout << ans[t.size()][j] << "\n";
    }
}