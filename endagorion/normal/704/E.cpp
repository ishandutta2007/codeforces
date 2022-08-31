#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct Rat {
    i64 x, y;

    Rat(i64 _x = 0, i64 _y = 1)
        : x(_x)
        , y(_y)
    {
        if (y < 0) x = -x, y = -y;
//        i64 G = GCD(abs(x), abs(y));
//        x /= G; y /= G;
    }

    Rat operator+(const Rat &r) const {
        return Rat(x * r.y + y * r.x, y * r.y);
    }

    Rat operator-(const Rat &r) const {
        return Rat(x * r.y - y * r.x, y * r.y);        
    }

    Rat operator*(const Rat &r) const {
        return Rat(x * r.x, y * r.y);
    }

    Rat operator/(const Rat &r) const {
        assert(r.x);
        return Rat(x * r.y, y * r.x);
    }

    bool operator<(const Rat &r) const {
        return x * r.y < y * r.x;
    }

    bool operator==(const Rat &r) const {
        return x * r.y == y * r.x;
    }

    bool operator>=(const Rat &r) const {
        return x * r.y >= y * r.x;
    }

    bool operator!=(const Rat &r) const {
        return x * r.y != y * r.x;
    }
};

const int maxn = 110000, LOG = 20;
vi e[maxn];
int h[maxn], sz[maxn];
int hldb[maxn], hj[maxn];
int up[LOG + 1][maxn];

struct TEvent {
    Rat t;
    int type;
    i64 id;

    bool operator<(const TEvent &ev) const {
        if (t != ev.t) return t < ev.t;
        if (type != ev.type) return type < ev.type;
        return id < ev.id;
    }
};

vector<TEvent> evs[maxn];


void dfs0(int v, int p) {
    up[0][v] = p;
    sz[v] = 1;
    if (v != p) e[v].erase(find(all(e[v]), p));
    for (int u: e[v]) {
        h[u] = h[v] + 1;
        dfs0(u, v);
        sz[v] += sz[u];
    }
    sort(all(e[v]), [&](int u, int w){return sz[u] > sz[w];});
    if (e[v].empty()) {
        hldb[v] = v;
        hj[v] = 0;
    } else {
        hldb[v] = hldb[e[v][0]];
        for1(i, e[v].size() - 1) {
            int u = e[v][i];
            hj[hldb[u]] = v;
        }
    }
}

int jmp(int v, int h) {
    forn(j, LOG) {
        if (!((h >> j) & 1)) continue;
        v = up[j][v];
    }
    return v;
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = jmp(u, h[u] - h[v]);
    if (u == v) return u;
    ford(j, LOG) {
        int uu = up[j][u], vv = up[j][v];
        if (uu != vv) u = uu, v = vv;
    }
    return up[0][u];
}

ostream &operator<<(ostream &out, const Rat &r) {
    out << r.x;
    if (r.y != 1) out << '/' << r.y;
    return out;
}

vi64 A, B;

Rat CT;

Rat at(int id) {
    return CT * Rat(A[id]) + Rat(B[id]);
}

struct AtComp {
    bool operator()(int i, int j) const {
        return at(i) < at(j);
    }
};

optional<TEvent> collision(int id1, int id2) {
    if (id1 > id2) swap(id1, id2);
    if (A[id1] == A[id2]) return nullopt;
    Rat t(B[id2] - B[id1], A[id1] - A[id2]);
    return TEvent({t, 1, 1000000LL * id1 + id2});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs0(0, 0);
    forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][up[j][v]];

    forn(i, m) {
        int t, c, v, u;
        cin >> t >> c >> v >> u;
        --v; --u;
        int w = lca(v, u);
        int D = h[v] + h[u] - 2 * h[w];
        i64 tatw = c * t + h[v] - h[w];
        bool atw = false;
        {
            int id = A.size();
            A.pb(-c);
            B.pb(h[v] + c * t);
            i64 T = t * c;
            while (v != w) {
                int hid = hldb[v], ht = hj[hid];
                if (h[ht] < h[w]) ht = w;

                evs[hid].pb({Rat(T, c), 0, id});
                T += h[v] - h[ht];
                evs[hid].pb({Rat(T, c), 2, id});

                if (hid == hldb[w]) atw = true;

                v = ht;
            }
        }
        {
            int id = A.size();
            A.pb(c);
            B.pb(h[u] - c * t - D);
            i64 T = c * t + D;
            while (1) {
                int hid = hldb[u], ht = hj[hid];
                if (h[ht] < h[w]) ht = w;

                if (ht == w && u == w) break;

                evs[hid].pb({Rat(T, c), 2, id});
                T -= h[u] - h[ht];
                evs[hid].pb({Rat(T, c), 0, id});

                if (hid == hldb[w]) atw = true;

                u = ht;
            }
        }

        if (!atw) {
            int id = A.size();
            A.pb(0);
            B.pb(h[w]);
            int hid = hldb[w];
            evs[hid].pb({Rat(tatw, c), 0, id});
            evs[hid].pb({Rat(tatw, c), 2, id});
        }

//        assert(atw);
    }

    Rat ans(1000000);
    forn(v, n) {
//        cerr << v << ":\n";
        sort(all(evs[v]));
/*        for (auto ev: evs[v]) {
            cerr << ev.t << ' ' << ev.type << ' ' << ev.id << '\n';
        }*/
        CT = Rat(0);
        set<int, AtComp> ps;

        set<TEvent> sevs(all(evs[v]));
        while (!sevs.empty()) {
            auto ev = *sevs.begin();
            sevs.erase(ev);

            CT = ev.t;

            if (ev.type == 1) {
                if (ev.t < ans) ans = ev.t;
                break;
            }

            if (ev.type == 0) {
                int id = ev.id;
                auto it = ps.lower_bound(id);
                if (it != ps.end() && at(id) == at(*it)) {
                    if (ev.t < ans) ans = ev.t;
                    break;            
                }
                if (it != ps.end() && it != ps.begin()) {
                    auto it2 = it;
                    --it2;
                    auto col = collision(*it, *it2);
                    if (col.has_value()) sevs.erase(*col);
                }
                ps.insert(id);
                it = ++ps.find(id);
                if (it != ps.end()) {
                    auto col = collision(*it, id);
                    if (col.has_value() && col->t >= CT) sevs.insert(*col);
                }
                --it;
                if (it != ps.begin()) {
                    --it;
                    auto col = collision(*it, id);
                    if (col.has_value() && col->t >= CT) sevs.insert(*col);
                }
            }
            if (ev.type == 2) {
                int id = ev.id;
                ps.erase(id);
                auto it = ps.lower_bound(id);
                if (it != ps.end()) {
                    auto col = collision(*it, id);
                    if (col.has_value()) sevs.erase(*col);
                }
                auto it2 = it;
                if (it2 != ps.begin()) {
                    --it2;
                    auto col = collision(*it2, id);
                    if (col.has_value()) sevs.erase(*col);
                    if (it != ps.end()) {
                        auto col = collision(*it2, *it);
                        if (col.has_value() && col->t >= CT) sevs.insert(*col);
                    }
                }
            }
        }
    }

    ld fans = 1.0 * ans.x / ans.y;
    if (fans > 5e5) cout << -1 << '\n';
    else cout << fans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}