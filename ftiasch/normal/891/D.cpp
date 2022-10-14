#include <cstdio>
#include <cstring>
#include <vector>

const int N = 500000;

struct State
{
    State() { memset(ways, 0, sizeof(ways)); }

    State extend()
    {
        State w;
        // 0 -- empty root, 1 -- occupied root
        w.ways[0][0] = ways[1][0];
        w.ways[0][1] = ways[0][0] + ways[1][1];
        w.ways[1][0] = ways[0][0];
        w.ways[1][1] = ways[0][1];
        return w;
    }

    int ways[2][2];
};

State merge(const State& u, const State& v)
{
    State w;
    for (int ur = 0; ur < 2; ++ ur) {
        for (int vr = 0; ur + vr < 2; ++ vr) {
            for (int uc = 0; uc < 2; ++ uc) {
                for (int vc = 0; uc + vc < 2; ++ vc) {
                    w.ways[ur + vr][uc + vc] += u.ways[ur][uc] * v.ways[vr][vc];
                }
            }
        }
    }
    return w;
}

int n, size[N];
State down[N], up[N];
std::vector<int> tree[N];

void dfs1(int p, int u)
{
    size[u] = 1;
    down[u].ways[0][0] = 1;
    for (auto v : tree[u]) {
        if (v != p) {
            dfs1(u, v);
            size[u] += size[v];
            down[u] = merge(down[u], down[v].extend());
        }
    }
}

void dfs2(int p, int u)
{
    std::vector<int> children;
    for (auto v : tree[u]) {
        if (v != p) {
            children.push_back(v);
        }
    }
    int m = children.size();
    std::vector<State> pre(m + 1);
    pre[0].ways[0][0] = 1;
    if (~p) {
        pre[0] = up[u].extend();
    }
    for (int i = 0; i < m; ++ i) {
        pre[i + 1] = merge(pre[i], down[children[i]].extend());
    }
    State suf;
    suf.ways[0][0] = 1;
    for (int i = m - 1; i >= 0; -- i) {
        up[children[i]] = merge(pre[i], suf);
        suf = merge(suf, down[children[i]].extend());
    }
    for (auto v : children) {
        dfs2(u, v);
    }
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("D.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        a --;
        b --;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(-1, 0);
    dfs2(-1, 0);
    long long result = 0;
    for (int i = 1; i < n; ++ i) {
        if (down[i].ways[1][0] == 1 && up[i].ways[1][0] == 1) {
            result += 1LL * size[i] * (n - size[i]);
        } else {
            result += 1LL * (down[i].ways[0][0] + down[i].ways[1][1]) * (up[i].ways[0][0] + up[i].ways[1][1]);
        }
    }
    printf("%lld\n", result);
}