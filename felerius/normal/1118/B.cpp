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

    size_t n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }

    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<uint32_t> sum_even = {a[0], a[0]};
    vector<uint32_t> sum_odd = {0, a[1]};
    for (size_t i = 2; i < n; ++i) {
        if (i % 2 == 0) {
            sum_even.emplace_back(sum_even.back() + a[i]);
            sum_odd.emplace_back(sum_odd.back());
        } else {
            sum_odd.emplace_back(sum_odd.back() + a[i]);
            sum_even.emplace_back(sum_even.back());
        }
    }

    size_t nice = 0;
    for (size_t i = 0; i < n; ++i) {
        auto sum_even_front = i == 0 ? 0 : sum_even[i - 1];
        auto sum_odd_front = i == 0 ? 0 : sum_odd[i - 1];
        auto sum_even_back = sum_odd.back() - sum_odd[i];
        auto sum_odd_back = sum_even.back() - sum_even[i];
        if (sum_even_front + sum_even_back == sum_odd_front + sum_odd_back) {
            ++nice;
        }
    }

    cout << nice << '\n';

    return 0;
}