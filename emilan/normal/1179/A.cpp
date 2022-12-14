#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    deque<int> d(n);
    for (int &x : d) cin >> x;

    int Max = *max_element(d.begin(), d.end());
    vector<pair<int, int>> ans;
    while (d[0] != Max) {
        ans.emplace_back(d[0], d[1]);
        int b = max(d[0], d[1]);
        int s = min(d[0], d[1]);

        d.pop_front();
        d.pop_front();
        d.push_front(b);
        d.push_back(s);
    }

    while (q--) {
        ll i;
        cin >> i;

        ll sz = ans.size();
        if (i <= sz) {
            auto [x, y] = ans[i - 1];
            cout << x << ' ' << y << '\n';
        } else {
            cout << d[0] << ' ' << d[(i - sz - 1) % (n - 1) + 1] << '\n';
        }
    }
}