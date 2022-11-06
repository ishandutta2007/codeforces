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
    cin.tie(nullptr);

    size_t n, q;
    cin >> n >> q;

    vector<uint32_t> a(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<array<size_t, 19>> next(n);
    array<size_t, 19> next_state;
    fill(begin(next_state), end(next_state), n);

    for (int i = n - 1; i >= 0; --i) {
        fill(begin(next[i]), end(next[i]), n);
        for (size_t j = 0; j < 19; ++j) {
            if ((a[i] >> j) & 1u) {
                next[i][j] = i;
                if (next_state[j] < n) {
                    for (size_t k = 0; k < 19; ++k) {
                        next[i][k] = min(next[i][k], next[next_state[j]][k]);
                    }
                }

                next_state[j] = i;
            }
        }
    }

    for (size_t i = 0; i < q; ++i) {
        size_t x, y;
        cin >> x >> y;
        x--;
        y--;
        bool reachable = false;
        for (size_t j = 0; j < 19; ++j) {
            if ((a[y] >> j) & 1u && next[x][j] <= y) {
                reachable = true;
                break;
            }
        }

        if (reachable) {
            cout << "Shi\n";
        } else {
            cout << "Fou\n";
        }
    }

    return 0;
}