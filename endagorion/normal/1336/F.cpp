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

const int maxn = 210000;
const int LOG = 20;
vi e[maxn], te[maxn];
int sz[maxn], h[maxn];
int tin[maxn], tout[maxn];
int up[LOG + 1][maxn];

int n, m;

void dfsw(int v, int p) {
    sz[v] = 1;
    if (v != p) e[v].erase(find(all(e[v]), p));
    for (int u: e[v]) {
        h[u] = h[v] + 1;
        dfsw(u, v);
        sz[v] += sz[u];
    }
    sort(all(e[v]), [&](int u, int w){return sz[u] > sz[w];});
}

int T = 0;

int ord[maxn];

void dfs0(int v) {
    tin[v] = T++;
    ord[tin[v]] = v;
    for (int u: e[v]) {
        dfs0(u);
        te[tin[v]].pb(tin[u]);
        up[0][tin[u]] = tin[v];
    }
    tout[v] = T;
}

void apply_tin(int *v) {
    vi res(n);
    forn(i, n) res[tin[i]] = v[i];
    forn(i, n) v[i] = res[i];
}

void build_up() {
    forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][up[j][v]];
}

int jmp(int v, int h) {
//    cerr << v << " ^ " << h << " = ";
    forn(j, LOG) {
        if (!((h >> j) & 1)) continue;
        v = up[j][v];
    }
//    cerr << v << '\n';
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = jmp(v, h[v] - h[u]);
    if (v == u) return v;
    ford(j, LOG) {
        int vv = up[j][v], uu = up[j][u];
        if (vv != uu) v = vv, u = uu;
    }
    return up[0][v];
}

int towards(int v, int u) {
//    cerr << "T " << v << ' ' << u << '\n';
//    cerr << tout[v] << ' ' << tout[u] << '\n';
    assert(u > v && tout[u] <= tout[v]);
    return *--upper_bound(all(te[v]), u);
}

int vert[maxn];
map<int, vector<pii> > qs[maxn];

i64 sum_vert(int v) {
    i64 ans = 0;
    for (int u: te[v]) {
        ans += sum_vert(u);
        vert[v] += vert[u];
    }
//    cerr << v << ' ' << vert[v] << '\n';
    return ans + 1LL * vert[v] * (vert[v] - 1) / 2;
}

typedef pair<int, pii> Event;

struct VSet {
    vi vs;
    int nv;
    i64 sum;
    map<int, int> cnt;
    map<int, vi> insts;
    set<Event> evs;

    int lvl;

    Event make_event(int i, int j) {
        if (i >= j) {
            cerr << i << ' ' << j << '\n';
            assert(false);
        }
        return {h[lca(vs[i], vs[j])], {i, j}};
    }

    template<class It>
    void init(It first, It last) {
        sum = 0;
        vs.clear();
        cnt.clear();
        evs.clear();
        insts.clear();
        lvl = 1e9;
        int L = last - first;
        nv = L;
//        cerr << "init, " << L << " elems\n";
        vs.resize(L);
        forn(i, L) vs[i] = (first + i)->se;
        sort(all(vs));
        forn(i, L) {
            ++cnt[i];
            if (i) evs.insert(make_event(i - 1, i));
            insts[vs[i]].pb(i);
        }
//        cerr << "done\n";
    }

    int repr(int i) {
        if (cnt.empty() || i < cnt.begin()->fi) return -1;
        return (--cnt.upper_bound(i))->fi;
    }

    void erase_cnt(int i) {
        auto it = cnt.find(i);
        toggle_event(it, false);
        toggle_event(++it, false);
        cnt.erase(i);
        toggle_event(cnt.upper_bound(i), true);
    }

    void execute(Event ev) {
        evs.erase(ev);
        if (cnt.empty()) return;
        auto [i, j] = ev.se;
        lvl = ev.fi;
//        cerr << "exec " << ord[vs[i]] << ' ' << ord[vs[j]] << '@' << ev.fi << '\n';
        i = repr(i); j = repr(j);
        if (i == j || i == -1 || j == -1) return;
        sum += 1LL * cnt[i] * cnt[j];
        cnt[i] += cnt[j];
        erase_cnt(j);
//        cerr << "sum = " << sum << '\n';
    }

    template<class It> 
    void toggle_event(It it, bool add) {
        if (it == cnt.begin() || it == cnt.end()) return;
        int i = it->fi;
        int j = (--it)->fi;
//        if (i == j || i == -1 || j == -1) return;
        if (add) evs.insert(make_event(j, i));
        else evs.erase(make_event(j, i));
    }

    void erasev(int v) {
        --nv;
        int i = insts[v].back();
        insts[v].pop_back();
//        cerr << "-- " << v << ' ' << i << '\n';
//        int i = upper_bound(all(vs), v) - vs.begin() - 1;
        i = repr(i);
        sum -= --cnt[i];
        if (!cnt[i]) erase_cnt(i);
    }

    void merge_lvl(int nlvl) {
//        cerr << "M " << nlvl << '\n';
        while (!evs.empty() && evs.rbegin()->fi >= nlvl) {
            execute(*evs.rbegin());
        }
        lvl = nlvl;
    }

    void print() {
        cerr << "sum = " << sum << '\n';
        for (auto [i, c]: cnt) cerr << i << ' ' << c << '\n';
    }
};

template<class It> 
i64 solve_dfs(int v, VSet &vset, It &first, It last, bool init, int h0, int k) {
    if (init) {
        first += vset.nv;
        last = first;
        while (last->fi < tout[v]) ++last;
/*        cerr << ord[v] << ": init with " << last - first << " elems\n";
        for (auto it = first; it != last; ++it) cerr << ord[it->fi] << ' ' << ord[it->se] << "; ";
        cerr << '\n';*/
        vset.init(first, last);
    } else {
        while (first < last && first->fi < v) {
//            cerr << "- " << ord[first->fi] << ' ' << ord[first->se] << '\n';
            vset.erasev(first->se), ++first;
//            vset.print();
        }
        while (first < last && (last - 1)->fi >= tout[v]) {
            --last;
//            cerr << "- " << ord[last->fi] << ' ' << ord[last->se] << '\n';
            vset.erasev(last->se);
//            vset.print();
        }
    }
//    cerr << v << '\n';
    int lvl = h0 + k - (h[v] - h0);
    i64 ans = 0;
    if (lvl > h0) {
        vset.merge_lvl(lvl);
        ans += vset.sum;
//        cerr << ord[v] << '@' << lvl << ' ' << vset.sum << '\n';
    }
    bool heavy = true;
    for (int u: te[v]) {
        if (heavy) {
            ans += solve_dfs(u, vset, first, last, false, h0, k);
            heavy = false;
        } else ans += solve_dfs(u, vset, first, last, true, h0, k);
    }
    return ans;
}

i64 solve(vector<pii> ps, int k) {
    forn(i, n) vert[i] = 0;
    forn(i, n) qs[i].clear();
//    cerr << k << '\n';
    for (auto &[x, y]: ps) {    
        if (x > y) swap(x, y);
        int z = lca(x, y);
//        cerr << x << ' ' << y << ' ' << z << '\n';
//        cerr << h[x] << ' ' << h[y] << ' ' << h[z] << '\n';
        for (int v: {x, y}) {
            if (h[v] - h[z] < k) continue;
            ++vert[v];
            --vert[jmp(v, h[v] - h[z] - k + 1)];
        }
        if (x == z || y == z) continue;
//        cerr << ord[x] << ' ' << ord[y] << ' ' << ord[z] << ": ";
        int xx = towards(z, x), yy = towards(z, y);
//        cerr << ord[xx] << ' ' << ord[yy] << '\n';
        qs[yy][xx].pb({y, x});
    }

    i64 ans = sum_vert(0);
    cerr << "vert " << k << ' ' << ans << '\n';
    forn(u, n) {
        int v = up[0][u];
        for (auto &[w, vps]: qs[u]) {
//            cerr << "S " << ord[u] << ' ' << ord[w] << '\n';
            sort(all(vps));
//            for (auto [x, y]: vps) cerr << ord[x] << ' ' << ord[y] << '\n';
            vps.pb({1e9, 1e9});
            auto it = vps.begin();
            VSet vset;
            vset.nv = 0;
//            cerr << "here\n";
            i64 res = solve_dfs(u, vset, it, vps.begin(), true, h[v], k);
//            cerr << ord[u] << ' ' << ord[w] << ' ' << res << '\n';
            ans += res;
        }
    }

    cerr << k << ' ' << ans << '\n';

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int k;
    cin >> n >> m >> k;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    vector<pii> ps(m);
    for (auto &[x, y]: ps) cin >> x >> y, --x, --y;
    
    dfsw(0, 0);
    dfs0(0);
    apply_tin(sz);
    apply_tin(h);
    apply_tin(tout);

    for (auto &[x, y]: ps) x = tin[x], y = tin[y];

    build_up();

    cout << solve(ps, k) - solve(ps, k + 1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}