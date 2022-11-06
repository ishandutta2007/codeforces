#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <random>
#include <string>
#include <tuple>
#include <vector>

// Contest: Educational Codeforces Round 66 (Rated for Div. 2) (https://codeforces.com/contest/1175)
// Problem: F: The Number of Subpermutations (https://codeforces.com/contest/1175/problem/F)

using namespace std;

using Hash = pair<uint64_t, uint64_t>;

Hash xor_(Hash a, Hash b) {
    return {a.first ^ b.first, a.second ^ b.second};
}

size_t n;
vector<Hash> hashes;
vector<Hash> permhash;
vector<uint32_t> a;

uint64_t count_perms() {
    vector<Hash> prefhash(n);
    prefhash[0] = hashes[a[0] - 1];
    for (size_t i = 1; i < n; ++i) {
        prefhash[i] = xor_(prefhash[i - 1], hashes[a[i] - 1]);
    }

    size_t i = 0;
    while (i < n && a[i] != 1) {
        ++i;
    }

    uint64_t count = 0;
    while (i < n) {
        ++i;
        uint32_t max = 0;
        while (i < n && a[i] > 1) {
            max = ::max(max, a[i]);
            if (max - 1 <= i) {
                auto hash = prefhash[i];
                if (i >= max) {
                    hash = xor_(hash, prefhash[i - max]);
                }

                count += permhash[max - 1] == hash;
            }

            ++i;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    for (auto& ai : a) {
        cin >> ai;
    }

    hashes.resize(n);
    uniform_int_distribution<uint64_t> d;
    mt19937_64 rnd{random_device{}()};
    for (auto& hi : hashes) {
        hi = {d(rnd), d(rnd)};
    }

    permhash.resize(n);
    permhash[0] = hashes[0];
    for (size_t i = 1; i < n; ++i) {
        permhash[i] = xor_(permhash[i - 1], hashes[i]);
    }

    uint64_t c = count(begin(a), end(a), 1u);
    c += count_perms();
    reverse(begin(a), end(a));
    c += count_perms();

    cout << c << '\n';

    return 0;
}