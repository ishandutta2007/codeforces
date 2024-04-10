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

static constexpr uint32_t MAX_SQRT = 3162278;

bool is_perfect(uint64_t num) {
    auto sqrt = (uint64_t)std::sqrt(num);
    return sqrt * sqrt == num;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<uint64_t> even(n / 2);
    for (size_t i = 0; i < n / 2; ++i) {
        cin >> even[i];
    }

    vector<uint64_t> odd(n / 2);
    uint64_t sum = 0;
    uint64_t sqrt = 1;
    for (size_t i = 0; i < n / 2; ++i) {
        auto old_sqrt = sqrt;
        while (!is_perfect(sqrt * sqrt + even[i])) {
            ++sqrt;
            if (sqrt - old_sqrt >= MAX_SQRT) {
                cout << "No\n";
                return 0;
            }
        }

        odd[i] = sqrt * sqrt - sum;
        sum = sqrt * sqrt + even[i];

        old_sqrt = sqrt;
        while (sqrt * sqrt <= sum) {
            ++sqrt;
            if (sqrt - old_sqrt >= MAX_SQRT) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
    cout << odd[0] << ' ' << even[0];
    for (size_t i = 1; i < n / 2; ++i) {
        cout << ' ' << odd[i] << ' ' << even[i];
    }

    cout << '\n';

    return 0;
}