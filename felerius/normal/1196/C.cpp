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
        size_t n;
        cin >> n;

        int min_x = -100000;
        int max_x = 100000;
        int min_y = -100000;
        int max_y = 100000;
        for (size_t i = 0; i < n; ++i) {
            int x, y, f1, f2, f3, f4;
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;
            if (!f1) {
                min_x = max(min_x, x);
            }
            if (!f2) {
                max_y = min(max_y, y);
            }
            if (!f3) {
                max_x = min(max_x, x);
            }
            if (!f4) {
                min_y = max(min_y, y);
            }
        }

        if (min_x <= max_x && min_y <= max_y) {
            cout << 1 << ' ' << min_x << ' ' << min_y << '\n';
        } else {
            cout << "0\n";
        }
    }

    return 0;
}