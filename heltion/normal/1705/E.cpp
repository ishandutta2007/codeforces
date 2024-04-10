#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i += 1)
        cin >> a[i];
    set<pair<int, int>> sp;
    function<void(int)> add = [&](int u) {
        auto it = sp.upper_bound(make_pair(u, INT_MAX));
        if (it == sp.begin() or prev(it)->second < u) {
            sp.insert({u, u});
            return;
        }
        it = prev(it);
        auto p = *it;
        sp.erase(it);
        if (p.first < u) sp.insert({p.first, u - 1});
        add(p.second + 1);
    };
    function<void(int)> sub = [&](int u) {
        auto it = sp.upper_bound(make_pair(u, INT_MAX));
        if (it == sp.begin() or prev(it)->second < u) {
            assert(it != sp.end());
            auto p = *it;
            sp.erase(it);
            if (p.second > p.first) sp.insert({p.first + 1, p.second});
            sp.insert({u, p.first - 1});
            return;
        }
        it = prev(it);
        auto p = *it;
        sp.erase(it);
        if (p.first < u) sp.insert({p.first, u - 1});
        if (u < p.second) sp.insert({u + 1, p.second});
    };
    for (int i = 1; i <= n; i += 1)
        add(a[i]);
    for (int qi = 0, k, l; qi < q; qi += 1) {
        cin >> k >> l;
        sub(a[k]);
        a[k] = l;
        add(a[k]);
        cout << sp.rbegin()->second << "\n";
    }
}