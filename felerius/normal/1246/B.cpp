#include <bits/stdc++.h>

// Contest: Codeforces Round #596 (Div. 1, based on Technocup 2020 Elimination Round 2) (https://codeforces.com/contest/1246)
// Problem: B: Power Products (https://codeforces.com/contest/1246/problem/B)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

array<int, 100'001> sieve;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < sieve.size(); ++i) {
        if (sieve[i])
            continue;
        for (int j = i; j < sieve.size(); j += i)
            if (!sieve[j])
                sieve[j] = i;
    }

    int n, k; cin >> n >> k;
    ll c = 0;
    map<vector<pair<int, int>>, int> m;
    vector<int> f;
    for (int i = 0; i < n; ++i) {
        int ai; cin >> ai;
        f.clear();
        while (ai > 1) {
            f.push_back(sieve[ai]);
            ai /= sieve[ai];
        }
        sort(begin(f), end(f));

        vector<pair<int, int>> fa;
        for (auto fi : f) {
            if (!fa.empty() && fa.back().first == fi)
                fa.back().second++;
            else
                fa.emplace_back(fi, 1);
        }

        for (auto& [_, c] : fa)
            c %= k;
        fa.erase(remove_if(begin(fa), end(fa), [](auto& p) {
            return p.second == 0;
        }), end(fa));

        vector<pair<int, int>> inv;
        for (auto [fi, c] : fa)
            inv.emplace_back(fi, k - c);
        auto it = m.find(inv);
        c += it == end(m) ? 0 : it->second;

        m[fa]++;
    }

    cout << c << '\n';
    return 0;
}