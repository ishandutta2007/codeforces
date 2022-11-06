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

    string s, t;
    cin >> s >> t;

    vector<size_t> posfront;
    auto it = begin(s);
    for (auto c : t) {
        while (*it != c) {
            ++it;
        }

        posfront.emplace_back(it - begin(s));
        ++it;
    }

    vector<size_t> posback(t.size());
    it = prev(end(s));
    for (int i = t.size() - 1; i >= 0; --i) {
        while (*it != t[i]) {
            --it;
        }

        posback[i] = it - begin(s);
        --it;
    }

    size_t longest = max(posback[0], s.size() - 1 - posfront.back());
    for (size_t i = 1; i < t.size(); ++i) {
        longest = max(longest, posback[i] - posfront[i - 1] - 1);
    }

    cout << longest << '\n';

    return 0;
}