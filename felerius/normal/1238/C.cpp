#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 74 (Rated for Div. 2) (https://codeforces.com/contest/1238)
// Problem: C: Standard Free2play (https://codeforces.com/contest/1238/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int h, n; cin >> h >> n;
        vector<int> p(n);
        for (auto& pi : p) cin >> pi;
        p.push_back(0);
        p.push_back(-1);
        reverse(begin(p), end(p));
        int res = 0;
        while (p.back() > 0) {
            auto cur = p.back(); p.pop_back();
            if (p.back() == cur - 1) {
                p.pop_back();
                if (p.back() < cur - 2) {
                    res++;
                    p.push_back(p.back() + 1);
                }
            } else {
                p.push_back(p.back() + 1);
            }
        }

        cout << res << '\n';
    }

    return 0;
}