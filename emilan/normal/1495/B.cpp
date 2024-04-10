#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> p{0};
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) {
            p.push_back(i);
        }
    }
    p.push_back(n - 1);

    int m = p.size();
    vector<pii> d(m);
    for (int i = 0; i < m; i++) {
        int l = p[i], r = p[i];
        for (; l && a[l - 1] < a[l]; l--);
        for (; r < n - 1 && a[r] > a[r + 1]; r++);

        d[i] = {p[i] - l, r - p[i]};
    }

    int max_dist = 0, max_cnt = 0;

    auto update = [&](int x) -> void {
        if (x > max_dist) {
            max_dist = x;
            max_cnt = 1;
        } else if (x == max_dist) {
            max_cnt++;
        }
    };

    for (auto [x, y] : d) {
        update(x);
        update(y);
    }

    int ans = -1;
    for (int i = 1; i < m - 1; i++) {
        auto [x, y] = d[i];

        if (x == y && x > ans) ans = x;
    }

    cout << (ans == max_dist && ~ans & 1 && max_cnt == 2);
}