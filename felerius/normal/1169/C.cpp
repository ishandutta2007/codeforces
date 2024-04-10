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

bool check(const vector<uint32_t> a, uint32_t m, uint32_t p) {
    uint32_t min = 0;
    for (unsigned int i : a) {
        if (i > min) {
            if (i + p < m || (i + p) % m < min) {
                min = i;
            }
        } else if (i < min) {
            if (i + p < min) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    uint32_t m;
    cin >> n >> m;

    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    uint32_t min = 0;
    uint32_t max = m;
    while (min != max) {
        auto mid = (min + max) / 2;
        if (check(a, m, mid)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }

    cout << min << '\n';

    return 0;
}