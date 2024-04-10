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

    array<vector<size_t>, 6> occ;
    for (size_t i = 0; i < n; ++i) {
        int num;
        cin >> num;
        switch (num) {
            case 4:
                occ[0].emplace_back(i);
                break;
            case 8:
                occ[1].emplace_back(i);
                break;
            case 15:
                occ[2].emplace_back(i);
                break;
            case 16:
                occ[3].emplace_back(i);
                break;
            case 23:
                occ[4].emplace_back(i);
                break;
            case 42:
                occ[5].emplace_back(i);
                break;
        }
    }

    auto max_len = min({
                               occ[0].size(),
                               occ[1].size(),
                               occ[2].size(),
                               occ[3].size(),
                               occ[4].size(),
                               occ[5].size(),
                       });

    if (max_len == 0) {
        cout << n << '\n';
        return 0;
    }

    array<size_t, 6> index = {0};
    size_t num = 0;
    size_t finished = 0;
    for (; num < max_len; ++num) {
        bool end = false;
        for (size_t i = 1; i < 6; ++i) {
            while (index[i] < occ[i].size() && occ[i][index[i]] < occ[i - 1][index[i - 1]]) {
                ++index[i];
            }

            if (index[i] >= occ[i].size()) {
                end = true;
                break;
            }
        }

        if (end) {
            break;
        }

        for (size_t i = 0; i < 6; ++i) {
            index[i]++;
        }
        finished++;
    }

    cout << (n - 6 * finished) << '\n';

    return 0;
}