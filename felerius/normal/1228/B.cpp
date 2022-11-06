#include <bits/stdc++.h>

// Contest: Codeforces Round #589 (Div. 2) (https://codeforces.com/contest/1228)
// Problem: B: Filling the Grid (https://codeforces.com/contest/1228/problem/B)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    arr<int, 1000, 1000> g{};
    int h, w; cin >> h >> w;
    for (int y = 0; y < h; ++y) {
        int r; cin >> r;
        for (int x = 0; x < r; ++x)
            g[x][y] = 1;
        if (r < w)
            g[r][y] = -1;
    }
    for (int x = 0; x < w; ++x) {
        int c; cin >> c;
        for (int y = 0; y < c; ++y) {
            if (g[x][y] == -1) {
                cout << "0\n";
                return 0;
            }
            g[x][y] = 1;
        }
        if (c < h) {
            if (g[x][c] == 1) {
                cout << "0\n";
                return 0;
            }
            g[x][c] = -1;
        }
    }

    ll res = 1;
    for (int x = 0; x < w; ++x)
        for (int y = 0; y < h; ++y)
            if (g[x][y] == 0)
                res = 2 * res % ((ll)1e9 + 7);

    cout << res << '\n';
    return 0;
}