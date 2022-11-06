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

    string s;
    cin >> s;
    vector<size_t> a(s.size());
    a[0] = s[0] == '1';
    for (size_t i = 1; i < s.size(); ++i) {
        a[i] = a[i - 1] + (size_t)s[i];
    }

    cin >> s;
    size_t b_count = 0;
    for (auto c : s) {
        b_count += c == '1';
    }

    auto b_len = s.size();
    size_t count = 0;
    for (size_t i = 0; i + b_len <= a.size(); ++i) {
        auto pref_sum = a[i + b_len - 1] - (i == 0 ? 0 : a[i - 1]);
        count += (pref_sum + b_count) % 2 == 0;
    }

    cout << count << '\n';

    return 0;
}