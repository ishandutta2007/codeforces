#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    array<vector<int>, 26> pos;
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;

        array<int, 26> f{};
        for (char c : t) f[c - 'a']++;

        int ans = 0;
        for (int i = 0; i < 26; i++) if (f[i] > 0) {
            ans = max(ans, pos[i][f[i] - 1]);
        }
        cout << ans + 1 << "\n";
    }
}