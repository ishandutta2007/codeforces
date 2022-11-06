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

template <class T, size_t Size>
struct Matrix {
    array<T, Size * Size> data = {0};

    T& operator()(size_t x, size_t y) {
        return data[y * Size + x];
    }
};

int main() {
    ios::sync_with_stdio(false);

    const uint64_t impos = 1'000'000'000;
    Matrix<array<uint64_t, 10>, 10> decomp;
    for (size_t x = 0; x < 10; ++x) {
        for (size_t y = x; y < 10; ++y) {
            auto& ent = decomp(x, y);
            ent.fill(impos);
            ent[x] = 0;
            ent[y] = 0;
            for (size_t i = 0; i < 10; ++i) {
                for (size_t j = 0; j < 10; ++j) {
                    if (ent[j] != impos) {
                        ent[(j + x) % 10] = min(ent[(j + x) % 10], ent[j] + 1);
                        ent[(j + y) % 10] = min(ent[(j + y) % 10], ent[j] + 1);
                    }
                }
            }

            decomp(y, x) = ent;
        }
    }

    string s;
    cin >> s;

    Matrix<uint64_t, 10> r;
    for (size_t i = 1; i < s.size(); ++i) {
        size_t diff = ((size_t)s[i] + 10 - (size_t)s[i - 1]) % 10;
        for (size_t x = 0; x < 10; ++x) {
            for (size_t y = x; y < 10; ++y) {
                r(x, y) += decomp(x, y)[diff];
            }
        }
    }

    for (size_t x = 0; x < 10; ++x) {
        for (size_t y = x; y < 10; ++y) {
            r(y, x) = r(x, y);
        }
    }

    for (size_t x = 0; x < 10; ++x) {
        for (size_t y = 0; y < 10; ++y) {
            if (r(x, y) >= impos) {
                cout << "-1 ";
            } else {
                cout << r(x, y) << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}