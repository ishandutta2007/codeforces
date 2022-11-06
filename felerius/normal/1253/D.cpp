#include <bits/stdc++.h>

// Contest: Codeforces Round #600 (Div. 2) (https://codeforces.com/contest/1253)
// Problem: D: Harmonious Graph (https://codeforces.com/contest/1253/problem/D)

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

struct dsu {
    vi p, mn, mx;
    explicit dsu(int n) : p(n), mn(n), mx(n) {
        iota(begin(p), end(p), 0);
        iota(begin(mn), end(mn), 0);
        iota(begin(mx), end(mx), 0);
    }
    int find(int v) { return p[v] == v ? v : p[v] = find(p[v]); }
    void merge(int a, int b) {
        a = find(a), b = find(b);
        p[b] = a;
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    dsu d(n);
    int u, v;
    while (m--)
        cin >> u >> v, d.merge(u - 1, v - 1);

    vpi rng;
    for (int i = 0; i < n; ++i)
        if (d.p[i] == i)
            rng.emplace_back(d.mn[i], d.mx[i]);

    sort(begin(rng), end(rng));
    int last = -1, cnt = 0;
    for (auto [mn, mx] : rng) {
        if (mn > last)
            last = mx;
        else
            ++cnt, last = max(last, mx);
    }

    cout << cnt << '\n';
    return 0;
}