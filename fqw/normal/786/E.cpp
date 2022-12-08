// 16:35 - 17:25
//       - 17:32 - ac
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// {{{
// clang-format off
#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for (int i = int(a); i <= int(b); ++i)
#define irep(i, a, b) for (int i = int(a); i >= int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define popcount __builtin_popcount
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PII> VPI;
typedef vector<PLL> VPL;
template <class T, class S> ostream& operator<<(ostream& os, const pair<T, S>& v) { return os << "(" << v.first << ", " << v.second << ")"; }
template <class T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; repn(i, sz(v)) { if(i) os << ", "; os << v[i]; } return os << "]"; }
template <class T> bool setmax(T& _a, T _b) { if(_a < _b) { _a = _b; return true; } return false; }
template <class T> bool setmin(T& _a, T _b) { if(_b < _a) { _a = _b; return true; } return false; }
template <class T> T gcd(T _a, T _b) { return _b == 0 ? _a : gcd(_b, _a % _b); }
// clang-format on
// }}}

template <class T> class Net {
public:
    Net(int n0, int s, int t)
        : n(n0 + 2),
          original_s(s),
          original_t(t),
          super_s(n),
          super_t(n + 1),
          es(n),
          dis(n) {}

    void* add(int x, int y, T w) {
        assert(x >= 0 && x < n && y >= 0 && y < n);
        Edge *e1, *e2;
        es[x].emplace_back(e1 = new Edge{y, w, nullptr});
        es[y].emplace_back(e2 = new Edge{x, 0, nullptr});
        e1->oppo = e2, e2->oppo = e1;
        return e1;
    }
    void* add(int x, int y, pair<T, T> w) {
        assert(w.fi <= w.se);
        if(w.fi > 0) {
            add(super_s, y, w.fi);
            add(x, super_t, w.fi);
            super_total += w.fi;
        }
        return add(x, y, w.se - w.fi);
    }

    // returns -1 if no solution.
    T compute() {
        if(super_total > 0) {
            add(original_t, original_s, numeric_limits<T>::max());
            LL r = 0, tmp;
            while((tmp = augment(super_s, super_t)) > 0) r += tmp;
            if(r != super_total) return -1;
        }
        T ans = 0, tmp;
        while((tmp = augment(original_s, original_t)) > 0) ans += tmp;
        return ans;
    }

    T flow(void* e) const { return static_cast<Edge*>(e)->oppo->w; }
    bool on_cut(void* e) const {
        return dis[static_cast<Edge*>(e)->oppo->y] > 0 &&
               dis[static_cast<Edge*>(e)->y] == 0;
    }
    VI left() const {
        VI r;
        repn(i, n) if(dis[i] > 0) r.pb(i);
        return r;
    }

private:
    struct Edge {
        int y;
        T w;
        Edge* oppo;
    };
    const int n, original_s, original_t, super_s, super_t;
    T super_total = 0;
    vector<vector<unique_ptr<Edge>>> es;
    VI dis;

    T augment(int s, int t) {
        dis.resize(n);
        fill(all(dis), 0);
        dis[s] = 1;
        queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int x = que.front();
            que.pop();
            for(const auto& e : es[x]) {
                if(e->w > 0 && dis[e->y] == 0) {
                    dis[e->y] = dis[x] + 1;
                    que.push(e->y);
                }
            }
        }
        if(dis[t] == 0) return 0;

        vector<size_t> ce(n);
        const function<T(int, T)> dfs = [&](int x, T rest) {
            if(x == t) return rest;
            T r = 0;
            for(size_t& i = ce[x]; i < es[x].size(); ++i) {
                const auto& e = es[x][i];
                if(e->w > 0 && dis[e->y] > dis[x]) {
                    T cur = dfs(e->y, min(e->w, rest));
                    e->w -= cur, e->oppo->w += cur;
                    r += cur, rest -= cur;
                    if(rest == 0) break;
                }
            }
            return r;
        };
        return dfs(s, numeric_limits<T>::max());
    }
};

const int LOG = 16;
const int N = 20000;
const int M = 10000;
const int INF = 1 << 29;

int up[N][LOG], dep[N];
VI es[N];
int ea[N], eb[N];
int from[M], to[M], lca[M];
int n, m;

void init() {
    scanf("%d%d", &n, &m);
    repn(i, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b), --a, --b;
        ea[i] = a, eb[i] = b;
        es[a].pb(b), es[b].pb(a);
    }
    repn(i, m) {
        scanf("%d%d", &from[i], &to[i]);
        --from[i], --to[i];
    }

    const function<void(int, int, int)> dfs = [&](int x, int fa, int d) {
        up[x][0] = fa, dep[x] = d;
        for(int i = 0; up[x][i] > 0; ++i) {
            up[x][i + 1] = up[up[x][i]][i];
        }
        for(int y : es[x]) {
            if(y != fa) {
                dfs(y, x, d + 1);
            }
        }
    };
    dfs(0, -1, 0);

    const auto go_up = [&](int x, int d) {
        repn(i, LOG) if(d & (1 << i)) { x = up[x][i]; }
        return x;
    };
    const auto get_lca = [&](int x, int y) {
        int d = dep[x] - dep[y];
        if(d > 0) {
            x = go_up(x, d);
        } else {
            y = go_up(y, -d);
        }
        irepn(i, LOG) if(up[x][i] != up[y][i]) {
            x = up[x][i];
            y = up[y][i];
        }
        if(x != y) x = up[x][0];
        return x;
    };
    repn(i, m) lca[i] = get_lca(from[i], to[i]);
}

int main() {
    init();
    // printf("#1\n");

    vector<VPI> dependency(m);
    // VI max_used(n, -1);
    const auto add_dependency = [&](int i, int x, int j) {
        dependency[i].pb(mp(x, j));
        // setmax(max_used[x], j);
    };
    repn(i, m) {
        int x = from[i], y = to[i], z = lca[i];
        irepn(j, LOG) if((dep[x] - dep[z]) & (1 << j)) {
            add_dependency(i, x, j);
            x = up[x][j];
        }
        irepn(j, LOG) if((dep[y] - dep[z]) & (1 << j)) {
            add_dependency(i, y, j);
            y = up[y][j];
        }
    }
    vector<VI> id(n, VI(LOG));
    int cur = m;
    repn(x, n) repn(i, LOG) { id[x][i] = cur++; }

    // printf("#2\n");
    // cout << dependency << endl;

    const int s = cur, t = cur + 1;
    Net<int> net(cur + 2, s, t);
    repn(i, m) for(const auto& d : dependency[i]) {
        net.add(i, id[d.fi][d.se], INF);
    }
    repn(x, n) repn(i, LOG - 1) if(up[x][i] >= 0) {
        net.add(id[x][i + 1], id[x][i], INF);
        net.add(id[x][i + 1], id[up[x][i]][i], INF);
    }
    vector<void *> begin(m), end(n);
    repn(i, m) begin[i] = net.add(s, i, 1);
    repn(x, n) end[x] = net.add(id[x][0], t, 1);

    // printf("#3\n");

    int ans = net.compute();
    printf("%d\n", ans);
    const auto print = [](VI a) {
        printf("%d", sz(a));
        for(int x : a) printf(" %d", x + 1);
        printf("\n");
    };
    VI l, r;
    repn(i, m) if(net.on_cut(begin[i]) > 0) l.pb(i);
    repn(i, n - 1) {
        int x = (dep[ea[i]] > dep[eb[i]] ? ea[i] : eb[i]);
        if(net.on_cut(end[x]) > 0) r.pb(i);
    }
    print(l), print(r);

    return 0;
}