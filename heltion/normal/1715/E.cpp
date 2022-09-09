#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
struct line{
    static bool Q;
    mutable LL k, m, p;
    bool operator<(const line& o)const{
        return Q ? p < o.p : k < o.k;
    }
};
bool line::Q = false;
struct lines : multiset<line> {
    //(for doubles, use inf = 1/.0, div(a,b) = a/b)
    const LL inf = LLONG_MAX;
    LL div(LL a, LL b){
        return a / b - ((a ^ b) < 0 and a % b);
    }
    bool isect(iterator x, iterator y) {
        if(y == end()) return x->p = inf, false;
        if(x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(LL k, LL m) {
        line::Q = false;
        auto z = insert({k, m, 0}), y = z++, x = y;
        while(isect(y, z)) z = erase(z);
        if(x != begin() and isect(--x, y)) isect(x, y = erase(y));
        while((y = x) != begin() and (--x)->p >= y->p)
        isect(x, erase(y));
    }
    LL query(LL x) {
        line::Q = true;
        auto l = lower_bound({0, 0, x});
        return l->k * x + l->m;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0, u, v, w; i < m; i += 1) {
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<LL> d(n + 1, 1E10);
    d[1] = 0;
    auto relax = [&]() {
        priority_queue<pair<LL, int>> pq;
        for (int i = 1; i <= n; i += 1) 
            pq.emplace(-d[i], i);
        while (not pq.empty()) {
            auto [du, u] = pq.top();
            pq.pop();
            if (-du > d[u]) continue;
            for (auto [v, w] : G[u])
                if (d[v] > d[u] + w)
                    pq.emplace(-(d[v] = d[u] + w), v);
        }
    };
    for (int i = 0; i <= k; i += 1) {
        if (i) {
            lines s;
            for (LL j = 1; j <= n; j += 1)
                s.add(2 * j, -j * j - d[j]);
            for (LL j = 1; j <= n; j += 1)
                d[j] = -s.query(j) + j * j;
        }
        relax();
    }
    for (int i = 1; i <= n; i += 1)
        cout << d[i] << " ";
}