#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (auto &v : a) {
            cin >> v[i];
        }
    }

    sort(a.rbegin(), a.rend());

    map<int, int> m;
    vector<pair<int, int>> tmp;
    auto add_m = [&]() {
        for (auto [x, y] : tmp) {
            auto it_right = m.lower_bound(x);
            if (it_right == m.end() || y > it_right->second) {
                m.erase(x);
                auto it = m.emplace(x, y).first;
                while (it != m.begin()) {
                    auto it_rm = prev(it);
                    if (y >= it_rm->second) {
                        m.erase(it_rm);
                    } else {
                        break;
                    }
                }
            }
        }

        tmp.clear();
    };

    int ded = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && a[i - 1][0] > a[i][0]) {
            add_m();
        }

        auto it = m.upper_bound(a[i][1]);
        if (it != m.end() && a[i][2] < it->second) {
            ded++;
        } else {
            tmp.emplace_back(a[i][1], a[i][2]);
        }
    }

    cout << ded << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}