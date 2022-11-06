#include <bits/stdc++.h>

// Contest: Codeforces Round #590 (Div. 3) (https://codeforces.com/contest/1234)
// Problem: E: Special Permutations (https://codeforces.com/contest/1234/problem/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (auto& ai : a) {
        cin >> ai; --ai;
    }

    vector<ll> s(n + 1);
    auto range_add = [&](int l, int r, int val) {
        s[l] += val;
        s[r] -= val;
    };
    for (int i = 1; i < m; ++i) {
        auto x = a[i - 1];
        auto y = a[i];
        if (x == y)
            continue;
        if (x > y)
            swap(x, y);

        range_add(0, x, y - x);
        range_add(x, x + 1, y);
        range_add(x + 1, y, y - x - 1);
        range_add(y, y + 1, x + 1);
        range_add(y + 1, n, y - x);
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += s[i];
        cout << sum << ' ';
    }
    cout << '\n';

    return 0;
}