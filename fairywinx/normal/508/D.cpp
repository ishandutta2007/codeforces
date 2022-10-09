#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

map<string, vector<string>> G;
map<string, int> deg;

string ans;

void huinya(string v) {
    vector<pair<string, char>> s;
    s.emplace_back(v, '}');
    while (s.size()) {
        auto c = s.back().first;
        if (G[c].size()) {
            s.emplace_back(G[c].back(), G[c].back().back());
            G[c].pop_back();
            continue;
        } else {
            reverse(all(s.back().first));
            if (s.back().second == '}')
                ans += s.back().first;
            else
                ans += s.back().second;
            s.pop_back();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++cnt[s];
        string z1 = s.substr(0, 2), z2 = s.substr(1, 2);
        ++deg[z1];
        --deg[z2];
        G[z1].push_back(z2);
    }
    bool find = false;
    for (auto i : G) {
        if (deg[i.first] > 0) {
            find = true;
            huinya(i.first);
            break;
        }
    }
    if (!find) {
        huinya(G.begin()->first);
    }

    reverse(all(ans));
    for (int i = 0; i + 2 < (int) ans.size(); ++i) {
        --cnt[ans.substr(i, 3)];
    }
    for (auto i : cnt) {
        if (i.second) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    cout << ans << '\n';
}