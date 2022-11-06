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

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    multiset<uint32_t> b;
    for (size_t i = 0; i < n; ++i) {
        uint32_t l;
        cin >> l;
        b.emplace(l);
    }

    for (auto av : a) {
        auto it = b.lower_bound(n - av);
        if (it == b.end()) {
            it = b.begin();
        }

        cout << ((av + *it) % n) << ' ';
        b.erase(it);
    }

    cout << '\n';

    return 0;
}