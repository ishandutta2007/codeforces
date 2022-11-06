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

size_t n;
array<int, 100000> bit = {0};

int bit_sum(size_t i) {
    int ret = 0;
    for (int idx = (int)i; idx >= 0; idx = (idx & (idx + 1)) - 1)
        ret += bit[(size_t)idx];
    return ret;
}

int bit_get(size_t i) {
    return bit_sum(i) - (i == 0 ? 0 : bit_sum(i - 1));
}

int bit_range(size_t a, size_t b) {
    if (a > b) {
        swap(a, b);
    }

    int ret = bit_sum(b);
    if (a > 0) {
        ret -= bit_sum(a - 1);
    }

    return ret;
}

void bit_add(size_t i, int val) {
    for (; i < n; i |= i + 1)
        bit[i] += val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t q;
    cin >> n >> q;

    for (size_t i = 0; i < n; ++i) {
        bit_add(i, 1);
    }

    size_t offset = 0;
    size_t width = n;
    bool inverse = false;
    auto idx = [&](size_t i) {
        return inverse ? offset + width - 1 - i : offset + i;
    };
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            size_t fold;
            cin >> fold;
            if (fold > width / 2) {
                for (size_t i = 0; i < width - fold; ++i) {
                    auto v = bit_get(idx(fold + i));
                    bit_add(idx(fold + i), -v);
                    bit_add(idx(fold - i - 1), v);
                }

                if (inverse) {
                    offset += width - fold;
                }
                width = fold;
                inverse = !inverse;
            } else {
                for (size_t i = 0; i < fold; ++i) {
                    auto v = bit_get(idx(fold - i - 1));
                    bit_add(idx(fold - i - 1), -v);
                    bit_add(idx(fold + i), v);
                }

                if (!inverse) {
                    offset += fold;
                }
                width -= fold;
            }
        } else {
            size_t l, r;
            cin >> l >> r;
            cout << bit_range(idx(r - 1), idx(l)) << '\n';
        }
    }

    return 0;
}