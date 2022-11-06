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

    size_t n;
    cin >> n;

    vector<int64_t> a(n);
    cin >> a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    auto sum_total = a.back();
    if (sum_total % 3 != 0 || n < 3) {
        cout << "0\n";
        return 0;
    }

    auto partsum = sum_total / 3;

    vector<size_t> split2;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 2 * partsum) {
            split2.emplace_back(i);
        }
    }

    uint64_t count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == partsum) {
            auto it = upper_bound(begin(split2), end(split2), i);
            count += split2.size() - (it - split2.begin());
        }
    }

    cout << count << '\n';

    return 0;
}