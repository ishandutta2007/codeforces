#include <bits/stdc++.h>

// Contest: Codeforces Round #589 (Div. 2) (https://codeforces.com/contest/1228)
// Problem: D: Complete Tripartite (https://codeforces.com/contest/1228/problem/D)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

template <class T, size_t... Is>
struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T>
struct arr_helper<T> {
    using type = T;
};
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> {
    using type = array<arr<T, Is...>, I>;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> c(n, 1);
    for (auto v : adj[0])
        c[v] = 2;

    if (adj[0].empty()) {
        cout << "-1\n";
        return 0;
    }
    auto v2 = adj[0][0];
    for (auto v : adj[v2])
        if (c[v] == 2)
            c[v] = 3;

    array<ll, 3> co = {0, 0, 0};
    for (int i = 0; i < n; ++i)
        co[c[i] - 1]++;

    arr<ll, 4, 4> e_co{};
    for (int i = 0; i < n; ++i) {
        for (int j : adj[i]) {
            if (j > i)
                continue;
            auto[a, b] = minmax(c[i], c[j]);
            if (a == b) {
                cout << "-1\n";
                return 0;
            }
            e_co[a][b]++;
        }
    }

    if (co[0] > 0 && co[1] > 0 && co[2] > 0 && e_co[1][2] == co[0] * co[1] &&
        e_co[1][3] == co[0] * co[2] && e_co[2][3] == co[1] * co[2]) {
        for (int i = 0; i < n; ++i)
            cout << c[i] << ' ';
        cout << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}