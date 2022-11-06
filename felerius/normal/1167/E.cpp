#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <tuple>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

namespace io {
    struct IO {
        array<char, 10 * 1024 * 1024> buffer;
        char *ptr;

        IO() {
            read(STDIN_FILENO, &buffer, buffer.size());
            ptr = &buffer[0];
        }

        template<class T>
        T read_unsigned() {
            T t = 0;
            while (*ptr >= '0') {
                t = t * 10 + (*ptr++ & 0xF);
            }

            ++ptr;
            return t;
        }

        template<class T>
        T read_signed() {
            T t = 0;
            if (*ptr == '-') {
                ++ptr;
                while (*ptr >= '0') {
                    t = t * 10 - (*ptr++ & 0xF);
                }
            } else {
                while (*ptr >= '0') {
                    t = t * 10 + (*ptr++ & 0xF);
                }
            }

            ++ptr;
            return t;
        }
    };

    static IO io;


#define MAKE_UREAD(BITS) uint ## BITS ## _t readu ## BITS () { return io.read_unsigned<uint ## BITS ## _t>(); }
#define MAKE_IREAD(BITS) int ## BITS ## _t readi ## BITS () { return io.read_signed<int ## BITS ## _t>(); }
#define MAKE_READ(BITS) MAKE_UREAD(BITS) MAKE_IREAD(BITS)

    MAKE_READ(8)

    MAKE_READ(16)

    MAKE_READ(32)

    MAKE_READ(64)

#undef MAKE_UREAD
#undef MAKE_IREAD
#undef MAKE_READ

    size_t readsize() {
        return io.read_unsigned<size_t>();
    }
}

using namespace io;

int main() {
    size_t n = readsize();
    uint32_t x = readu32();

    vector<pair<int32_t, int32_t>> all_ranges(x + 1, {-1, -1});
    for (size_t i = 0; i < n; ++i) {
        uint32_t a = readu32();
        if (all_ranges[a].first == -1) {
            all_ranges[a] = {i, i};
        } else {
            all_ranges[a].second = i;
        }
    }

    vector<tuple<uint32_t, size_t, size_t>> ranges;
    for (size_t i = 0; i <= x; ++i) {
        if (all_ranges[i].first != -1) {
            ranges.emplace_back(i, all_ranges[i].first, all_ranges[i].second);
        }
    }

    uint32_t max_low_num = get<0>(ranges[0]);
    for (size_t i = 1; i < ranges.size(); ++i) {
        if (get<2>(ranges[i - 1]) < get<1>(ranges[i])) {
            max_low_num = get<0>(ranges[i]);
        } else {
            max_low_num = get<0>(ranges[i]) - 1;
            break;
        }
    }

    uint32_t min_high_num = get<0>(ranges.back());
    for (int i = ranges.size() - 2; i >= 0; --i) {
        if (get<1>(ranges[i + 1]) > get<2>(ranges[i])) {
            min_high_num = get<0>(ranges[i]);
        } else {
            min_high_num = get<0>(ranges[i]) + 1;
            break;
        }
    }

    if (max_low_num == get<0>(ranges.back())) {
        max_low_num = x;
        min_high_num = 1;
    }

    vector<int> last_smalleq(x + 1);
    vector<int> earlier_bigeq(x + 2);
    last_smalleq[0] = -1;
    earlier_bigeq[x + 1] = n;

    for (size_t i = 1; i <= x; ++i) {
        if (all_ranges[i].first == -1) {
            last_smalleq[i] = last_smalleq[i - 1];
        } else {
            last_smalleq[i] = max(last_smalleq[i - 1], all_ranges[i].second);
        }
    }

    for (int i = x; i >= 0; --i) {
        if (all_ranges[i].first == -1) {
            earlier_bigeq[i] = earlier_bigeq[i + 1];
        } else {
            earlier_bigeq[i] = min(earlier_bigeq[i + 1], all_ranges[i].first);
        }
    }

    uint64_t count = 0;
#if false
    cerr << "max_low_num = " << max_low_num << ", min_high_num = " << min_high_num << '\n';
#endif
    uint32_t r = min_high_num - 1;
    for (uint32_t l = 1; l <= min(max_low_num + 1, x); ++l) {
        r = max(l, r);
        while (last_smalleq[l - 1] > earlier_bigeq[r + 1]) {
            r++;
        }

        count += x - r + 1;
#if false
        cerr << "l = " << l << ": r >= " << r << '\n';
#endif
    }

    cout << count << '\n';

    return 0;
}