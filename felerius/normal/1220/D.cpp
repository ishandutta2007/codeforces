#include <bits/stdc++.h>

// Contest: Codeforces Round #586 (Div. 1 + Div. 2) (https://codeforces.com/contest/1220)
// Problem: D: Alex and Julian (https://codeforces.com/contest/1220/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    array<vector<ll>, 65> c;

    for (int i = 0; i < n; ++i) {
        ll b; cin >> b;
        int c2 = 0;
        auto b2 = b;
        while (b2 % 2 == 0) {
            b2 /= 2;
            ++c2;
        }

        c[c2].push_back(b);
    }

    int mx = 0, im = 0;
    for (int i = 0; i < 64; ++i)
        if (c[i].size() > mx) {
            mx = c[i].size();
            im = i;
        }

    cout << (n - mx) << '\n';
    for (int i = 0; i < 64; ++i) {
        if (i == im)
            continue;
        for (auto j : c[i])
            cout << j << ' ';
    }
    cout << '\n';

    return 0;
}