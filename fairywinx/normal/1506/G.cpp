#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<vector<int>> pos(26);
    vector<vector<int>> pref(26);
    set<int> free;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; ++i) {
        if (pos[i].size())
            free.insert(-i);
        pref[i].resize(n + 1);
    }
    for (int i = 0; i < n; ++i) {
        ++pref[s[i] - 'a'][i + 1];
        for (int j = 0; j < 26; ++j)
            pref[j][i + 1] += pref[j][i];
    }
    string ans;
    int now_pos = 0;
    while (free.size()) {
        for (int c : free) {
            c = -c;
            int p = *lower_bound(all(pos[c]), now_pos);
            bool can = true;
            for (int i : free) {
                i = -i;
                if (i == c)
                    continue;
                if (pref[i].back() - pref[i][p] <= 0)
                    can = false;
            }
            if (can) {
                free.erase(-c);
                ans += (char) c + 'a';
                now_pos = p;
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}