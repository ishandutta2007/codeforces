#include <bits/stdc++.h>

// Contest: Codeforces Round #605 (Div. 3) (https://codeforces.com/contest/1272)
// Problem: E: Nearest Opposite Parity (https://codeforces.com/contest/1272/problem/E)

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

    int n;
    cin >> n;
    vi a(n);
    for (auto& ai : a) cin >> ai;

    queue<int> q;
    vvi inc(n);
    vi d(n, -1);
    for (int i = 0; i < n; ++i) {
        int np = i - a[i], nn = i + a[i];
        if ((np >= 0 && a[i] % 2 != a[np] % 2) || (nn < n && a[i] % 2 != a[nn] % 2))
            d[i] = 1, q.push(i);
        if (np >= 0 && a[i] % 2 == a[np] % 2)
            inc[np].push_back(i);
        if (nn < n && a[i] % 2 == a[nn] % 2)
            inc[nn].push_back(i);
    }

    while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (auto vi : inc[v])
            if (d[vi] == -1)
                d[vi] = d[v] + 1, q.push(vi);
    }

    for (auto di : d)
        cout << di << ' ';
    cout << '\n';

    return 0;
}