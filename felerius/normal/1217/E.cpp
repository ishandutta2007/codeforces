#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <random>
#include <string>
#include <tuple>
#include <vector>

// Contest: Educational Codeforces Round 72 (Rated for Div. 2) (https://codeforces.com/contest/1217)
// Problem: E: Sum Queries? (https://codeforces.com/contest/1217/problem/E)

using namespace std;

int INF = 1'000'000'000;
int DEC[] = {1, 10, 100, 1000, 10'000, 100'000, 1'000'000, 10'000'000, 100'000'000};

struct Node {
    array<array<int, 2>, 9> agg;

    Node() {
        for (auto& row : agg)
            row.fill(INF);
    }
};

vector<Node> segtree;

void create_segtree(int idx, int l, int r, vector<int>& a) {
    if (r <= l)
        return;
    if (r - l < 2) {
        for (int i = 0; i < 9; ++i)
            if (a[l] / DEC[i] % 10 != 0)
                segtree[idx].agg[i][0] = a[l];
        return;
    }

    auto mid = (l + r) / 2;
    create_segtree(2 * idx + 1, l, mid, a);
    create_segtree(2 * idx + 2, mid, r, a);
    for (int i = 0; i < 9; ++i) {
        array<int, 4> b = {segtree[2 * idx + 1].agg[i][0], segtree[2 * idx + 1].agg[i][1],
                           segtree[2 * idx + 2].agg[i][0], segtree[2 * idx + 2].agg[i][1]};
        sort(begin(b), end(b));
        segtree[idx].agg[i] = {b[0], b[1]};
    }
}

void update_segtree(int idx, int l, int r, int pos, int new_val) {
    if (r <= l) return;

    if (r - l < 2) {
        segtree[idx] = Node();
        for (int i = 0; i < 9; ++i)
            if (new_val / DEC[i] % 10 != 0)
                segtree[idx].agg[i][0] = new_val;
        return;
    }

    auto mid = (r + l) / 2;
    if (pos < mid)
        update_segtree(2 * idx + 1, l, mid, pos, new_val);
    else
        update_segtree(2 * idx + 2, mid, r, pos, new_val);

    for (int i = 0; i < 9; ++i) {
        array<int, 4> a = {segtree[2 * idx + 1].agg[i][0], segtree[2 * idx + 1].agg[i][1],
                           segtree[2 * idx + 2].agg[i][0], segtree[2 * idx + 2].agg[i][1]};
        sort(begin(a), end(a));
        segtree[idx].agg[i] = {a[0], a[1]};
    }
}

array<array<int, 2>, 9> query_segtree(int idx, int l, int r, int ql, int qr) {
    if (qr <= l || ql >= r)
        return Node().agg;

    if (ql <= l && r <= qr)
        return segtree[idx].agg;

    auto agg = Node().agg;
    auto mid = (r + l) / 2;
    auto agg1 = query_segtree(2 * idx + 1, l, mid, ql, qr);
    auto agg2 = query_segtree(2 * idx + 2, mid, r, ql, qr);
    for (int i = 0; i < 9; ++i) {
        array<int, 4> a = {agg1[i][0], agg1[i][1], agg2[i][0], agg2[i][1]};
        sort(begin(a), end(a));
        agg[i] = {a[0], a[1]};
    }

    return agg;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto& ai : a) cin >> ai;
    segtree.resize(4 * n);
    create_segtree(0, 0, n, a);

    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int i, x; cin >> i >> x; --i;
            update_segtree(0, 0, n, i, x);
        } else {
            int l, r; cin >> l >> r; --l;
            auto agg = query_segtree(0, 0, n, l, r);
            int mn = 2 * INF;
            for (int d = 0; d < 9; ++d) {
                auto& [a, b] = agg[d];
                if (a != INF && b != INF)
                    mn = min(mn, a + b);
            }

            if (mn == 2 * INF)
                cout << "-1\n";
            else
                cout << mn << '\n';
        }
    }

    return 0;
}