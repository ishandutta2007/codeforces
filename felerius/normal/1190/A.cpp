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

int main() {
    ios::sync_with_stdio(false);

    uint64_t n, m, k;
    cin >> n >> m >> k;

    vector<uint64_t> p(m);
    for (size_t i = 0; i < m; ++i) {
        cin >>  p[i];
    }

    uint64_t base = 0;
    size_t num_removed = 0;
    uint64_t num_ops = 0;
    while (base < p.back()) {
        auto max_base = p[num_removed] - 1;
        base += ((max_base - base) / k) * k;
        auto len = k;
        while (true) {
            auto it = upper_bound(begin(p) + num_removed, end(p), base + len);
            if (it == end(p)) {
                num_removed = m;
                num_ops++;
                break;
            }
            if (it == begin(p) + num_removed) {
                break;
            }

            auto removed = it - (begin(p) + num_removed);
            num_removed += removed;
            len += removed;
            num_ops++;
        }

        base += len;
    }

    cout << num_ops << '\n';

    return 0;
}