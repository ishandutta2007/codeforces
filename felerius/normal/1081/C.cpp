#include <bits/stdc++.h>

// Contest: Avito Cool Challenge 2018 (https://codeforces.com/contest/1081)
// Problem: C: Colorful Bricks (https://codeforces.com/contest/1081/problem/C)

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

const ll M = 998244353;
arr<ll, 2000, 2000> dp{};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    dp[0][0] = m;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (m - 1)) % M;
        }
    }

    cout << dp[n - 1][k] << '\n';
    return 0;
}