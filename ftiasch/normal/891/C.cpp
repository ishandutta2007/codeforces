#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

const int N = 500000;

int n, m, a[N], b[N], c[N], order[N], group[N];

struct DSU
{
    DSU(int n) : parent(n), time(n, -1)
    {
    }

    int find(int u)
    {
        if (time[u] != now) {
            time[u] = now;
            parent[u] = u;
        }
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool merge(int u, int v)
    {
        if (find(u) == find(v)) {
            return false;
        }
        parent[find(u)] = find(v);
        return true;
    }

    void reset()
    {
        now ++;
    }

    int now = 0;
    std::vector<int> parent, time;
};

bool by_c(int i, int j)
{
    return c[i] < c[j];
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("C.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d%d", a + i, b + i, c + i);
        a[i] --;
        b[i] --;
        order[i] = i;
    }
    std::sort(order, order + m, by_c);
    DSU global(n);
    std::vector<DSU> locals;
    int gcnt = 0;
    for (int i = 0; i < m; ) {
        int j = i;
        std::map<int, int> M;
        while (j < m && c[order[i]] == c[order[j]]) {
            M[a[order[j]] = global.find(a[order[j]])] = 0;
            M[b[order[j]] = global.find(b[order[j]])] = 0;
            group[order[j ++]] = gcnt;
        }
        gcnt ++;
        int cnt = 0;
        for (auto& it : M) {
            it.second = cnt ++;
        }
        for (int k = i; k < j; ++ k) {
            global.merge(a[order[k]], b[order[k]]);
            a[order[k]] = M[a[order[k]]];
            b[order[k]] = M[b[order[k]]];
        }
        i = j;
        locals.emplace_back(cnt);
    }
    int q;
    scanf("%d", &q);
    while (q --) {
        int k;
        scanf("%d", &k);
        std::vector<int> is(k);
        for (int i = 0; i < k; ++ i) {
            scanf("%d", &is[i]);
            is[i] --;
        }
        std::sort(is.begin(), is.end(), by_c);
        bool ok = true;
        for (int i = 0; i < k && ok; ) {
            int j = i;
            auto& l = locals[group[is[i]]];
            l.reset();
            while (j < k && c[is[i]] == c[is[j]]) {
                ok &= l.merge(a[is[j]], b[is[j]]);
                j ++;
            }
            i = j;
        }
        puts(ok ? "YES" : "NO");
    }
}