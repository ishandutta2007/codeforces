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
    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    uint64_t res = 0;
    for (auto ai : a) {
        uint64_t base = 1;
        for (size_t di = 0; di < 10; ++di) {
            auto d = ai % 10;
            ai /= 10;
            res += n * ((d * base) % MOD);
            res += n * ((d * base * 10) % MOD);
            res %= MOD;
            base *= 100;
        }
    }

    cout << res << '\n';

    return 0;
}