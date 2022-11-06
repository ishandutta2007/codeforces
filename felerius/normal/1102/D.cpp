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

template <class Iter>
void replace_iter(char c_old, char c_new, size_t count, Iter iter) {
    while (count > 0) {
        if (*iter == c_old) {
            *iter = c_new;
            --count;
        }

        ++iter;
    }
}

void replace(char c_old, char c_new, size_t count, vector<char>& s) {
    if (c_old < c_new) {
        replace_iter(c_old, c_new, count, s.rbegin());
    } else {
        replace_iter(c_old, c_new, count, s.begin());
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<char> s(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> s[i];
    }

    size_t counts[3] = {0};
    for (auto c : s) {
        counts[c - '0']++;
    }

    auto num_low = (int)(counts[0] < n/3) + (int)(counts[1] < n/3) + (int)(counts[2] < n/3);
    if (num_low == 1) {
        auto c_low = counts[0] < n/3 ? '0' : (counts[1] < n/3 ? '1' : '2');
        for (auto c : {'0', '1', '2'}) {
            if (c != c_low) {
                replace(c, c_low, counts[c - '0'] - n/3, s);
            }
        }
    } else if (num_low == 2) {
        auto c_high = counts[0] > n/3 ? '0' : (counts[1] > n/3 ? '1' : '2');
        auto a = c_high == '0' ? std::vector<char>{'2', '1'} : std::vector<char>{'0', '1', '2'};
        for (auto c : a) {
            if (c != c_high) {
                replace(c_high, c, n / 3 - counts[c - '0'], s);
            }
        }
    }

    for (auto c : s) {
        cout << c;
    }

    cout << '\n';

    return 0;
}