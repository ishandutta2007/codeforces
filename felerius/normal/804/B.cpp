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

array<uint32_t, 1'000'000> f;

uint32_t MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    f[0] = 1;
    for (size_t i = 1; i < f.size(); ++i) {
        f[i] = (f[i - 1] * 2 + 1) % MOD;
    }

    auto it = begin(s);
    while (it != end(s) && *it == 'b') {
        ++it;
    }

    uint32_t total = 0;
    uint64_t a = 0;
    while (it != end(s)) {
        uint64_t b = 0;
        while (it != end(s) && *it == 'a') {
            ++a;
            ++it;
        }
        while (it != end(s) && *it == 'b') {
            ++b;
            ++it;
        }

        total = (total + (f[a - 1] * b)) % MOD;
    }

    cout << total << '\n';

    return 0;
}