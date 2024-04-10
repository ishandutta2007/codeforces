#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n, ans[maxn], foo[maxn];

struct {
    int d[maxn];
    set<array<int, 2>> E, deg, leaf;
    set<int> V, G[maxn];

    void add_edge(int u, int v) {
        d[u]++, d[v]++;
        E.insert({u, v}), E.insert({v, u});
        G[u].insert(v), G[v].insert(u);
    }
    void init() {
        for (int i = 1; i <= n; i++) {
            V.insert(i), deg.insert({d[i], i});
            if (d[i] == 1) leaf.insert({*G[i].begin(), i});
        }
    }

    int star() {
        return V.size() - 1 - deg.rbegin()->at(0);
    }
    void del(int x) {
        int y = *G[x].begin();
        V.erase(x), leaf.erase({y, x}), deg.erase({1, x});
        G[x].erase(y), G[y].erase(x);
        deg.erase({d[y], y}), deg.insert({--d[y], y});
        if (d[y] == 1) leaf.insert({*G[y].begin(), y});
    }
    pair<int, int> leaves() {
        set<int> S = {leaf.begin()->at(1), next(leaf.begin())->at(1), leaf.rbegin()->at(1), next(leaf.rbegin())->at(1)};
        int big = -1, x = -1, y = -1;
        for (int u : S) if (d[*G[u].begin()] > 2) {
            big = *G[u].begin(); break;
        }
        if (!~big) return {leaf.begin()->at(1), leaf.rbegin()->at(1)};
        for (int u : S) {
            (*G[u].begin() == big ? x : y) = u;
        }
        return {x, y};
    }
} T1, T2;

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v), T1.add_edge(u, v);
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v), T2.add_edge(u - n, v - n);        
    }
    T1.init(), T2.init();
    if (!T1.star() || !T2.star()) puts("No"), exit(0);
    auto brute = [&]() {
        vector<int> V1(T1.V.begin(), T1.V.end()), V2(T2.V.begin(), T2.V.end());
        do {
            bool flag = 1;
            for (int i = 0; i < V1.size(); i++) {
                for (int j = i + 1; j < V1.size(); j++) if (T1.E.count({V1[i], V1[j]})) {
                    if (T2.E.count({V2[i], V2[j]})) flag = 0;
                }
            }
            if (flag) {
                for (int i = 0; i < V1.size(); i++) ans[V1[i]] = V2[i];
                return;
            }
        } while (next_permutation(V2.begin(), V2.end()));
    };
    auto star = [&]() {
        int u = next(T1.deg.rbegin())->at(1), v = *T1.G[u].begin(), w = *T1.G[u].rbegin();
        if (T1.d[w] == 1) swap(v, w);
        int _u = -1, _w = T2.leaf.begin()->at(1), _v = *T2.G[_w].begin();
        for (int x : T2.V) {
            if (!T2.E.count({x, _v}) && !T2.E.count({x, _w})) { _u = x; break; }
        }
        ans[u] = _u, ans[v] = _v, ans[w] = _w;
        vector<int> V;
        for (int x : T1.V) {
            if (x ^ u && x ^ v && x ^ w) V.push_back(x);
        }
        for (int x : T2.V) if (x ^ _u && x ^ _v && x ^ _w) {
            ans[V.back()] = x, V.pop_back();
        }
    };
    function<void()> solve = [&]() {
        if (T1.V.size() <= 5) { brute(); return; }
        if (T1.star() == 1) { star(); return; }
        if (T2.star() == 1) {
            swap(T1, T2), star();
            for (int i = 1; i <= n; i++) foo[ans[i]] = i;
            memcpy(ans, foo, sizeof(ans)); return;
        }
        auto a = T1.leaves(), b = make_pair(*T1.G[a.first].begin(), *T1.G[a.second].begin());
        auto c = T2.leaves(), d = make_pair(*T2.G[c.first].begin(), *T2.G[c.second].begin());
        T1.del(a.first), T1.del(a.second);
        T2.del(c.first), T2.del(c.second), solve();
        ans[a.first] = c.first, ans[a.second] = c.second;
        if (ans[b.first] == d.first || ans[b.second] == d.second) swap(ans[a.first], ans[a.second]);
    };
    puts("Yes"), solve();
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i] + n);
    }
    return 0;
}