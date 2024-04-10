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

uint64_t pages(uint32_t days, const vector<uint32_t>& a) {
    uint64_t sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (i / days > a[i]) {
            break;
        }

        sum += a[i] - i / days;
    }

    return sum;
}

uint32_t bin_search(const vector<uint32_t>& a, uint32_t m, uint32_t min_days, uint32_t max_days) {
    if (max_days - min_days <= 1) {
        auto p = pages(min_days, a);
        return p >= m ? min_days : max_days;
    }

    uint32_t mid_days = (min_days + max_days) / 2;
    if (m > pages(mid_days, a)) {
        return bin_search(a, m, mid_days, max_days);
    }

    return bin_search(a, m, min_days, mid_days);
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n, m;
    cin >> n >> m;

    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<>{});
    if (m > pages(n, a)) {
        cout << -1 << '\n';
    } else {
        cout << bin_search(a, m, 1, n) << '\n';
    }

    return 0;
}