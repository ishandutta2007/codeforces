#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, a[MN];
vector<pair<ll, ll>> ans, ord;
set<int> zz;

template<typename T>
struct fenwick_tree {
    vector<T> a;
    fenwick_tree(int n) { a.resize(n + 1); }
    void update(int idx, T delta) {
        for(; idx < a.size(); idx += (idx & -idx)) a[idx] += delta;
    }
    T query(int idx) {
        T ret = 0;
        for(; idx; idx -= (idx & -idx)) ret += a[idx];
        return ret;
    }
};

int main() {
    fenwick_tree<int> ac(MN);
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        ord.emplace_back(a[i], i);
    }
    sort(ord.begin(), ord.end());

    zz.insert(0); zz.insert(n+1);
    for(auto tt : ord) {
        int v = tt.first, i = tt.second;
        int l = *prev(zz.lower_bound(i)) + 1, r = *zz.upper_bound(i) - 1;

        int calls = v - ac.query(i);
        for(int j = 0; j < calls; j++) {
            ans.emplace_back(l, r);
        }
        ac.update(l, calls);
        ac.update(r + 1, -calls);

        zz.insert(i);
    }

    printf("%d\n", ans.size());
    for(auto tt : ans)
        printf("%lld %lld\n", tt.first, tt.second);
    return 0;
}