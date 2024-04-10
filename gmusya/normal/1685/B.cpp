#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int n = s.size();
        int cntA = 0;
        int cntB = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'A') {
                ++cntA;
            } else {
                ++cntB;
            }
        }
        if (cntA != a + c + d || cntB != b + c + d) {
            cout << "NO\n";
            continue;
        } else {
            vector<int> diff;
            for (int i = 0; i + 1 < n; ++i) {
                if (s[i] != s[i + 1]) {
                    diff.push_back(i);
                }
            }
            int last = -1000;
            int prev = -1000;
            vector<pair<int, char>> groups;
            for (auto& now : diff) {
                if (last == -1000) {
                    last = now;
                    prev = now;
                } else if (prev + 1 == now) {
                    prev = now;
                } else {
                    groups.emplace_back(prev - last, s[last]);
                    last = now;
                    prev = now;
                }
            }
            if (last != -1000) {
                groups.emplace_back(prev - last, s[last]);
            }
            vector<int> AB_good, BA_good, indifferent;
            for (auto& now : groups) {
                if (now.first % 2 == 0) {
                    if (now.second == 'B') {
                        BA_good.push_back((now.first + 2) / 2);
                    } else {
                        AB_good.push_back((now.first + 2) / 2);
                    }
                } else {
                    indifferent.push_back((now.first + 2) / 2);
                }
            }
            sort(AB_good.begin(), AB_good.end());
            for (auto& now : AB_good) {
                while (now && c > 0) {
                    --c;
                    --now;
                }
                if (now && d > 0) {
                    d -= now - 1;
                    if (d < 0) {
                        d = 0;
                    }
                }
            }
            sort(BA_good.begin(), BA_good.end());
            for (auto& now : BA_good) {
                while (now && d > 0) {
                    --d;
                    --now;
                }
                if (now && c > 0) {
                    c -= now - 1;
                    if (c < 0) {
                        c = 0;
                    }
                }
            }
            for (auto& now : indifferent) {
                while (now && c > 0) {
                    --c;
                    --now;
                }
                while (now && d > 0) {
                    --d;
                    --now;
                }
            }
            if (c == 0 && d == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}