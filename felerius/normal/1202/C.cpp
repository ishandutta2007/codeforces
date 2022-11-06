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

template <class It, class OutIt>
pair<int, int> find_ex(int x, int y, int one, It begin, It end, OutIt out) {
    int min_x, max_x, min_y, max_y;
    min_x = max_x = x;
    min_y = max_y = y;
    while (begin != end) {
        switch (*begin++) {
            case 'W':
                y -= one;
                break;
            case 'A':
                x -= one;
                break;
            case 'S':
                y += one;
                break;
            case 'D':
                x += one;
                break;
        }
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
        *out++ = {min_x, max_x, min_y, max_y};
    }

    return {x, y};
}

int64_t area(int min_x, int max_x, int min_y, int max_y) {
    return (int64_t)(max_x - min_x + 1) * (int64_t)(max_y - min_y + 1);
}

int main() {
    ios::sync_with_stdio(false);

    size_t t;
    cin >> t;

    string s;
    vector<array<int, 4>> ex;
    vector<array<int, 4>> exback;
    while (t--) {
        cin >> s;
        ex.resize(s.size());
        exback.resize(s.size());

        auto [final_x, final_y] = find_ex(0, 0, 1, begin(s), end(s), begin(ex));
        find_ex(final_x, final_y, -1, rbegin(s), rend(s), rbegin(exback));

        auto best = area(exback[0][0], exback[0][1], exback[0][2], exback[0][3]);
        for (size_t i = 0; i < s.size() - 1; ++i) {
            auto [f_min_x, f_max_x, f_min_y, f_max_y] = ex[i];
            auto [b_min_x, b_max_x, b_min_y, b_max_y] = exback[i + 1];

            for (auto [dx, dy] : {pair(-1, 0), pair(1, 0), pair(0, 1), pair(0, -1)}) {
                auto a = area(
                    min(f_min_x, b_min_x + dx),
                    max(f_max_x, b_max_x + dx),
                    min(f_min_y, b_min_y + dy),
                    max(f_max_y, b_max_y + dy)
                );
                best = min(best, a);
            }
        }

        cout << best << '\n';
    }

    return 0;
}