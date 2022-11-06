#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

// Contest: Codeforces Round #568 (Div. 2) (https://codeforces.com/contest/1185)
// Problem: E: Polycarp and Snakes (https://codeforces.com/contest/1185/problem/E)

using namespace std;

struct Bbox {
    int min_r = 2000;
    int max_r = -1;
    int min_c = 2000;
    int max_c = -1;
};

int main() {
    ios::sync_with_stdio(false);

    size_t t;
    cin >> t;

    while (t--) {
        size_t n, m;
        cin >> n >> m;

        array<Bbox, 26> b;
        vector<string> f(n);
        for (size_t r = 0; r < n; ++r) {
            cin >> f[r];
            for (size_t c = 0; c < m; ++c) {
                if (f[r][c] != '.') {
                    auto& bbox = b[f[r][c] - 'a'];
                    bbox.min_r = min(bbox.min_r, (int) r);
                    bbox.max_r = max(bbox.max_r, (int) r);
                    bbox.min_c = min(bbox.min_c, (int) c);
                    bbox.max_c = max(bbox.max_c, (int) c);
                }
            }
        }

        bool pos = true;
        vector<Bbox> snakes;
        for (int i = 25; pos && i >= 0; --i) {
            if (b[i].max_r == -1) {
                if (!snakes.empty()) {
                    auto last_snake = snakes.back();
                    snakes.emplace_back(last_snake);
                }

                continue;
            }

            auto& bb = b[i];
            snakes.emplace_back(bb);
            if (bb.min_r == bb.max_r) {
                for (size_t c = bb.min_c; c <= bb.max_c; ++c) {
                    if (f[bb.min_r][c] == '.' || f[bb.min_r][c] < ('a' + i)) {
                        pos = false;
                        break;
                    }
                }
            } else if (bb.min_c == bb.max_c) {
                for (size_t r = bb.min_r; r <= bb.max_r; ++r) {
                    if (f[r][bb.min_c] == '.' || f[r][bb.min_c] < ('a' + i)) {
                        pos = false;
                        break;
                    }
                }
            } else {
                pos = false;
            }
        }

        if (pos) {
            cout << "YES\n" << snakes.size() << '\n';
            for (auto it = rbegin(snakes); it != rend(snakes); ++it) {
                cout << (it->min_r + 1) << ' ' << (it->min_c + 1) << ' ' << (it->max_r + 1) << ' ' << (it->max_c + 1) << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}