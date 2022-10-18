//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using pii = pair<int, int>;

struct Query {
    int idx, x, k;

    bool operator<(const Query& rhs) const {
        return k < rhs.k;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int q;
        cin >> q;
        vector<int> ans(q, -1);
        vector<Query> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i].x >> queries[i].k;
            --queries[i].x;
            queries[i].idx = i;
        }
        sort(all(queries));
        int ptr = 0;
        for (int iter = 0; ptr < q; ++iter) {
            while (ptr < q && iter == queries[ptr].k) {
                ans[queries[ptr].idx] = v[queries[ptr].x];
                ++ptr;
            }
            vector<int> cnt(n + 1);
            auto u = v;
            for (int i = 0; i < n; ++i)
                ++cnt[v[i]];
            for (int i = 0; i < n; ++i)
                u[i] = cnt[u[i]];
            if (u == v) {
                while (ptr < q) {
                    ans[queries[ptr].idx] = v[queries[ptr].x];
                    ++ptr;
                }
                break;
            }
            swap(v, u);
        }
        for (int i = 0; i < q; ++i)
            cout << ans[i] << '\n';
    }
}