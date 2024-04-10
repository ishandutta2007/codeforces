#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 77 (Rated for Div. 2) (https://codeforces.com/contest/1260)
// Problem: D: A Game with Traps (https://codeforces.com/contest/1260/problem/D)

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k, t; cin >> m >> n >> k >> t;
    vi a(m);
    for (auto& ai : a) cin >> ai;
    sort(begin(a), end(a), greater<>());

    vector<arr<int, 3>> tr(k);
    for (auto& [l, r, d] : tr) cin >> l >> r >> d;
    sort(begin(tr), end(tr));

    int low = 0, high = m + 1;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        int ag = a[mid - 1];
        int cost = n + 1;
        int mn = -1, mx = -1;
        for (auto [l, r, d] : tr) {
            if (d <= ag)
                continue;
            if (l <= mx)
                mx = max(mx, r);
            else {
                if (mx >= 0)
                    cost += 2 * (mx - mn + 1);
                mn = l;
                mx = r;
            }
        }
        if (mx >= 0)
            cost += 2 * (mx - mn + 1);
        (cost <= t ? low : high) = mid;
    }

    cout << low << '\n';
    return 0;
}