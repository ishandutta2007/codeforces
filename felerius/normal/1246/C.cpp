#include <bits/stdc++.h>

// Contest: Codeforces Round #596 (Div. 1, based on Technocup 2020 Elimination Round 2) (https://codeforces.com/contest/1246)
// Problem: C: Rock Is Push (https://codeforces.com/contest/1246/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

arr<bool, 2000, 2000> rock;
arr<int, 2000, 2000> cd, cr, r, d;
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int y = 0; y < n; ++y) {
        string s; cin >> s;
        for (int x = 0; x < m; ++x)
            rock[x][y] = s[x] == 'R';
    }

    for (int y = n - 1; y >= 0; --y) {
        for (int x = m - 1; x >= 0; --x) {
            cd[x][y] = (y + 1 == n ? 0 : cd[x][y + 1]) + rock[x][y];
            cr[x][y] = (x + 1 == m ? 0 : cr[x + 1][y]) + rock[x][y];
        }
    }

    if (n == 1 || m == 1) {
        cout << (cr[0][0] == 0 && cd[0][0] == 0 ? 1 : 0) << '\n';
        return 0;
    }

    for (int y = n - 1; y >= 0; --y) {
        for (int x = m - 1; x >= 0; --x) {
            if (x == m - 1 && y == n - 1)
                r[x][y] = d[x][y] = 1;
            else if (y == n - 1) {
                d[x][y] = 0;
                r[x][y] = (cr[x + 1][y] == 0) ? 1 : 0;
            } else if (x == m - 1) {
                r[x][y] = 0;
                d[x][y] = (cd[x][y + 1] == 0) ? 1 : 0;
            } else {
                if (x == 0)
                    d[x][y] = (y + 1 >= n - cd[0][0]) ? 0 : d[x][y + 1] + r[x][y + 1];
                else
                    d[x][y] = (d[x][y + 1] + r[x][y + 1]) % M + M - (rock[x][y + 1] ? r[x][n - cd[x][y + 1]] : 0);

                if (y == 0)
                    r[x][y] = (x + 1 >= m - cr[0][0]) ? 0 : r[x + 1][y] + d[x + 1][y];
                else
                    r[x][y] = (r[x + 1][y] + d[x + 1][y]) % M + M - (rock[x + 1][y] ? d[m - cr[x + 1][y]][y] : 0);
            }
            d[x][y] %= M;
            r[x][y] %= M;
        }
    }

    cout << ((d[0][0] + r[0][0]) % M) << '\n';
    return 0;
}