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

static bool debug = false;

uint64_t calc(const vector<size_t>& a, uint64_t val_a, uint64_t val_b, uint64_t left, uint64_t right, size_t a_begin, size_t a_end) {
    if (a_end - a_begin == 0) {
        return val_a;
    }

    if (right - left == 1) {
        return val_b * (a_end - a_begin);
    }

    size_t mid = (right + left) / 2;
    size_t a_mid = lower_bound(a.begin() + a_begin, a.begin() + a_end, mid) - a.begin();
    auto cost_left = calc(a, val_a, val_b, left, mid, a_begin, a_mid);
    auto cost_right = calc(a, val_a, val_b, mid, right, a_mid, a_end);
    auto cost_self = val_b * (a_end - a_begin) * (right - left);
    return min(cost_self, cost_left + cost_right);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n, k;
    uint64_t val_a, val_b;
    cin >> n >> k >> val_a >> val_b;

    vector<size_t> a(k);
    for (size_t i = 0; i < k; ++i) {
        cin >> a[i];
        a[i]--;
    }

    sort(a.begin(), a.end());
    cout << calc(a, val_a, val_b, 0, (uint64_t)1 << n, 0, k) << '\n';

    return 0;
}