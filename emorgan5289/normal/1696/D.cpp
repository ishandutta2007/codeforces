#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

template<typename it, typename bin_op>
struct sparse_table {

    using T = typename iterator_traits<it>::value_type;
    vector<vector<T>> t; bin_op f;

    void assign(it first, it last) {
        int n = distance(first, last);
        t.assign(32-__builtin_clz(n), vector<T>(n));
        t[0].assign(first, last);
        for (int i = 1; i < t.size(); i++)
            for (int j = 0; j < n-(1<<i)+1; j++)
                t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
    }

    sparse_table(bin_op op) : f(op) {}
    sparse_table(it first, it last, bin_op op) : f(op) {
        assign(first, last);
    }

    // returns f(a[l..r]) in O(1) time
    T operator()(int l, int r) {
        int h = floor(log2(r-l+1));
        return f(t[h][l], t[h][r-(1<<h)+1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> v(n); iota(all(v), 0);
        sparse_table argmin(all(v), [&](int x, int y) { return a[x] < a[y] ? x : y; });
        sparse_table argmax(all(v), [&](int x, int y) { return a[x] < a[y] ? y : x; });

        vector<array<int, 2>> stk;
        if (n != 1) stk.pb({0, n-1});
        int ans = 0;

        while (!stk.empty()) {
            auto [l, r] = stk.back();
            stk.pop_back();
            ans++;
            int x = argmin(l, r);
            int y = argmax(l, r);
            if (x > y) swap(x, y);
            if (l != x) stk.pb({l, x});
            if (y != r) stk.pb({y, r});
        }
        cout << ans << "\n";
    }
}