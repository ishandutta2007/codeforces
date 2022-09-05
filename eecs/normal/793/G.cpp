#include <bits/stdc++.h>
using namespace std;

// https://atcoder.github.io/ac-library/production/document_en/maxflow.html
namespace atcoder {
namespace internal {
template <class T> struct simple_queue {
    vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};
} // namespace internal
 
template <class Cap> struct mf_graph {
  public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}
 
    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }
 
    struct edge {
        int from, to;
        Cap cap, flow;
    };
 
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    vector<edge> edges() {
        int m = int(pos.size());
        vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }
 
    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
 
        vector<int> level(_n), iter(_n);
        internal::simple_queue<int> que;
 
        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };
 
        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }
 
    vector<bool> min_cut(int s) {
        vector<bool> visited(_n);
        internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
 
  private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
};
} // namespace atcoder

const int maxn = 10010;
int n, q, tot, rt[maxn << 2];
vector<array<int, 2>> V[maxn << 2];
struct node { int l, r; } t[maxn * 220];
atcoder::mf_graph<int> G(maxn * 220);

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void add(int k, int l, int r, int ql, int qr, array<int, 2> v) {
    if (l >= ql && r <= qr) { V[k].push_back(v); return; }
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
}

void build(int &k, int l, int r) {
    if (l == r) { k = l + n; return; }
    k = ++tot, build(t[k].l, l, mid), build(t[k].r, mid + 1, r);
    G.add_edge(k, t[k].l, n), G.add_edge(k, t[k].r, n);
}

void clear(int &k1, int k2, int l, int r, int ql, int qr) {
    static vector<int> pool;
    if (!k2) return;
    if (pool.empty()) k1 = ++tot;
    else k1 = pool.back(), pool.pop_back();
    t[k1] = t[k2];
    if (l >= ql && r <= qr) { pool.push_back(k1), k1 = 0; return; }
    if (mid >= ql) clear(t[k1].l, t[k2].l, l, mid, ql, qr);
    if (mid < qr) clear(t[k1].r, t[k2].r, mid + 1, r, ql, qr);
    if (!t[k1].l && !t[k1].r) pool.push_back(k1), k1 = 0;
    if (t[k1].l) G.add_edge(k1, t[k1].l, n);
    if (t[k1].r) G.add_edge(k1, t[k1].r, n);
}

int main() {
    scanf("%d %d", &n, &q), tot = 2 * n;
    while (q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        add(1, 1, n, x1, x2, {y1, y2});
    }
    int s = ++tot, t = ++tot;
    for (int i = 1; i <= 2 * n; i++) {
        i <= n ? G.add_edge(s, i, 1) : G.add_edge(i, t, 1);
    }
    function<void(int, int, int)> solve = [&](int k, int l, int r) {
        for (auto &p : V[k]) {
            clear(rt[k], rt[k], 1, n, p[0], p[1]);
        }
        if (l == r) {
            G.add_edge(l, rt[k], 1);
        } else {
            rt[ls] = rt[k], solve(ls, l, mid);
            rt[rs] = rt[k], solve(rs, mid + 1, r);
        }
    };
    build(rt[1], 1, n), solve(1, 1, n);
    printf("%d\n", G.flow(s, t));
    return 0;
}