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
#include <utility>
#include <vector>


using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    uint32_t n, k;
    string s, t;
    cin >> n >> k >> s >> t;

    uint64_t c = n;
    uint64_t used_strings = 1;
    uint64_t base_strings = 1;
    for (size_t i = 0; i < n && used_strings < k; ++i) {
        auto old_base_strings = base_strings;
        base_strings *= 2;
        if (s[i] == 'b') {
            base_strings--;
        }
        if (t[i] == 'a') {
            base_strings--;
        }

        auto new_strings = min(k - used_strings, base_strings - old_base_strings);
        c += new_strings * (n - i);

        used_strings += new_strings;
    }


//    size_t i = 1;
//    while (used_strings < k && prefix_len + i < n) {
//        base_strings *= 2;
//        if (s[prefix_len + i] == 'b') {
//            base_strings--;
//        }
//        if (t[prefix_len + i] == 'a') {
//            base_strings--;
//        }
//
//        base_strings = min(base_strings, k - used_strings);
//        c += static_cast<uint64_t>(base_strings) * (l - i);
//        used_strings += base_strings;
//        base_strings = max(base_strings, 1u);
//        ++i;
//    }

    cout << c << '\n';

    return 0;
}