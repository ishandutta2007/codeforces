#include <bits/stdc++.h>

// Contest: Codeforces Round #597 (Div. 2) (https://codeforces.com/contest/1245)
// Problem: E: Hyakugoku and Ladders (https://codeforces.com/contest/1245/problem/E)

using namespace std;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;

pair<int, int> PATH[] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9}, {1, 9}, {1, 8}, {1, 7}, {1, 6}, {1, 5}, {1, 4}, {1, 3}, {1, 2}, {1, 1}, {1, 0}, {2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9}, {3, 9}, {3, 8}, {3, 7}, {3, 6}, {3, 5}, {3, 4}, {3, 3}, {3, 2}, {3, 1}, {3, 0}, {4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 9}, {5, 9}, {5, 8}, {5, 7}, {5, 6}, {5, 5}, {5, 4}, {5, 3}, {5, 2}, {5, 1}, {5, 0}, {6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}, {6, 8}, {6, 9}, {7, 9}, {7, 8}, {7, 7}, {7, 6}, {7, 5}, {7, 4}, {7, 3}, {7, 2}, {7, 1}, {7, 0}, {8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9}, {9, 9}, {9, 8}, {9, 7}, {9, 6}, {9, 5}, {9, 4}, {9, 3}, {9, 2}, {9, 1}, {9, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    arr<int, 10, 10> ladder{};
    for (int y = 9; y >= 0; --y)
        for (int x = 0; x < 10; ++x)
            cin >> ladder[x][y];

    arr<double, 10, 10> dp{};
    dp[0][9] = 0.0;
    dp[1][9] = dp[2][9] = dp[3][9] = dp[4][9] = dp[5][9] = 6.0;
    for (int i = 93; i >= 0; --i) {
        auto [y, x] = PATH[i];
        for (int j = 1; j <= 6; ++j) {
            auto [dy, dx] = PATH[i + j];
            double res = dp[dx][dy] + 1;
            if (ladder[dx][dy])
                res = min(res, dp[dx][dy + ladder[dx][dy]] + 1);
            dp[x][y] += res / 6.0;
        }
    }

    cout << setprecision(20) << dp[0][0] << '\n';
    return 0;
}