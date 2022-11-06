#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

vector<uint32_t> build_almost_balanced(size_t b, size_t n) {
    vector<uint32_t> levels = {1};
    --n;
    while (n >= levels.back() * b) {
        levels.emplace_back(levels.back() * b);
        n -= levels.back();
    }

    levels.emplace_back(n);
    return levels;
}

uint64_t min_s(size_t b, size_t n) {
    auto levels = build_almost_balanced(b, n);
    uint64_t s = 0;
    for (size_t i = 0; i < levels.size(); ++i) {
        s += (i + 1) * static_cast<uint64_t>(levels[i]);
    }

    return s;
}

size_t binary_search(size_t min_b, size_t max_b, size_t n, uint64_t s) {
    if (min_b == max_b) {
        return min_b;
    }

    auto mid_b = (min_b + max_b) / 2;
    if (min_s(mid_b, n) > s) {
        return binary_search(mid_b + 1, max_b, n, s);
    } else {
        return binary_search(min_b, mid_b, n, s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    uint64_t n;
    uint64_t s;
    cin >> n >> s;

    if (s < 2 * n - 1 || s > (n*n + n) / 2) {
        cout << "No\n";
        return 0;
    }

    auto b = binary_search(1, n - 1, n, s);
    auto tree = build_almost_balanced(b, n);
    s -= min_s(b, n);
    size_t l = tree.size() - 1;
    while (s > 0) {
        if (tree[l] == 1) {
            --l;
        }

        auto diff = tree.size() - l;
        if (diff > s) {
            tree[l]--;
            tree[l + s]++;
            break;
        } else {
            tree[l]--;
            tree.emplace_back(1);
            s -= diff;
        }
    }

    cout << "Yes\n";
    size_t left_above = 0;
    for (size_t i = 1; i < tree.size(); ++i) {
        for (size_t j = 0; j < tree[i]; ++j) {
            cout << (left_above + j / b + 1) << ' ';
        }

        left_above += tree[i - 1];
    }

    return 0;
}