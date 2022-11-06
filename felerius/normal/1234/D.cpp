#include <bits/stdc++.h>

// Contest: Codeforces Round #590 (Div. 3) (https://codeforces.com/contest/1234)
// Problem: D: Distinct Characters Queries (https://codeforces.com/contest/1234/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

struct Bit {
    vector<int> b;

    Bit() = default;
    explicit Bit(size_t n) : b(n) {}

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += b[r];
        return ret;
    }

    void add(size_t idx, int val) {
        for (; idx < b.size(); idx = idx | (idx + 1))
            b[idx] += val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    auto n = s.size();

    array<Bit, 26> bits;
    for (auto& bit : bits)
        bit = Bit(n);

    for (int i = 0; i < n; ++i)
        bits[s[i] - 'a'].add(i, 1);

    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int pos; char c; cin >> pos >> c; --pos;
            bits[s[pos] - 'a'].add(pos, -1);
            s[pos] = c;
            bits[c - 'a'].add(pos, 1);
        } else {
            int l, r; cin >> l >> r; --l; --r;
            int c = 0;
            for (int i = 0; i < 26; ++i)
                c += (bits[i].sum(r) - (l == 0 ? 0 : bits[i].sum(l - 1))) > 0;
            cout << c << '\n';
        }
    }

    return 0;
}