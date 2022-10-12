#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

struct scc {
    int components;
    std::vector<int> label;
};

// Labels strongly connected components in reverse topological order.
// That means for any edge u-->v label[u] >= label[v].
scc strongly_connected_components(const std::vector<std::vector<int>>& graph) {
    const int N = int(graph.size());

    int C = 0, V = 0, top = 0;
    std::vector<int> comp(N, -1), inx(N, -1), stack(N + 1, -1);

    auto tarjan = [&](auto&& self, int loc) -> int {
        stack[top++] = loc;
        int low = inx[loc] = V++;
        for (int nbr : graph[loc]) {
            if (inx[nbr] == -1) low = std::min(low, self(self, nbr));
            else if (comp[nbr] == -1) low = std::min(low, inx[nbr]);
        }
        if (low == inx[loc]) {
            while (stack[top] != loc)
                comp[stack[--top]] = C;
            C++;
        }
        return low;
    };

    for (int i = 0; i < N; i++) {
        if (inx[i] == -1)
            tarjan(tarjan, i);
    }
    return { C, comp };
}

template<int MAXV>
std::vector<std::bitset<MAXV>> digraph_reachability(
        const std::vector<std::vector<int>> &graph) {
    int V = int(graph.size());
    assert(V <= MAXV);

    scc s = strongly_connected_components(graph);

    std::vector<std::bitset<MAXV>> component_reachability(s.components);

    for (int v = 0; v < s.components; v++)
        component_reachability[s.label[v]][v] = true;

    std::vector<int> order;
    std::iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
            [&](int u, int v) { return s.label[u] < s.label[v]; });

    for (int u : order)
        for (int v : graph[u])
            component_reachability[s.label[u]]
                |= component_reachability[s.label[v]];

    std::vector<std::bitset<MAXV>> reach(V);
    for (int v = 0; v < V; v++)
        reach[v] = component_reachability[s.label[v]];
    return reach;
}

struct two_sat {
    std::vector<std::vector<int>> graph;

    two_sat(int SZ) : graph(2 * SZ) {}

    int new_var() {
        graph.push_back({});
        graph.push_back({});
        return int(graph.size()) - 1;
    }

    static inline int neg(int a) { return a^1; }

    void implies(int a, int b) {
        if (a < 0 || b < 0) return;
        graph[a].push_back(b);
        graph[neg(b)].push_back(neg(a));
    }

    void assign(int a, int v) {
        if (v) implies(neg(a), a);
        else implies(a, neg(a));
    }
    void constrain_equal(int a, int b) {
        implies(a, b);
        implies(neg(a), neg(b));
    }
    void constrain_not_equal(int a, int b) {
        implies(a, neg(b));
        implies(neg(a), b);
    }
    void constrain_at_most_one(int a, int b) {
        implies(a, neg(b)); // contrapositive is automatic
    }
    void constraint_at_least_one(int a, int b) {
        implies(neg(a), b); // contrapositive is automatic
    }

    int make_or(int a, int b) {
        if (a < 0) return b;
        if (b < 0) return a;
        int v = new_var();
        implies(a, v);
        implies(b, v);
        return v;
    }

    int make_and(int a, int b) {
        if (a < 0) return b;
        if (b < 0) return a;
        int v = new_var();
        implies(v, a);
        implies(v, b);
        return v;
    }

    std::vector<bool> solve() const {
        scc s = strongly_connected_components(graph);
        std::vector<bool> assignment(int(graph.size()) / 2);

        for (int v = 0; v < int(graph.size()); v += 2) {
            if (s.label[v] == s.label[v + 1])
                return {};

            assignment[v / 2] = s.label[v] > s.label[v + 1];
        }
        return assignment;
    }

    // (2 * MAXV)^2 / machine word size
    template<int MAXV>
    std::string classify() const {
        auto reach = digraph_reachability<2 * MAXV>(graph);
        std::string res(int(graph.size()), '?');
        for (int v = 0; v < int(graph.size()); v++) {
            bool n0 = reach[v][neg(v)];
            bool n1 = reach[neg(v)][v];
            if (n0 && n1) return "";
            res[v] = n0 ? '0' : n1 ? '1' : '?';
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, p, M, m; cin >> n >> p >> M >> m;
    two_sat ts(p+M+5);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y; x--, y--;
        ts.constraint_at_least_one(2*x+1, 2*y+1);
    }
    for (int i = 1; i < M; i++)
        ts.implies(2*(p+i+1)+1, 2*(p+i)+1);
    for (int i = 0; i < p; i++) {
        int l, r; cin >> l >> r;
        ts.implies(2*i+1, 2*(p+l)+1);
        ts.implies(2*i+1, 2*(p+r+1));
    }
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--, y--;
        ts.constrain_at_most_one(2*x+1, 2*y+1);
    }
    auto v = ts.solve();
    if (v.empty())
        cout << "-1\n";
    else {
        vector<int> ans;
        int f;
        for (int i = 1; i <= M; i++)
            if (v[p+i] && (i == M || !v[p+i+1]))
                f = i;
        for (int i = 0; i < p; i++)
            if (v[i]) ans.pb(i);
        cout << ans.size() << " " << f << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i]+1 << " \n"[i+1 == ans.size()];
    }
}