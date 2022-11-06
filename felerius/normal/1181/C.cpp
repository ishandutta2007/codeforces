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

struct C {
    size_t right;
    size_t down;
};

int main() {
    ios::sync_with_stdio(false);

    size_t h, w;
    cin >> h >> w;

    vector<string> grid(h);
    for (size_t i = 0; i < h; ++i) {
        cin >> grid[i];
    }

    vector<vector<C>> streaks(h, vector<C>(w));
    for (size_t y = 0; y < h; ++y) {
        size_t start_x = 0;
        while (start_x < w) {
            size_t x = start_x + 1;
            while (x < w && grid[y][x] == grid[y][start_x]) {
                ++x;
            }

            for (size_t i = start_x; i < x; ++i) {
                streaks[y][i].right = x - i;
            }

            start_x = x;
        }
    }

    for (size_t x = 0; x < w; ++x) {
        size_t start_y = 0;
        while (start_y < h) {
            size_t y = start_y + 1;
            while (y < h && grid[y][x] == grid[start_y][x]) {
                ++y;
            }

            for (size_t i = start_y; i < y; ++i) {
                streaks[i][x].down = y - i;
            }

            start_y = y;
        }
    }


    uint64_t count = 0;
    for (size_t x = 0; x < w; ++x) {
        size_t y = 0;
        while (y < h) {
            size_t y2 = y + streaks[y][x].down;
            if (y2 >= h || streaks[y][x].down < streaks[y2][x].down) {
                y = y2;
                continue;
            }

            size_t y3 = y2 + streaks[y2][x].down;
            if (y3 >= h || streaks[y3][x].down < streaks[y2][x].down) {
                y = y2;
                continue;
            }

            size_t fh = streaks[y2][x].down;
            size_t min_w = streaks[y2 - fh][x].right;
            for (size_t fy = y2 - fh + 1; fy < y2 + 2 * fh; ++fy) {
                min_w = min(min_w, streaks[fy][x].right);
            }

            count += min_w;
            y = y2;
        }
    }

    cout << count << '\n';

    return 0;
}