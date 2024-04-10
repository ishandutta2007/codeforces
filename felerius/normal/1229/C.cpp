#include <bits/stdc++.h>

// Contest: Codeforces Round #588 (Div. 1) (https://codeforces.com/contest/1229)
// Problem: C: Konrad and Company Evaluation (https://codeforces.com/contest/1229/problem/C)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

//ll M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> inc(n);
    vector<ll> out(n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        if (a > b) swap(a, b);
        inc[a].emplace_back(b);
        out[b]++;
    }

    ll res = 0;
    auto add = [&](auto v) { res += out[v] * (ll)inc[v].size(); };
    auto sub = [&](auto v) { res -= out[v] * (ll)inc[v].size(); };
    for (int i = 0; i < n; ++i)
        add(i);

    cout << res << '\n';
    int q; cin >> q;
    while (q--) {
        int v; cin >> v; --v;
        sub(v);
        out[v] += inc[v].size();
        for (auto v2 : inc[v]) {
            sub(v2);
            out[v2]--;
            inc[v2].emplace_back(v);
            add(v2);
        }
        inc[v].clear();
        cout << res << '\n';
    }

    return 0;
}