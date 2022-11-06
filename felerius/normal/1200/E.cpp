#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <string_view>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

void z(string_view s, vector<size_t>& out) {
    auto n = s.size();
    out.resize(n);
    fill(begin(out), end(out), 0);
    size_t l, r;
    l = r = 0;
    for (size_t i = 1; i < n; ++i) {
        if (i <= r) {
            out[i] = min(r - i + 1, out[i - l]);
        }
        while (i + out[i] < n and s[out[i]] == s[i + out[i]]) {
            out[i]++;
        }
        if (i + out[i] - 1 > r) {
            l = i;
            r = i + out[i] - 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<string> w(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> w[i];
    }

    string s;
    string res = w[0];
    vector<size_t> zf;
    for (size_t i = 0; i < n - 1; ++i) {
        s.resize(2 * w[i + 1].size() + 1);
        copy(begin(w[i + 1]), end(w[i + 1]), begin(s));
        s[w[i + 1].size()] = '#';
        auto suf = min(res.size(), w[i + 1].size());
        copy(rbegin(res), rbegin(res) + suf, rbegin(s));
        z(s, zf);
        size_t j = 0;
        for (size_t k = 0; k < suf; ++k) {
            if (*(rbegin(zf) + k) == k + 1) {
                j = k + 1;
            }
        }
        copy(begin(w[i + 1]) + j, end(w[i + 1]), back_inserter(res));
    }

    cout << res << '\n';

    return 0;
}