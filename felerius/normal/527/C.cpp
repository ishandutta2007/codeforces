#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h;
    size_t n;
    cin >> w >> h >> n;

    array<size_t, 200000> hor = {0};
    array<size_t, 200000> vert = {0};
    for (size_t i = 0; i < n; ++i) {
        char c;
        int coord;
        cin >> c >> coord;
        if (c == 'H') {
            hor[coord] = i + 1;
        } else {
            vert[coord] = i + 1;
        }
    }

    list<int> vert_seg, hor_seg;
    vector<pair<bool, decltype(hor_seg)::iterator>> cut_iter(n);
    int len = 0;
    for (int i = 0; i < h; ++i) {
        if (hor[i] != 0) {
            hor_seg.emplace_back(len);
            cut_iter[hor[i] - 1] = {false, prev(end(hor_seg))};
            len = 0;
        }

        ++len;
    }
    hor_seg.emplace_back(len);

    len = 0;
    for (int i = 0; i < w; ++i) {
        if (vert[i] != 0) {
            vert_seg.emplace_back(len);
            cut_iter[vert[i] - 1] = {true, prev(end(vert_seg))};
            len = 0;
        }

        ++len;
    }
    vert_seg.emplace_back(len);

    int max_vert = *max_element(begin(vert_seg), end(vert_seg));
    int max_hor = *max_element(begin(hor_seg), end(hor_seg));

    vector<int64_t> result(n);
    for (int i = n - 1; i >= 0; --i) {
        result[i] = (int64_t)max_vert * max_hor;

        auto [vert, it] = cut_iter[i];
        if (vert) {
            *next(it) += *it;
            max_vert = max(max_vert, *next(it));
            vert_seg.erase(it);
        } else {
            *next(it) += *it;
            max_hor = max(max_hor, *next(it));
            hor_seg.erase(it);
        }
    }

    for (auto r : result) {
        cout << r << '\n';
    }

    return 0;
}