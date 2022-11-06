#include <bits/stdc++.h>

// Contest: Codeforces Round #595 (Div. 3) (https://codeforces.com/contest/1249)
// Problem: D2: Too Many Segments (hard version) (https://codeforces.com/contest/1249/problem/D2)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<pair<int, int>> seg(n);
    for (auto& [a, b] : seg) cin >> a >> b;
    vector<tuple<int, bool, int>> evt;
    for (int i = 0; i < n; ++i) {
        evt.emplace_back(seg[i].first, false, i);
        evt.emplace_back(seg[i].second, true, i);
    }
    sort(begin(evt), end(evt));

    set<pair<int, int>> act;
    int cur = 0;
    vector<int> rem;
    for (auto [x, t, i] : evt) {
        if (t) {
            cur -= act.erase(pair(x, i));
            continue;
        }
        act.emplace(seg[i].second, i);
        ++cur;
        if (cur > k) {
            auto it = prev(end(act));
            rem.emplace_back(it->second);
            act.erase(it);
            --cur;
        }
    }

    cout << rem.size() << '\n';
    for (auto i : rem)
        cout << (i + 1) << ' ';
    cout << '\n';

    return 0;
}