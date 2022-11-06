#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

array<size_t, 150005> c;
array<bool, 150005> o;

int main() {
    ios::sync_with_stdio(false);

    c.fill(0);
    o.fill(false);

    size_t n;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        uint32_t w;
        cin >> w;
        c[w]++;
    }

    for (size_t w = 1; w < c.size(); ++w) {
        if (c[w] > 0 && w > 1 && !o[w - 1]) {
            o[w - 1] = true;
            c[w]--;
        }
        if (c[w] > 0 && !o[w]) {
            o[w] = true;
            c[w]--;
        }
        if (c[w] > 0 && !o[w + 1]) {
            o[w + 1] = true;
            c[w]--;
        }
    }

    cout << accumulate(begin(o), end(o), 0) << '\n';

    return 0;
}