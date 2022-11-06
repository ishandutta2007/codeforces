#include <bits/stdc++.h>

// Contest: Avito Cool Challenge 2018 (https://codeforces.com/contest/1081)
// Problem: D: Maximum Distance (https://codeforces.com/contest/1081/problem/D)

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
    vi p;
    vector<bool> special;
    int c;
    explicit dsu(int n, vector<bool> special) : p(n), special(special) {
        iota(begin(p), end(p), 0);
        c = accumulate(begin(special), end(special), 0);
    }
    int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }
    void join(int i, int j) {
        i = find(i), j = find(j);
        p[i] = j;
        c -= (i != j && special[j] && special[i]);
        special[j] = special[j] || special[i];
    }
};

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<tuple<int, int, int>> e(m);
    vector<bool> special(n);
    int u, v, w;
    for (int i = 0; i < k; ++i)
        cin >> u, special[--u] = true;
    for (auto& [w, u, v] : e)
        cin >> u >> v >> w, --u, --v;

    sort(begin(e), end(e));
    dsu d(n, move(special));
    for (auto& [w, u, v] : e) {
        d.join(u, v);
        if (d.c == 1) {
            while (k--)
                cout << w << ' ';
            cout << '\n';
            return 0;
        }
    }

    return 0;
}