#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;

int costs[N];

struct magic {
    bool bad;
    int left, right, cost_mid;

    magic(bool bad = true, int left = 0, int right = 0, int cost_mid = 0) :
        bad(bad), left(left), right(right), cost_mid(cost_mid) {}
};

int total(magic a) {
    if (a.bad == false) {
        return a.cost_mid + costs[a.left] + costs[a.right];
    } else {
        return costs[a.left];
    }
}

magic rev(magic a) {
    return magic(a.bad, a.right, a.left, a.cost_mid);
}

magic operator+(magic l, magic r) {
    if (l.bad && r.bad) {
        return magic(true, l.left + r.left, l.right + r.right, 0);
    } else if (l.bad) {
        return magic(false, l.left + r.left, r.right, r.cost_mid);
    } else if (r.bad) {
        return magic(false, l.left, l.right + r.right, l.cost_mid);
    } else {
        return magic(false, l.left, r.right, l.cost_mid + r.cost_mid +
                                                costs[l.right + r.left]);
    }
}

void upd(vector<magic> & tree, int v, int vl, int vr, int i) {
    if (vl > i || vr <= i) {
        return;
    } else if (vl == vr - 1) {
        tree[v] = magic(true, 1, 1, 0);
    } else {
        int mid = (vl + vr) / 2;
        upd(tree, v * 2 + 1, vl, mid, i);
        upd(tree, v * 2 + 2, mid, vr, i);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
}

magic get(vector<magic> & tree, int v, int vl, int vr, int l, int r) {
    if (vl >= r || vr <= l) {
        return magic();
    } else if (vl >= l && vr <= r) {
        return tree[v];
    } else {
        int mid = (vl + vr) / 2;
        return get(tree, v * 2 + 1, vl, mid, l, r) + get(tree, v * 2 + 2, mid, vr, l, r);
    }
}

void build(vector<magic> & tree, int v, int vl, int vr) {
    if (vr <= vl) {
        return;
    } else if (vr == vl + 1) {
        tree[v] = magic(false, 0, 0, 0);
    } else {
        int mid = (vl + vr) / 2;
        build(tree, v * 2 + 1, vl, mid);
        build(tree, v * 2 + 2, mid, vr);
        tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
    }
}

struct query {
    int i;
    int v, u, l;
    query(int i, int v, int u, int l) : i(i), v(v), u(u), l(l) {}

    bool operator< (query b) {
        return l < b.l;
    }
};

struct edge{
    int v, u, w;
    edge(int v, int u, int w) : v(v), u(u), w(w) {}

    bool operator< (edge b) {
        return w < b.w;
    }
};

int n, q, t_in[N], t_out[N], t, par[N], sz[N];
int up[17][N];
int ans[N];
int path[N], place[N], path_sizes[N], cnt_paths, last[N];
vector<int> graph[N];
vector<edge> edges;
vector<query> queries;
vector<magic> trees[N];

void dfs(int v, int p) {
    t_in[v] = t++;
    par[v] = p;
    for (auto i : graph[v]) {
        if (i != p) {
            dfs(i, v);
        }
    }
    t_out[v] = t;
    sz[v] = t_out[v] - t_in[v];
}

inline bool is_upper(int a, int b) {
    return t_in[a] <= t_in[b] && t_out[a] >= t_out[b];
}

int lcp(int a, int b) {
    if (is_upper(a, b)) {
        return a;
    }
    for (int i = 16; i >= 0; i--) {
        if (!is_upper(up[i][a], b)) {
            a = up[i][a];
        }
    }
    return par[a];
}

magic get_ans_up(int a, int b) {
    magic ans(true, 0, 0, 0);
    while (a != 1 && is_upper(b, last[path[a]])) {
        ans = ans + get(trees[path[a]], 0, 0, path_sizes[path[a]], place[a], path_sizes[path[a]]);
        a = last[path[a]];
    }
    if (a != b) {
        ans = ans + get(trees[path[a]], 0, 0, path_sizes[path[a]], place[a], place[b]);
    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &q);

    for (int i = 1; i <= n - 1; i++) {
        scanf("%d", costs + i);
    }

    for (int i = 0; i < n - 1; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        graph[v].pb(u);
        graph[u].pb(v);
        edges.eb(v, u, w);
    }

    for (int i = 0; i < q; i++) {
        int v, u, l;
        scanf("%d%d%d", &v, &u, &l);
        queries.eb(i, v, u, l);
    }

    sort(all(edges));
    sort(all(queries));
    reverse(all(edges));
    reverse(all(queries));

    dfs(1, 0);
    t_in[0] = -INF;
    t_out[0] = INF;

    for (int i = 1; i <= n; i++) {
        up[0][i] = par[i];
    }
    for (int i = 1; i < 17; i++) {
        for (int j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (auto j : graph[i]) {
            if (j != par[i] && sz[i] <= sz[j] * 2) {
                flag = false;
            }
        }
        if (flag) {
            for (int cur = i; flag; cur = par[cur]) {
                path[cur] = cnt_paths;
                place[cur] = path_sizes[cnt_paths]++;
                last[cnt_paths] = par[cur];
                if (par[cur] == 1 || sz[par[cur]] > sz[cur] * 2) {
                    flag = false;
                }
            }
            cnt_paths++;
        }
    }

    for (int i = 0; i < cnt_paths; i++) {
        trees[i].resize(path_sizes[i] * 4 + 2);
        build(trees[i], 0, 0, path_sizes[i]);
    }

    int j = 0;
    for (auto i : queries) {
        while (j < edges.size() && edges[j].w >= i.l) {
            int v = 0;
            if (is_upper(edges[j].u, edges[j].v)) {
                v = edges[j].v;
            } else {
                v = edges[j].u;
            }
            int path_num = path[v];
            upd(trees[path_num], 0, 0, path_sizes[path_num], place[v]);
            j++;
        }

        int lcp_vu = lcp(i.v, i.u);
        magic cur_ans = get_ans_up(i.v, lcp_vu) + rev(get_ans_up(i.u, lcp_vu));

        ans[i.i] = total(cur_ans);
    }

    for (int i = 0; i < q; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}