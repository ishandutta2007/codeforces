#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 74 (Rated for Div. 2) (https://codeforces.com/contest/1238)
// Problem: B: Kill `Em All (https://codeforces.com/contest/1238/problem/B)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n, r; cin >> n >> r;
        vector<int> x(n);
        for (auto& xi : x) cin >> xi;
        sort(begin(x), end(x));
        int z = 0;
        int c = 0;
        while (!x.empty() && x.back() > z) {
            ++c;
            auto e = x.back();
            while (!x.empty() && x.back() == e)
                x.pop_back();
            z += r;
        }

        cout << c << '\n';
    }

    return 0;
}