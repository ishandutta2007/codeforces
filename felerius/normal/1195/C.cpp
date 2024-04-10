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

    vector<int> h1(n);
    vector<int> h2(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> h1[i];
    }
    for (size_t i = 0; i < n; ++i) {
        cin >> h2[i];
    }

    vector<array<int64_t, 2>> dp(n);
    dp[0] = {h1[0], h2[0]};

    array<int64_t, 2> ma = dp[0];
    for (size_t i = 1; i < n; ++i) {
        dp[i][0] = h1[i] + ma[1];
        dp[i][1] = h2[i] + ma[0];
        ma[0] = max(ma[0], dp[i][0]);
        ma[1] = max(ma[1], dp[i][1]);
    }

    cout << max(ma[0], ma[1]) << '\n';

    return 0;
}