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

    uint32_t w, h, w1, h1, w2, h2;
    cin >> w >> h >> w1 >> h1 >> w2 >> h2;

    while (h > 0) {
        w += h;
        if (h == h1) {
            w = w1 > w ? 0 : w - w1;
        }
        if (h == h2) {
            w = w2 > w ? 0 : w - w2;
        }

        h--;
    }

    cout << w << '\n';

    return 0;
}