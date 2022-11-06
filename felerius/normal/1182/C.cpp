#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

struct Words {
    size_t total = 0;
    array<vector<size_t>, 5> by_last;
};

int main() {
    ios::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<string> words(n);
    map<size_t, Words> by_count;
    for (size_t i = 0; i < n; ++i) {
        cin >> words[i];

        size_t count = 0;
        char last;
        for (auto c : words[i]) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
                last = c;
            }
        }

        size_t vowel_index = 0;
        if (last == 'a') {
            vowel_index = 0;
        } else if (last == 'e') {
            vowel_index = 1;
        } else if (last == 'i') {
            vowel_index = 2;
        } else if (last == 'o') {
            vowel_index = 3;
        } else if (last == 'u') {
            vowel_index = 4;
        }

        by_count[count].total++;
        by_count[count].by_last[vowel_index].emplace_back(i);
    }

    vector<pair<size_t, size_t>> good;
    vector<pair<size_t, size_t>> bad;

    vector<size_t> bad_candidates;
    for (auto& [count, w]: by_count) {
        if (w.total == 0) {
            continue;
        }

        bad_candidates.clear();
        for (size_t last = 0; last < 5; ++last) {
            for (size_t i = 1; i < w.by_last[last].size(); i += 2) {
                good.emplace_back(w.by_last[last][i - 1], w.by_last[last][i]);
            }

            if (w.by_last[last].size() % 2 == 1) {
                bad_candidates.emplace_back(w.by_last[last].back());
            }
        }

        for (size_t i = 1; i < bad_candidates.size(); i += 2) {
            bad.emplace_back(bad_candidates[i - 1], bad_candidates[i]);
        }
    }

    auto good_bad = min(good.size(), bad.size());
    auto good_good = (good.size() - good_bad) / 2;
    cout << (good_bad + good_good) << '\n';

    for (size_t i = 0; i < good_bad; ++i) {
        auto [a, b] = good[i];
        auto [c, d] = bad[i];
        cout << words[c] << ' ' << words[a] << '\n';
        cout << words[d] << ' ' << words[b] << '\n';
    }

    for (size_t i = 0; i < good_good; ++i) {
        auto [a, b] = good[2 * i + good_bad];
        auto [c, d] = good[2 * i + 1 + good_bad];
        cout << words[c] << ' ' << words[a] << '\n';
        cout << words[d] << ' ' << words[b] << '\n';
    }

    return 0;
}