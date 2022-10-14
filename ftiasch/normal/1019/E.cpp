#include <bits/stdc++.h>

using LL = long long;

struct Edge
{
    int v, a, b;
};

struct Line
{
    Line(LL a = 0, LL b = 0) : a(a), b(b) {}

    LL at(LL x) const { return a * x + b; }

    LL a, b;
};

bool operator <(const Line& u, const Line& v) {
    return u.a == v.a ? u.b < v.b : u.a < v.a;
}

using LineList = std::vector<Line>;

const int N = 100000;
const int M = 1000000;

int n, m, size[N], imbl[N];
bool resolved[N];
std::vector<int> vertices;
std::vector<Edge> edges[N];
Line tree[M << 1];

void prepare(int p, int u)
{
    size[u] = 1;
    imbl[u] = 0;
    vertices.push_back(u);
    for (auto&& e : edges[u]) {
        if (e.v != p && !resolved[e.v]) {
            prepare(u, e.v);
            size[u] += size[e.v];
            imbl[u] = std::max(imbl[u], size[e.v]);
        }
    }
}

struct Cmp
{
    bool operator()(LineList* a, LineList* b) const {
        return a->size() > b->size();
    }
};

void dfs(LineList& lst, int p, int u, LL a, LL b)
{
    lst.push_back(Line { a, b });
    for (auto&& e : edges[u]) {
        if (e.v != p && !resolved[e.v]) {
            dfs(lst, u, e.v, a + e.a, b + e.b);
        }
    }
}

int get_id(int l, int r)
{
    return l + r | l != r;
}

void update(int l, int r, Line u)
{
    auto& v = tree[get_id(l, r)];
    if (u.at(l) > v.at(l)) {
        std::swap(u, v);
    }
    if (l < r && u.at(r) > v.at(r)) {
        int m = l + r >> 1;
        if (u.at(m) > v.at(m)) {
            std::swap(u, v);
            update(l, m, u);
        } else {
            update(m + 1, r, u);
        }
    }
}

void merge(const LineList& u, const LineList& v, int ub, int ue, int vb, int ve, int l, int r)
{
    int m = l + r >> 1;
    std::pair<LL, int> ubest { -1, 0 }, vbest { -1, 0 };
    for (int z = ub; z < ue; ++ z) {
        ubest = std::max(ubest, std::make_pair(u[z].at(m), z));
    }
    for (int z = vb; z < ve; ++ z) {
        vbest = std::max(vbest, std::make_pair(v[z].at(m), z));
    }
    if (l == r || (ub + 1 == ue && vb + 1 == ve)) {
        auto&& x = u[ubest.second];
        auto&& y = v[vbest.second];
        update(l, r, Line { x.a + y.a, x.b + y.b });
    } else {
        merge(u, v, ub, ubest.second + 1, vb, vbest.second + 1, l, m);
        merge(u, v, ubest.second, ue, vbest.second, ve, m + 1, r);
    }
}

void divide(int root)
{
    vertices.clear();
    prepare(-1, root);
    std::pair<int, int> best { imbl[root], root };
    for (int v : vertices) {
        best = std::min(best, std::make_pair(std::max(imbl[v], size[root] - size[v]), v));
    }
    root = best.second;
    resolved[root] = true;
    std::priority_queue<LineList*, std::vector<LineList*>, Cmp> pq;
    pq.emplace(new LineList { Line {0, 0} });
    for (auto&& e : edges[root]) {
        if (!resolved[e.v]) {
            auto l = new LineList {};
            dfs(*l, root, e.v, e.a, e.b);
            pq.emplace(l);
        }
    }
    while (pq.size() > 1) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        std::sort(a->begin(), a->end());
        std::sort(b->begin(), b->end());
        merge(*a, *b, 0, a->size(), 0, b->size(), 0, m - 1);
        for (auto&& l : *a) {
            b->push_back(l);
        }
        delete a;
        pq.emplace(b);
    }
    delete pq.top();
    for (auto&& e : edges[root]) {
        if (!resolved[e.v]) {
            divide(e.v);
        }
    }
}

LL query(int l, int r, int x)
{
    int m = l + r >> 1;
    return std::max(tree[get_id(l, r)].at(x), l == r ? 0 : (x <= m ? query(l, m, x) : query(m + 1, r, x)));
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("E.in", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0, u, v, a, b; i < n - 1; ++ i) {
        scanf("%d%d%d%d", &u, &v, &a, &b);
        u --; v --;
        edges[u].push_back(Edge { v, a, b });
        edges[v].push_back(Edge { u, a, b });
    }
    divide(0);
    for (int i = 0; i < m; ++ i) {
        printf("%lld%c", query(0, m - 1, i), " \n"[i == m - 1]);
    }
}