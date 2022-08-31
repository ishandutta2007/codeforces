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

const int maxn = 510000;
vi cells[4][2 * maxn];

vi &get_cells(int d, int y) {
    return cells[d][y + maxn];
}

struct TState {
    int d;
    pii p;

    bool operator<(const TState &st) const {
        if (d != st.d) return d < st.d;
        return p < st.p;
    }
};

pii dirsgn[] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

int operator*(const pii &a, const pii &b) {
    return a.fi * b.fi + a.se * b.se;
}

pii operator+(const pii &a, const pii &b) {
    return {a.fi + b.fi, a.se + b.se};
}

pii operator-(const pii &a) {
    return {-a.fi, -a.se};
}

int coord(const pii &p, int d) {
    return p * dirsgn[d];
}

pii coords(const pii &p, int d) {
    return {coord(p, d), coord(p, (d + 1) & 3)};
}

pii actual_coords(const TState &st) {
    pii p = coords(st.p, (3 - st.d) & 3);
    p.fi /= 2; p.se /= 2;
    return p;
}

TState change_d(const TState &st, int d) {
    pii p = actual_coords(st);
    return {d, coords(p, d)};
}

TState get_state(const pii &p, int d) {
    return {d, coords(p, d)};
}

void add_obstacle(const pii &p) {
//    cerr << p.fi << ' ' << p.se << '\n';
    forn(d, 4) {
        pii np = coords(p, d);
        get_cells(d, np.se).pb(np.fi);
    }
}

template<class T>
bool isinsorted(const vector<T> &v, const T &x) {
    auto it = lower_bound(all(v), x);
    return it != v.end() && *it == x;
}

bool is_obstacle(const TState &st) {
    return isinsorted(get_cells(st.d, st.p.se), st.p.fi);
}

struct TEvent {
    int x, y1, y2;
    int delta;

    bool operator<(const TEvent &ev) const {
        return x < ev.x;
    }
};

vector<TEvent> evs[2];
int miny[2], maxy[2];

void add_rectangle(int d, pii a, pii b) {
    if (d >= 2) {
        d -= 2;
        a = -a; b = -b;
    }
//    cerr << d << ' ' << a.fi << ' ' << a.se << ' ' << b.fi << ' ' << b.se << '\n';
    if (a > b) swap(a, b);
    int x = a.fi & 1;
    assert(x >= 0 && x <= 1);
    a = a + mp(x, x);
    b = b + mp(x, x);
    assert(a.fi % 2 == 0);
    assert(a.se % 2 == 0);
    assert(b.fi % 2 == 0);
    assert(b.se % 2 == 0);
    a.fi /= 2; a.se /= 2; b.fi /= 2; b.se /= 2;
    evs[x].pb({a.fi, a.se, b.se + 1, 1});
    evs[x].pb({b.fi + 1, a.se, b.se + 1, -1});
    assert(a.se <= b.se);
    uin(miny[x], a.se);
    uax(maxy[x], b.se + 1);
}

TState next_state(TState st) {
    int nx = *lower_bound(all(get_cells(st.d, st.p.se)), st.p.fi) - 2;
    pii stop = {nx, st.p.se};
    add_rectangle(st.d, st.p, stop);
    bool below = is_obstacle({st.d, stop + mp(1, -1)});
    bool above = is_obstacle({st.d, stop + mp(1, 1)});
//    cerr << st.d << ' ' << st.p.fi << ' ' << st.p.se << ' ' << below << ' ' << above << '\n';
    if (below == above) return {st.d ^ 2, {-stop.fi, -stop.se}};
    if (below) return {(st.d + 1) & 3, {stop.se + 1, -stop.fi - 1}};
    return {(st.d + 3) & 3, {-stop.se + 1, stop.fi + 1}};
}

struct TNode {
    int L, R;
    int l, r;
    int val;
    pii mins;
};

TNode t[2 * maxn];
int tc = 0;

pii combine(const pii &a, const pii &b) {
    if (a.fi != b.fi) return min(a, b);
    return {a.fi, a.se + b.se};
}

#define dn TNode &n = t[node]

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, {0, R - L}};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void add_val(int node, int val) {
    dn;
    n.val += val;
    n.mins.fi += val;
}

void push(int node) {
    dn;
    if (!n.val) return;
    add_val(n.l, n.val);
    add_val(n.r, n.val);
    n.val = 0;
}

void add_seg(int node, int L, int R, int x) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        add_val(node, x);
        return;
    }
    add_seg(n.l, L, R, x);
    add_seg(n.r, L, R, x);
    n.mins = combine(t[n.l].mins, t[n.r].mins);
}

i64 unionS(int z) {
    auto &ev = evs[z];
    sort(all(ev));
    int L = miny[z], R = maxy[z];
    tc = 0;
    int root = buildTree(L, R);
    i64 ans = 0;
    int px = 0;
    for (auto e: ev) {
        int dx = e.x - px;
        auto p = t[root].mins;
        int n0 = p.fi ? 0 : p.se;
        ans += 1LL * dx * (R - L - n0);
        add_seg(root, e.y1, e.y2, e.delta);
        px = e.x;
    }
    return ans;
}

void print_actual(TState st) {
    auto p = actual_coords(st);
    cerr << st.d << ' ' << p.fi << ' ' << p.se << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, k;
    cin >> m >> n >> k;
    forn(j, m + 2) {
        add_obstacle({0, j});
        add_obstacle({n + 1, j});
    }
    for1(i, n) {
        add_obstacle({i, 0});
        add_obstacle({i, m + 1});
    }

    forn(i, k) {
        pii p;
        cin >> p.se >> p.fi;
        add_obstacle(p);
    }

    forn(d, 4) forn(x, 2 * maxn) sort(all(cells[d][x]));
//    forn(d, 4) for (auto &[x, v]: cells[d]) assert(is_sorted(all(v)));


    pii st;
    cin >> st.se >> st.fi;
    string dirs;
    cin >> dirs;
    int stdir = (3 * (dirs[0] == 'N')) ^ (dirs[1] == 'W');

    TState state = {stdir, coords(st, stdir)};

    forn(z, 2) miny[z] = 1e9, maxy[z] = -1e9;


    set<TState> vis;
    while (!vis.count(state)) {
        TState nstate = next_state(state);
//        print_actual(state);
//        print_actual(nstate);
//        add_rectangle(state.d, state.p, change_d(nstate, state.d).p);
        vis.insert(state);
        state = nstate;
    }

    cerr << "here\n";

    cout << unionS(0) + unionS(1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}