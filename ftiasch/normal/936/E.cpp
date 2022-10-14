#include <algorithm>
#include <cstdio>
#include <climits>
#include <map>
#include <set>
#include <utility>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

struct Point
{
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    int x, y;
};

bool operator < (const Point& a, const Point& b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

struct Info
{
    int c, d, y;
};

using Set = std::set<std::pair<int, int>>;

const int N = 300000;

int n, id[N], start[N], count[N], size[N], imbl[N];
bool done[N];
Point p[N];
std::map<Point, int> points;
std::vector<int> nodes, tree[N], graph[N];
std::pair<int, int> dis[N];
std::vector<Info> anc[N];
Set stat[N][2];

void update(Set& s, int k, int v)
{
    auto iterator = s.upper_bound(std::make_pair(k, INT_MAX));
    if (iterator != s.begin()) {
        iterator --;
        if (iterator->second <= v) {
            return;
        }
    }
    while (true) {
        iterator = s.lower_bound(std::make_pair(k, INT_MIN));
        if (iterator == s.end() || v > iterator->second) {
            break;
        }
        s.erase(iterator);
    }
    s.emplace(k, v);
}

int query(Set& s, int k) // <= k
{
    auto iterator = s.upper_bound(std::make_pair(k, INT_MAX));
    if (iterator == s.begin()) {
        return 1000000000;
    }
    iterator --;
    return iterator->second;
}

void add_edge(std::vector<int> g[], int x, int y)
{
    g[x].push_back(y);
    g[y].push_back(x);
}

void prepare(int p, int u)
{
    size[u] = count[u], imbl[u] = 0;
    nodes.push_back(u);
    for (int v : tree[u]) {
        if (v != p && !done[v]) {
            prepare(u, v);
            size[u] += size[v];
            imbl[u] = std::max(imbl[u], size[v]);
        }
    }
}

void divide(int root)
{
    nodes.clear();
    prepare(-1, root);
    std::pair<int, int> best(imbl[root], root);
    for (int u : nodes) {
        best = std::min(best, std::make_pair(std::max(imbl[u], size[root] - size[u]), u));
    }
    root = best.second;
    std::vector<int> queue;
    for (int i = start[root]; i < start[root] + count[root]; ++ i) {
        dis[i] = {0, p[i].y};
        queue.push_back(i);
    }
    for (size_t head = 0; head < queue.size(); ++ head) {
        int u = queue[head];
        anc[u].push_back(Info {root, dis[u].first, dis[u].second});
        for (int v : graph[u]) {
            if (!done[id[v]] && dis[v].first == n) {
                dis[v] = {dis[u].first + 1, dis[u].second};
                queue.push_back(v);
            }
        }
    }
    for (int u : queue) {
        dis[u].first = n;
    }

    done[root] = true;
    for (int u : tree[root]) {
        if (!done[u]) {
            divide(u);
        }
    }
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("E.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    std::sort(p, p + n);
    for (int i = 0; i < n; ++ i) {
        points[p[i]] = i;
        if (!(count[id[i] = i ? id[i - 1] + (p[i - 1].x!= p[i].x || p[i - 1].y + 1 != p[i].y) : 0] ++)) {
            start[id[i]] = i;
        }
        for (int k = 0; k < 2; ++ k) {
            auto q = p[i];
            (k ? q.x : q.y) --;
            auto iterator = points.find(q);
            if (iterator != points.end()) {
                auto j = iterator->second;
                if (k) {
                    add_edge(tree, id[i], id[j]);
                }
                add_edge(graph, i, j);
            }
        }
    }
    for (int i = 0; i <= id[n - 1]; ++ i) {
        std::sort(ALL(tree[i]));
        tree[i].erase(std::unique(ALL(tree[i])), tree[i].end());
    }
    for (int i = 0; i < n; ++ i) {
        dis[i].first = n;
    }
    divide(0);
    int q;
    scanf("%d", &q);
    while (q --) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        int id = points[{x, y}];
        if (t == 1) {
            for (auto&& info : anc[id]) {
                update(stat[info.c][0], info.y, info.d - info.y);
                update(stat[info.c][1], -info.y, info.d + info.y);
            }
        } else {
            int result = 1000000000;
            for (auto&& info : anc[id]) {
                result = std::min(result, query(stat[info.c][0], info.y) + info.y + info.d);
                result = std::min(result, query(stat[info.c][1], -info.y) - info.y + info.d);
            }
            printf("%d\n", result < n ? result : -1);
        }
    }
}