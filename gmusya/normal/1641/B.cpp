#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) {
            cin >> x;
        }
        map<int, int> cnt;
        for (int& x : a) {
            ++cnt[x];
        }
        bool good = true;
        for (auto& now : cnt) {
            if (now.second & 1) {
                good = false;
            }
        }
        if (!good) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> cur = a;
        int l = 0;
        vector<pair<int, int>> ans;
        vector<int> repeats;
        for (int i = 1; i < cur.size(); ++i) {
            if (cur[i] == cur[l]) {
                vector<int> to_add2;
                for (int j = i + 1; j < cur.size(); ++j) {
                    to_add2.push_back(cur[j]);
                }
                cur.resize(i + 1);
                vector<int> to_add;
                for (int j = l + 1; j < i; ++j) {
                    ans.emplace_back(cur.size(), cur[j]);
                    cur.push_back(cur[j]);
                }
                for (int j = i - 1; j > l; --j) {
                    cur.push_back(cur[j]);
                }
                for (auto& now : to_add2) {
                    cur.push_back(now);
                }
                int len = (i - l);
                repeats.push_back(len);
                l = l + 2 * len;
                i = l;
            }
        }
        cout << ans.size() << "\n";
        for (auto& now : ans) {
            cout << now.first << ' ' << now.second << '\n';
        }
        cout << repeats.size() << "\n";
        for (auto& now : repeats) {
            cout << now * 2 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
1
6
1 3 1 2 2 3
 */