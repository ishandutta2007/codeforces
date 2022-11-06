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

constexpr uint64_t MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);

    size_t n; cin >> n;
    array<array<uint64_t, 10>, 10> byl;
    array<uint64_t, 10> l = {0};
    array<uint64_t, 10> zero = {0};
    byl.fill(zero);

    for (size_t i = 0; i < n; ++i) {
        uint32_t ai;
        cin >> ai;
        auto aii = ai;
        size_t j = 0;
        while (aii > 9) {
            aii /= 10;
            j++;
        }

        l[j]++;
        size_t k = 0;
        while (ai > 0) {
            byl[j][k] += ai % 10;
            ai /= 10;
            ++k;
        }
    }

    uint64_t res = 0;
    for (size_t l1 = 0; l1 < 10; ++l1) {
        for (size_t l2 = 0; l2 < 10; ++l2) {
            uint64_t base = 1;
            for (size_t i = 0; i <= max(l1, l2); ++i) {
                if (i <= l1) {
                    res += l[l2] * ((byl[l1][i] * base) % MOD);
                    res %= MOD;
                    base *= 10;
                    base %= MOD;
                }
                if (i <= l2) {
                    res += l[l1] * ((byl[l2][i] * base) % MOD);
                    res %= MOD;
                    base *= 10;
                    base %= MOD;
                }
            }
        }
    }

//    uint64_t res = 0;
//    for (auto ai : a) {
//        for (size_t dig_o = 0; dig_o < 10; ++dig_o) {
//            auto aii = ai;
//            uint64_t base = 1;
//            auto c = l[dig_o];
//            for (size_t di = 0; di <= dig_o; ++di) {
//                auto d = aii % 10;
//                aii /= 10;
//                res += c * ((d * base) % MOD);
//                res += c * ((d * base * 10) % MOD);
//                res %= MOD;
//                base *= 100;
//            }
//            for (size_t di = dig_o + 1; di < 10; ++di) {
//                auto d = aii % 10;
//                aii /= 10;
//                res += c * ((d * base) % MOD);
//                res %= MOD;
//                base *= 10;
//            }
//        }
//    }

    cout << res << '\n';

    return 0;
}