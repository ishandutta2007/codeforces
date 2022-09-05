#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007, B = 233;
int n, mx, id, h[maxn];
vector<int> G[maxn];
unordered_map<int, int> mp;
mt19937 rnd(time(0));

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    auto ins = [&](int x) { mp[x]++; };
    auto del = [&](int x) { if (!--mp[x]) mp.erase(x); };
    auto gen = [&](int x) {
        static unordered_map<int, int> h;
        if (h.count(x)) return h[x];
        int t = rnd() % P;
        while (!t) t = rnd() % P;
        return h[x] = t;
    };
    function<void(int, int)> init = [&](int v, int fa) {
        h[v] = 1;
        for (int u : G[v]) if (u ^ fa) {
            init(u, v), red(h[v] += gen(h[u]) - P);
        }
        ins(h[v]);
    };
    function<void(int, int)> dfs = [&](int v, int fa) {
        if (mp.size() > mx) mx = mp.size(), id = v;
        for (int u : G[v]) if (u ^ fa) {
            del(h[v]), del(h[u]);
            int foo = h[v], bar = h[u];
            red(h[v] -= gen(h[u])), red(h[u] += gen(h[v]) - P);
            ins(h[v]), ins(h[u]), dfs(u, v);
            del(h[v]), del(h[u]);
            ins(h[v] = foo), ins(h[u] = bar);
        }
    };
    init(1, 0), dfs(1, 0);
    printf("%d\n", id);
    return 0;
}