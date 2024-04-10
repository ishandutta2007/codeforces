#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

size_t n, k;
vector<pair<int, int>> p;
multiset<pair<int, size_t>> left, bottom;
multiset<pair<int, size_t>, greater<>> right, top;
int64_t min_area = numeric_limits<int64_t>::max();

int64_t get_area() {
    int64_t dx = begin(::right)->first - begin(::left)->first;
    int64_t dy = begin(top)->first - begin(bottom)->first;
    return max(1ll, ((dx + 1) / 2)) * max(1ll, ((dy + 1) / 2));
}

void calc_best_area(size_t removed) {
    min_area = min(min_area, get_area());
    if (removed == k) {
        return;
    }

    size_t to_check[4] = {
        begin(::left)->second,
        begin(::right)->second,
        begin(bottom)->second,
        begin(top)->second,
    };

    for (auto idx : to_check) {
        bool rl = false;
        bool rr = false;
        bool rb = false;
        bool rt = false;

        auto itl = ::left.find(pair(p[idx].first, idx));
        if (itl != end(::left)) { ::left.erase(itl); rl = true; }
        auto itr = ::right.find(pair(p[idx].first, idx));
        if (itr != end(::right)) { ::right.erase(itr); rr = true; }
        auto itb = bottom.find(pair(p[idx].second, idx));
        if (itb != end(bottom)) { bottom.erase(itb); rb = true; }
        auto itt = top.find(pair(p[idx].second, idx));
        if (itt != end(top)) { top.erase(itt); rt = true; }

        calc_best_area(removed + 1);

        if (rl) { ::left.emplace(p[idx].first, idx); }
        if (rr) { ::right.emplace(p[idx].first, idx); }
        if (rb) { bottom.emplace(p[idx].second, idx); }
        if (rt) { top.emplace(p[idx].second, idx); }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;

    p.resize(n);
    vector<pair<int, size_t>> horizontal(n);
    vector<pair<int, size_t>> vertical(n);
    for (size_t i = 0; i < n; ++i) {
        int l, r, t, b;
        cin >> l >> b >> r >> t;
        int cx = r + l;
        int cy = b + t;
        horizontal[i] = {cx, i};
        vertical[i] = {cy, i};
        p[i] = {cx, cy};
    }

    sort(begin(horizontal), end(horizontal));
    sort(begin(vertical), end(vertical));

    for (size_t i = 0; i <= k; ++i) {
        ::left.emplace(horizontal[i]);
        ::right.emplace(horizontal[n - i - 1]);
        bottom.emplace(vertical[i]);
        top.emplace(vertical[n - i - 1]);
    }

    calc_best_area(0);
    cout << min_area << '\n';

    return 0;
}