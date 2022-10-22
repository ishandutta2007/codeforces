#include <bits/stdc++.h>

using namespace std;

int cnt[26][26];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n - 1; ++i) {
        ++cnt[s[i] - 'A'][s[i + 1] - 'A'];
    }

    int mx = 0;
    for (int i = 0; i < 26; ++i) for (int j = 0; j < 26; ++j) mx = max(mx, cnt[i][j]);

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (cnt[i][j] == mx) {
                cout << (char)('A' + i) << (char)('A' + j) << '\n';
                return 0;
            }
        }
    }

    return 0;
}