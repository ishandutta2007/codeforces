// 20:08 - 21:04 - wa sample
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

class Hash {
    static constexpr LL P1 = 911, M1 = LL(1e9) + 7;
    static constexpr LL P2 = 127, M2 = LL(1e9) + 9;
    static VL p1, p2, ip1, ip2;

    friend struct hash<Hash>;
    LL h1, h2;
    int size;

    Hash(LL h1, LL h2, int size)
        : h1((h1 % M1 + M1) % M1), h2((h2 % M2 + M2) % M2), size(size) {}

public:
    static void init(int n) {
        const auto pow = [](LL a, LL b, LL mod) {
            LL r = 1;
            for(; b > 0; b >>= 1, a = a * a % mod) {
                if(b & 1) r = r * a % mod;
            }
            return r;
        };
        p1.resize(n + 1), ip1.resize(n + 1);
        p2.resize(n + 1), ip2.resize(n + 1);
        p1[0] = p2[0] = 1;
        rep(i, 1, n) {
            p1[i] = p1[i - 1] * P1 % M1;
            p2[i] = p2[i - 1] * P2 % M2;
        }
        ip1[n] = pow(p1[n], M1 - 2, M1);
        ip2[n] = pow(p2[n], M2 - 2, M2);
        irep(i, n, 1) {
            ip1[i - 1] = ip1[i] * P1 % M1;
            ip2[i - 1] = ip2[i] * P2 % M2;
        }
    }

    Hash() : Hash(0, 0, 0) {}
    explicit Hash(int ch) : Hash(ch + 1, ch + 1, 1) {}

    bool operator==(const Hash& b) const { return h1 == b.h1 && h2 == b.h2; }
    Hash operator+(const Hash& b) const {
        return Hash(h1 * p1[b.size] + b.h1, h2 * p2[b.size] + b.h2,
                    size + b.size);
    }
    Hash remove_l(const Hash& b) const {
        return Hash(h1 - b.h1 * p1[size - b.size],
                    h2 - b.h2 * p2[size - b.size], size - b.size);
    }
    Hash remove_r(const Hash& b) const {
        return Hash((h1 - b.h1) * ip1[b.size], (h2 - b.h2) * ip2[b.size],
                    size - b.size);
    }
};
VL Hash::p1, Hash::p2, Hash::ip1, Hash::ip2;
namespace std {
template <> struct hash<Hash> {
    size_t operator()(const Hash& h) const { return h.h1 ^ h.h2; }
};
}

const int N = 20000;
const int LOG = 16;

struct Edge {
    int y, ch, *valid;
};

struct Query {
    int y, i;
};

vector<Edge> es[N];
vector<Query> qs[N];
map<PII, int> e2c;
int n;

int up[N][LOG], dep[N];
Hash hu[N], hd[N];

void prepare(int x, int fa, int _dep, Hash _hu, Hash _hd) {
    dep[x] = _dep, hu[x] = _hu, hd[x] = _hd;
    fillchar(up[x], -1);
    up[x][0] = fa;
    for(int i = 0; up[x][i] >= 0; ++i) up[x][i + 1] = up[up[x][i]][i];
    for(const auto& e : es[x]) {
        if(e.y != fa) {
            prepare(e.y, x, _dep + 1, Hash(e.ch) + _hu, _hd + Hash(e.ch));
        }
    }
}

int go_up(int x, int d) {
    repn(i, LOG) if(d & (1 << i)) x = up[x][i];
    return x;
}

int lca(int x, int y) {
    int d = dep[x] - dep[y];
    if(d > 0) {
        x = go_up(x, d);
    } else {
        y = go_up(y, -d);
    }
    irepn(i, LOG) if(up[x][i] != up[y][i]) { x = up[x][i], y = up[y][i]; }
    if(x != y) {
        x = up[x][0], y = up[y][0];
    }
    assert(x == y);
    return x;
}

int dis(int x, int y) { return dep[x] + dep[y] - dep[lca(x, y)] * 2; }

int go(int x, int y, int d) {
    if(d <= dep[x] - dep[lca(x, y)]) {
        return go_up(x, d);
    } else {
        return go_up(y, dis(x, y) - d);
    }
}

int next(int x, int y) { return go(x, y, 1); }

int next_ch(int x, int y) { return e2c[mp(x, next(x, y))]; }

Hash get_hash(int x, int y) {
    int z = lca(x, y);
    return hu[x].remove_r(hu[z]) + hd[y].remove_l(hd[z]);
}

int compare(int x1, int y1, int x2, int y2) {
    int d1 = dis(x1, y1), d2 = dis(x2, y2);
    int le = 0, ri = min(d1, d2);
    while(le < ri) {
        int mid = (le + ri + 1) / 2;
        if(get_hash(x1, go(x1, y1, mid)) == get_hash(x2, go(x2, y2, mid))) {
            le = mid;
        } else {
            ri = mid - 1;
        }
    }
    if(le == d1 && le == d2) {
        return 0;
    } else if(le == d1) {
        return -1;
    } else if(le == d2) {
        return 1;
    }
    int z1 = go(x1, y1, le), z2 = go(x2, y2, le);
    assert(z1 != y1 && z2 != y2);
    int c1 = next_ch(z1, y1), c2 = next_ch(z2, y2);
    assert(c1 != c2);
    return c1 < c2 ? -2 : 2;
}

class Trie {
    struct Node {
        int val = 0, sum = 0, lt = 0;
        Node* child[26] = {nullptr};
    };
    Node* root;
    unordered_map<Hash, Node*> h2n;

    Node* add(Node* cur, int x, int fa) {
        if(!cur) cur = new Node();
        ++cur->val;
        for(const auto& e : es[x]) {
            if(*e.valid && e.y != fa) {
                cur->child[e.ch] = add(cur->child[e.ch], e.y, x);
            }
        }
        return cur;
    }

    void prepare(Node* cur, int lt, Hash h) {
        h2n[h] = cur;
        cur->lt = lt;
        cur->sum = cur->val;
        lt += cur->val;
        repn(ch, 26) if(cur->child[ch]) {
            prepare(cur->child[ch], lt, h + Hash(ch));
            cur->sum += cur->child[ch]->sum;
            lt += cur->child[ch]->sum;
        }
    }

public:
    Trie() : root(new Node()) {}

    void add(int x, int fa, int ch) {
        root->child[ch] = add(root->child[ch], x, fa);
    }
    void prepare() { prepare(root, 0, Hash()); }

    int count() const { return root->sum; }
    int count_lt(int x, int y) const {
        int le = 0, ri = dis(x, y);
        while(le < ri) {
            int mid = (le + ri + 1) / 2;
            if(h2n.count(get_hash(x, go(x, y, mid)))) {
                le = mid;
            } else {
                ri = mid - 1;
            }
        }
        int z = go(x, y, le);
        Node* cur = h2n.find(get_hash(x, z))->se;
        int r = cur->lt;
        if(z != y) {
            int ch = next_ch(z, y);
            r += cur->val;
            repn(i, ch) if(cur->child[i]) r += cur->child[i]->sum;
        }
        return r;
    }
};

pair<int, VI> find_center(int seed) {
    VI xs, ss, ms;
    const function<int(int, int)> dfs = [&](int x, int fa) {
        int s = 1, m = 0;
        for(const auto& e : es[x]) {
            if(*e.valid && e.y != fa) {
                int sy = dfs(e.y, x);
                s += sy, setmax(m, sy);
            }
        }
        xs.pb(x), ss.pb(s), ms.pb(m);
        return s;
    };
    dfs(seed, -1);
    repn(i, sz(xs)) setmax(ms[i], sz(xs) - ss[i]);
    int j = 0;
    repn(i, sz(xs)) if(ms[i] < ms[j]) j = i;
    return mp(xs[j], xs);
}

void solve(int seed, VI* ans) {
    int center;
    VI xs;
    tie(center, xs) = find_center(seed);

    static Trie sub_tr[N];
    Trie tr;
    for(const auto& e : es[center]) {
        if(*e.valid) {
            sub_tr[e.y] = Trie();
            sub_tr[e.y].add(e.y, center, e.ch);
            sub_tr[e.y].prepare();
            tr.add(e.y, center, e.ch);
        }
    }
    tr.prepare();
    for(const int x : xs) {
        for(const auto& q : qs[x]) {
            const int y = q.y;
            int cmp = compare(x, center, x, y);
            if(cmp == -2) {
                assert(x != center);
                int sub_x = next(center, x);
                (*ans)[q.i] += sz(xs) - sub_tr[sub_x].count();
            } else if(cmp == -1) {
                const int z = go(x, y, dis(x, center));
                (*ans)[q.i] += tr.count_lt(z, y);
                if(x != center) {
                    (*ans)[q.i] += 1;
                    int sub_x = next(center, x);
                    (*ans)[q.i] -= sub_tr[sub_x].count_lt(z, y);
                }
            }
        }
    }

    for(const auto& e : es[center]) {
        if(*e.valid) {
            *e.valid = false;
            solve(e.y, ans);
        }
    }
}

int main() {
    Hash::init(N + 10);

    int q;
    scanf("%d%d", &n, &q);
    VI valid(n - 1, 1);
    repn(i, n - 1) {
        int a, b;
        char s[5];
        scanf("%d%d%s", &a, &b, s);
        int ch = int(s[0] - 'a');
        --a, --b;
        es[a].pb(Edge{b, ch, &valid[i]});
        es[b].pb(Edge{a, ch, &valid[i]});
        e2c[mp(a, b)] = e2c[mp(b, a)] = ch;
    }
    repn(i, q) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        qs[a].pb(Query{b, i});
    }

    prepare(0, -1, 0, Hash(), Hash());

    VI ans(q);
    solve(0, &ans);
    repn(i, q) printf("%d\n", ans[i]);
    return 0;
}