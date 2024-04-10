#include <bits/stdc++.h>

using namespace std;

using tri = array<int, 3>;

struct BIT {
    int n;
    vector<int> a;

    BIT(int _n) : n(_n + 2), a(n) {}

    void add(int i, int d) {
        for (i++; i < n; i += i & -i) {
            a[i] += d;
        }
    }

    int sum(int i) {
        int ret = 0;
        for (i++; i > 0; i -= i & -i) {
            ret += a[i];
        }
        return ret;
    }
};

void solve() {
    int q;
    cin >> q;
    vector<tri> tasks(q);
    for (tri &v : tasks) {
        for (int &z : v) cin >> z;
    }

    map<int, vector<tri>> ops_map;
    for (int i = 0; i < q; i++) {
        auto [a, t, x] = tasks[i];
        ops_map[x].push_back({a, t, i});
    }

    map<int, int> ans;
    for (auto [x, ops] : ops_map) {
        map<int, int> time2idx;
        for (auto [a, t, i] : ops) {
            time2idx[t] = 0;
        }

        {
            int j = 0;
            for (auto &[t, idx] : time2idx) {
                idx = j++;
            }
        }

        BIT bit(ops.size());
        for (auto [a, t, i] : ops) {
            if (a == 1) {
                bit.add(time2idx[t], 1);
            } else if (a == 2) {
                bit.add(time2idx[t], -1);
            } else {
                ans[i] = bit.sum(time2idx[t]);
            }
        }
    }

    for (auto [i, f] : ans) {
        cout << f << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}