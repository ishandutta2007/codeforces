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

    string s;
    cin >> s;

    auto n = s.size();
    vector<uint8_t> rad(n);
    for (size_t i = 0; i < n; ++i) {
        for (size_t r = 1; r <= 4 && r <= i && i + r < n; ++r) {
            if (s[i - r] == s[i] && s[i] == s[i + r]) {
                rad[i] = r;
                break;
            }
        }
    }

    uint64_t count = 0;
    for (size_t l = 0; l < n; ++l) {
        size_t min_r = l + 100;
        for (size_t i = 0; i <= 8 && l + i < n; ++i) {
            if (rad[l + i] != 0 && rad[l + i] <= i && l + i + rad[l + i] < n) {
                min_r = min(min_r, l + i + rad[l + i]);
            }
        }

        if (min_r < l + 100) {
            count += n - min_r;
        }
    }

    cout << count << '\n';

    return 0;
}