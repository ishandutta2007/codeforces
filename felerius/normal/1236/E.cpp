#include <bits/stdc++.h>

// Contest: Codeforces Round #593 (Div. 2) (https://codeforces.com/contest/1236)
// Problem: E: Alice and the Unfair Game (https://codeforces.com/contest/1236/problem/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (auto& ai : a) cin >> ai, --ai;

    if (n == 1) {
        cout << "0\n";
        return 0;
    }

    vector<pair<int, int>> range(n);

    map<int, pair<int,int>> state;
    for (int i = 0; i < n; ++i)
        state[i] = {i, 1};
    for (int i = 0; i < m; ++i) {
        auto val = a[m - 1 - i] - i - 1;
        auto it = state.find(val);
        if (it == end(state))
            continue;
        auto it2 = state.find(it->first - 1);
        if (it2 == end(state))
            state[it->first - 1] = it->second;
        else
            state[it->first - 1].second += it->second.second;
        state.erase(it);
    }
    for (auto [k, p] : state) {
        auto [first, c] = p;
        for (int i = 0; i < c; ++i)
            range[first + i].second = min(n - 1, k + m + 1);
    }

    state.clear();
    for (int i = 0; i < n; ++i)
        state[i] = {i, 1};
    for (int i = 0; i < m; ++i) {
        auto val = a[m - 1 - i] + i + 1;
        auto it = state.find(val);
        if (it == end(state))
            continue;
        auto it2 = state.find(it->first + 1);
        if (it2 == end(state))
            state[it->first + 1] = it->second;
        else
            it2->second = {it->second.first, it->second.second + it2->second.second};
        state.erase(it);
    }
    for (auto [k, p] : state) {
        auto [first, c] = p;
        for (int i = 0; i < c; ++i)
            range[first + i].first = max(0, k - m - 1);
    }

    ll res = 0;
    for (int i = 0; i < n; ++i)
        res += range[i].second - range[i].first + 1;

    cout << res << '\n';
    return 0;
}