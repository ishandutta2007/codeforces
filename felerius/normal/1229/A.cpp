#include <bits/stdc++.h>

// Contest: Codeforces Round #588 (Div. 1) (https://codeforces.com/contest/1229)
// Problem: A: Marcin and Training Camp (https://codeforces.com/contest/1229/problem/A)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<u64, ll>> a(n);
    for (auto& [ai, bi] : a) cin >> ai;
    for (auto& [ai, bi] : a) cin >> bi;

    sort(begin(a), end(a));
    vector<vector<int>> sub(n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if ((a[i].first & ~a[j].first) == 0)
                sub[j].emplace_back(i);

    vector<bool> taken(n);
    auto it = begin(a);
    while (it != end(a)) {
        auto it2 = it;
        while (it2 != end(a) && it->first == it2->first)
            ++it2;
        if (it2 - 1 > it) {
            for (auto it3 = it; it3 != it2; ++it3)
                taken[it3 - begin(a)] = true;
            for (auto i : sub[it - begin(a)])
                taken[i] = true;
        }
        it = it2;
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += taken[i] * a[i].second;
    cout << sum << '\n';
    return 0;
}