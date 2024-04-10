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

    size_t q;
    cin >> q;

    while (q--) {
        size_t n, k;
        cin >> n >> k;

        uint32_t odd = 0;
        vector<size_t> odd_pos;
        for (size_t i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a % 2 == 1) {
                odd++;
                if (odd_pos.size() < (k - 1)) {
                    odd_pos.emplace_back(i);
                }
            }
        }

        if (odd >= k && (odd - k) % 2 == 0) {
            cout << "YES\n";
            for (auto i : odd_pos) {
                cout << (i + 1) << ' ';
            }
            cout << n << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}