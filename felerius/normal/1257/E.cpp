#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 76 (Rated for Div. 2) (https://codeforces.com/contest/1257)
// Problem: E: The Contest (https://codeforces.com/contest/1257/problem/E)

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

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    arr<int, 3> k; cin >> k[0] >> k[1] >> k[2];
    int n = k[0] + k[1] + k[2];
    vi a(n); int aij;
    for (int i : {0, 1, 2})
        for (int j = 0; j < k[i]; ++j)
            cin >> aij, a[--aij] = i;

    vector<arr<int, 3>> dp(n);
    for (int i : {0, 1, 2})
        dp[0][i] = (int)(a[0] != i);
    for (int i = 1; i < n; ++i) {
        for (int j : {0, 1, 2}) {
            int mn = INF;
            for (int k = 0; k <= j; ++k)
                mn = min(mn, dp[i - 1][k]);
            dp[i][j] = mn + (a[i] != j);
        }
    }

    int mn = INF;
    for (int i : {0, 1, 2})
        mn = min(mn, dp[n - 1][i]);
    cout << mn << '\n';
    return 0;
}