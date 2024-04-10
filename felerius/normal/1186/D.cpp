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
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    auto delta = 0.0;
    for (size_t i = 0; i < n; ++i) {
        double a;
        cin >> a;
        auto b = delta >= 0 ? floor(a) : ceil(a);
        cout << (int)b << '\n';
        delta += b - a;
    }

    return 0;
}