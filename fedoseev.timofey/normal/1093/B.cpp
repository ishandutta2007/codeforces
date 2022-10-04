#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector <int> cnt(26);
        for (auto c : s) ++cnt[c - 'a'];
        bool bad = false;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] == (int)s.size()) {
                cout << "-1\n";
                bad = true;
                break;
            }
        }
        if (!bad) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < cnt[i]; ++j) {
                    cout << char('a' + i);
                }
            }
            cout << '\n';
        }
    }
}