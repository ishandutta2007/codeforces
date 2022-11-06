#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>

using namespace std;

uint32_t floor_log2(uint32_t i) {
    // Works for everything but 0
    return sizeof(unsigned long) * 8 - 1 - __builtin_clzl(i);
}

bool is_pow2(uint32_t i) {
    return (i & ~(i - 1)) == 0;
}

uint32_t ceil_log2(uint32_t i) {
    return floor_log2(i) + !is_pow2(i);
}

void init_segtree(vector<int>& segtree, size_t node, size_t l, size_t r, const vector<int>& a) {
    if (l + 1 == r) {
        segtree[node] = a[l];
        return;
    }

    auto mid = (l + r + 1) / 2;
    init_segtree(segtree, 2 * node + 1, l, mid, a);
    init_segtree(segtree, 2 * node + 2, mid, r, a);
    segtree[node] = min(segtree[2 * node + 1], segtree[2 * node + 2]);
}

const int NO_MIN = 1'000'000'000;

int query_segtree(vector<int>& segtree, size_t node, size_t l, size_t r, size_t ql, size_t qr) {
    if (qr <= l || r <= ql) {
        return NO_MIN;
    }
    if (ql <= l && r <= qr) {
        return segtree[node];
    }

    auto mid = (l + r + 1) / 2;
    auto lmin = query_segtree(segtree, 2 * node + 1, l, mid, ql, qr);
    auto rmin = query_segtree(segtree, 2 * node + 2, mid, r, ql, qr);
    return min(lmin, rmin);
}

void remove_segtree(vector<int>& segtree, size_t node, size_t l, size_t r, size_t index) {
    if (l + 1 == r) {
        segtree[node] = NO_MIN;
        return;
    }

    auto mid = (l + r + 1) / 2;
    if (index < mid) {
        remove_segtree(segtree, 2 * node + 1, l, mid, index);
    } else {
        remove_segtree(segtree, 2 * node + 2, mid, r, index);
    }

    segtree[node] = min(segtree[2 * node + 1], segtree[2 * node + 2]);
}

bool handle_query() {
    size_t n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> b[i];
    }

    auto ceil_log2_n = ceil_log2(n);
    vector<int> segtree(16 * (1u << ceil_log2_n));
    init_segtree(segtree, 0, 0, n, a);

    set<pair<int, size_t>> rem;
    for (size_t i = 0; i < n; ++i) {
        rem.insert(pair(a[i], i));
    }

    for (size_t i = 0; i < n; ++i) {
        auto it = rem.lower_bound(pair(b[i], 0));
        if (it == end(rem) || it->first != b[i]) {
            return false;
        }

        auto idx = it->second;
        auto min = query_segtree(segtree, 0, 0, n, 0, idx);
        if (min < b[i]) {
            return false;
        }

        rem.erase(it);
        remove_segtree(segtree, 0, 0, n, idx);
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);

    size_t t;
    cin >> t;
    while (t--) {
        if (handle_query()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}