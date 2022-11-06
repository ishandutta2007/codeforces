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
#include <unordered_map>
#include <vector>


using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    if (n == 1) {
        int a;
        cin >> a;
        cout << "YES\n" << a << '\n';
        return 0;
    }

    unordered_map<int, size_t> counts;
    for (size_t i = 0; i < n * n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }

    if (n % 2 == 0) {
        if (!all_of(counts.begin(), counts.end(), [](auto pair) {
            return pair.second % 4 == 0;
        })) {
            cout << "NO\n";
            return 0;
        }
    } else {
        size_t odd = 0;
        size_t not_4 = 0;
        for (auto [_, c] : counts) {
            odd += c % 2;
            not_4 += (c % 4 > 1);
        }

        if (odd != 1 || not_4 > n - 1) {
            cout << "NO\n";
            return 0;
        }
    }

    vector<int> m(n * n);
    if (n % 2 == 1) {
        for (auto [v, c] : counts) {
            if (c % 2 == 1) {
                m[n * (n / 2) + n / 2] = v;
                counts[v]--;
                break;
            }
        }

        vector<int> twos;
        for (auto [v, c] : counts) {
            if (c % 4 == 2) {
                twos.emplace_back(v);
                counts[v] -= 2;
            }
        }
        for (auto [v, c] : counts) {
            while (twos.size() < n - 1 && c > 0) {
                twos.emplace_back(v);
                c -= 2;
            }

            counts[v] = c;
        }

        for (size_t i = 0; i < n / 2; ++i) {
            auto a = twos[2 * i];
            auto b = twos[2 * i + 1];
            m[n * (n / 2) + i] = m[n * (n / 2) + (n - i - 1)] = a;
            m[n * i + n / 2] = m[n * (n - i - 1) + n / 2] = b;
        }
    }

    auto it = counts.begin();
    for (size_t y = 0; y < n / 2; ++y) {
        for (size_t x = 0; x < n / 2; ++x) {
            while (it->second == 0) {
                ++it;
            }

            m[y * n + x] = m[y * n + (n - x - 1)] = m[(n - y - 1) * n + x] = m[(n - y - 1) * n + (n - x - 1)] = it->first;
            it->second -= 4;
        }
    }

    cout << "YES\n";
    for (size_t y = 0; y < n; ++y) {
        for (size_t x = 0; x < n; ++x) {
            cout << m[y * n + x] << ' ';
        }

        cout << '\n';
    }

    return 0;
}