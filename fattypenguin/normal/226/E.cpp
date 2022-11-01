#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define TR(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAXN = 2811111;

struct Node
{
    int l, r, cl, cr, val;

    Node(int tl, int tr, int tcl, int tcr, int tval = 0) :
        l(tl), r(tr), cl(tcl), cr(tcr), val(tval)
    {
    }

    Node()
    {
    }
} tree[MAXN];

int last;

int getNode() { return last++;}

int makeNode(int left, int right, int cl, int cr, int x)
{
    tree[x] = Node(left, right, cl, cr);
    tree[x].val = tree[cl].val + tree[cr].val;
    return x;
}

int build(int left, int right, int val, int x)
{
    tree[x].l = left;
    tree[x].r = right;
    if (left == right)
    {
        tree[x].val = val;
        return x;
    }

    int mid = (left + right) >> 1;
    tree[x].cl = build(left, mid, val, getNode());
    tree[x].cr = build(mid+1, right, val, getNode());
    tree[x].val = tree[tree[x].cl].val + tree[tree[x].cr].val;

    return x;
}

int add(int pos, int val, int x)
{
    if (tree[x].l == tree[x].r)
        return build(tree[x].l, tree[x].r, tree[x].val + val, getNode());
    int mid = tree[tree[x].cl].r;
    if (pos <= mid)
        return makeNode(tree[x].l, tree[x].r, add(pos, val, tree[x].cl), tree[x].cr, getNode());
    return makeNode(tree[x].l, tree[x].r, tree[x].cl, add(pos, val, tree[x].cr), getNode());
}

int root[MAXN];
int att[MAXN], depth[MAXN];

vector<int> e[MAXN];
int fa[200007][20];

void dfs(int u, int father = 0, int dep = 0)
{
    root[u] = add(att[u], 1, root[father]);
    fa[u][0] = father;
    depth[u] = dep;
    for (int i = 1; i < 20; ++i)
        fa[u][i] = fa[fa[u][i-1]][i-1];
    for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); ++it)
        if (*it != father)
            dfs(*it, u, dep+1);
}

int getLca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = 19; i >= 0; --i)
        if (depth[fa[u][i]] >= depth[v])
            u = fa[u][i];
    if (u == v)
        return u;
    for (int i = 19; i >= 0; --i)
        if (fa[u][i] != fa[v][i])
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

int get(int left, int right, int u, int v)
{
    if (left <= tree[u].l && right >= tree[u].r)
    {
        int have = tree[u].val - tree[v].val;
        return have;
    }

    int mid = (tree[u].l + tree[u].r) >> 1, ret = 0;
    if (left <= mid) ret += get(left, right, tree[u].cl, tree[v].cl);
    if (right > mid) ret += get(left, right, tree[u].cr, tree[v].cr);

    return ret;
}

int getVal(int u, int v, int left, int right)
{
    if (depth[v] < depth[u])
        swap(u, v);
    int ru = root[v], rv = root[u];
    return get(left, right, ru, rv);
}

int q[222222][5];
int attacked[222222];

//path v -> u
int func(int u, int v, int k, int l, int r)
{
    u = fa[u][0];
    if (depth[v] - depth[u] - getVal(u, v, l, r) < k)
        return -1;

    int cur = v;
    for (int i = 19; i >= 0; --i)
    {
        if (depth[fa[cur][i]] <= depth[u])
            continue;
        if (depth[v] - depth[fa[cur][i]] + 1 - getVal(v, fa[fa[cur][i]][0], l, r) < k)
            cur = fa[cur][i];
    }

    return fa[cur][0];
}


//path u -> v  u is LCA
int func1(int u, int v, int k, int l, int r)
{
    u = fa[u][0];
    if (depth[v] - depth[u] - getVal(u, v, l, r) < k)
        return -1;

    int cur = v;
    for (int i = 19; i >= 0; --i)
    {
        if (depth[fa[cur][i]] <= depth[u])
            continue;
        if (depth[fa[cur][i]] - depth[u] - getVal(u, fa[cur][i], l, r) >= k)
            cur = fa[cur][i];
    }

    return cur;
}

int getKth(int u, int v, int k, int l, int r)
{
    int lca = getLca(u, v);

    if (lca == u || lca == v)
    {
        if (lca == v)
            return func(v, u, k, l, r);
        return func1(u, v, k, l, r);
    }
    else
    {
        if (depth[u] - depth[lca] + 1 - getVal(u, fa[lca][0], l, r) >= k)
            return func(lca, u, k, l, r);
        k -= depth[u] - depth[lca] + 1 - getVal(u, fa[lca][0], l, r);
        if (!(att[lca] >= l && att[lca] <= r))
            ++k;
        return func1(lca, v, k, l, r);
    }
}

int main()
{
    int rt, n, m, u, v, w;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &u);
        if (!u)
            rt = i;
        else e[u].push_back(i);

        attacked[i] = 0;
    }

    scanf("%d", &m);
    for (int i = 1; i <= n; ++i)
        att[i] = m;
    REP(i, m)
    {
        scanf("%d%d", &q[i][0], &q[i][1]);
        if (q[i][0] == 1)
            att[q[i][1]] = i;
        else
        {
            for (int j = 2; j < 5; ++j)
                scanf("%d", &q[i][j]);
        }
    }

    last = 0;
    depth[0] = -1;
    root[0] = build(0, m, 0, getNode());
    dfs(rt, 0, 0);

    REP(i, m) if (q[i][0] == 2)
    {
        int u = q[i][1],
            v = q[i][2],
            k = q[i][3],
            y = q[i][4];
        if (att[u] < y || !attacked[u]) ++k;

        int ans = getKth(u, v, k, y, i);
        if (ans == -1 || ans == v)
            ans = -1;
        printf("%d\n", ans);
    } else attacked[q[i][1]] = 1;
    return 0;
}