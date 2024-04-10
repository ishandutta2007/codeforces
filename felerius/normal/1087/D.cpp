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
    std::ios_base::sync_with_stdio(false);

    size_t n;
    uint32_t s;
    cin >> n >> s;

    vector<size_t> adjacency_size(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t a, b;
        cin >> a >> b;
        a--;
        b--;
        adjacency_size[a]++;
        adjacency_size[b]++;
    }

    size_t num_leaves = 0;
    for (const auto& size : adjacency_size) {
        if (size == 1) {
            num_leaves += 1;
        }
    }

    cout.precision(20);
    if (num_leaves == n) {
        cout << (double)s << '\n';
    } else {
        cout << (2.0 * (double)s / (double)num_leaves) << '\n';
    }

    return 0;
}