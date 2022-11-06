#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 22 (https://codeforces.com/contest/813)
// Problem: C: The Tag Game (https://codeforces.com/contest/813/problem/C)

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

vvi adj;
vi d, p;

void dfs(int v) {
    d[v] = 0;
    for (auto v2 : adj[v])
        if (v2 != p[v])
            p[v2] = v, dfs(v2), d[v] = max(d[v], d[v2] + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x; cin >> n >> x; --x;
    adj.resize(n), d.resize(n), p.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v; --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    p[0] = -1;
    dfs(0);

    int steps = 0;
    int v = x;
    while (v != 0)
        ++steps, v = p[v];

    int up = (steps - 1) / 2;
    for (int i = 0; i < up; ++i)
        x = p[x];

    cout << 2 * (d[x] + steps - up) << '\n';
    return 0;
}