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

    size_t n, q;
    cin >> n >> q;

    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<uint64_t, size_t>> quer(q);
    for (size_t i = 0; i < q; ++i) {
        uint64_t q;
        cin >> q;
        quer[i] = {q, i};
    }

    vector<pair<uint32_t, uint32_t>> answers(q);
    sort(begin(quer), end(quer));
    auto quer_it = begin(quer);

    vector<uint32_t> circ;
    circ.reserve(n - 1);
    circ.emplace_back(min(a[0], a[1]));
    auto largest = max(a[0], a[1]);
    while (quer_it != end(quer) && quer_it->first == 1) {
        answers[quer_it++->second] = {a[0], a[1]};
    }

    for (size_t i = 2; quer_it != end(quer) && i < n; ++i) {
        while (quer_it != end(quer) && quer_it->first == i) {
            answers[quer_it++->second] = {largest, a[i]};
        }

        if (a[i] > largest) {
            circ.emplace_back(largest);
            largest = a[i];
        } else {
            circ.emplace_back(a[i]);
        }
    }

    while (quer_it != end(quer)) {
        answers[quer_it->second] = {largest, circ[(quer_it->first - n) % (n - 1)]};
        quer_it++;
    }

    for (auto [a, b] : answers) {
        cout << a << ' ' << b << '\n';
    }

    return 0;
}