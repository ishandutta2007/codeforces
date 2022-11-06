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

    string s;
    while (q--) {
        size_t n, k;
        cin >> n >> k >> s;

        array<vector<int>, 3> b;
        b.fill(vector<int>(n));

        for (size_t i = 0; i < n; ++i) {
            auto c = s[i];
            auto v = (c == 'R' ? 0 : (c == 'G' ? 1 : 2));
            b[0][i] = (i % 3) == v;
            b[1][i] = ((i + 1) % 3) == v;
            b[2][i] = ((i + 2) % 3) == v;
        }

        for (auto& bi : b) {
            for (size_t i = 1; i < n; ++i) {
                bi[i] += bi[i - 1];
            }
        }

        int max = 0;
        for (auto& bi : b) {
            for (size_t i = 0; i < n; ++i) {
                int v = bi[i];
                if (i >= k) {
                    v -= bi[i - k];
                }
                max = std::max(max, v);
            }
        }

        cout << (k - max) << '\n';
    }

    return 0;
}