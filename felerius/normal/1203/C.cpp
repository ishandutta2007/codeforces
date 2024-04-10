#include <algorithm>
#include <array>
#include <cmath>
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

    size_t n;
    cin >> n;

    uint64_t g;
    cin >> g;
    for (size_t i = 1; i < n; ++i) {
        uint64_t a;
        cin >> a;
        g = gcd(g, a);
    }

    uint64_t s = sqrt(g);
    uint64_t c = 0;
    for (uint64_t i = 1; i < min(s + 1, g); ++i) {
        if (g % i == 0) {
            c += 2;
            if (i * i == g) {
                --c;
            }
        }
    }

    cout << (g == 1 ? 1 : c) << '\n';

    return 0;
}