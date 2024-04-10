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

    size_t n, k;
    cin >> n >> k;

    vector<int> diffs(n - 1);
    int prev;
    cin >> prev;
    for (size_t i = 1; i < n; ++i) {
        int a;
        cin >> a;
        diffs[i - 1] = abs(a - prev);
        prev = a;
    }

    sort(begin(diffs), end(diffs), greater{});
    cout << accumulate(begin(diffs) + (k - 1), end(diffs), (int64_t)0) << '\n';

    return 0;
}