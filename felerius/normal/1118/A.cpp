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
    ios_base::sync_with_stdio(false);

    size_t q;
    cin >> q;

    while (q--) {
        uint64_t n;
        uint32_t a, b;
        cin >> n >> a >> b;
        if (b < 2 * a) {
            cout << (b * (n / 2) + a * (n % 2)) << '\n';
        } else {
            cout << (n * a) << '\n';
        }
    }

    return 0;
}