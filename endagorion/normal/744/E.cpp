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

const int Z = 2;
const i64 P[Z] = {998244353, 987654323};
const i64 Q[Z] = {239, 71};

const int maxn = 100001;
i64 pq[Z][maxn];

struct Hash {
    int len;
    i64 h[Z];

    Hash() {
        len = 0;
        forn(z, Z) h[z] = 0;
    }

    Hash(char c) {
        len = 1;
        forn(z, Z) h[z] = c;
    }

    Hash operator+(const Hash &r) const {
        Hash res;
        res.len = len + r.len;
        forn(z, Z) {
            res.h[z] = (h[z] * pq[z][r.len] + r.h[z]) % P[z];
        }
        return res;
    }

    Hash operator-(const Hash &r) const {
        Hash res;
        res.len = len - r.len;
        forn(z, Z) {
            res.h[z] = (h[z] - r.h[z] * pq[z][len - r.len]) % P[z];
            if (res.h[z] < 0) res.h[z] += P[z];
        }
        return res;
    }

    bool operator<(const Hash &r) const {
        if (len != r.len) return len < r.len;
        forn(z, Z) if (h[z] != r.h[z]) return h[z] < r.h[z];
        return false;
    }
};

vector<Hash> phash(const string &s) {
    vector<Hash> ph(s.size() + 1);
    forn(i, s.size()) ph[i + 1] = ph[i] + Hash(s[i]);
    return ph;
}

vvi e, re;
vi ord;

void dfs0(int v, vi &vis) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int u: e[v]) {
        dfs0(u, vis);
    }
    ord.pb(v);
}

void dfs_re(int v, int c, vi &res, vi &vis) {
    if (vis[v]) return;
    vis[v] = 1;
    res[v] = c;
    for (int u: re[v]) dfs_re(u, c, res, vis);
}

vi scc() {
    int n = e.size();
    ord.clear();
    re.clear();
    re.resize(n);
    forn(i, n) for (int j: e[i]) re[j].pb(i);
    vi vis(n);
    forn(i, n) dfs0(i, vis);
    reverse(all(ord));

    vi res(n);
    int C = 0;
    vis.assign(n, 0);
    for (int v: ord) {
        if (!vis[v]) dfs_re(v, C++, res, vis);
    }
    return res;
}

struct TEdge {
    int to;
    int id;
};

vvi pid, sid;
int V;

vector<vector<TEdge> > buildGraph(vector<string> s) {
    int n = s.size();

    vector<vector<Hash> > ph;
    forn(i, n) ph.pb(phash(s[i]));
    map<Hash, int> en;
    auto get_id = [&](const Hash &h) {
        if (en.count(h)) return en[h];
        int z = en.size();
        en[h] = z;
//        cerr << z << ' ' << h.len << '\n';
        return z;
    };

    pid.resize(n); sid.resize(n);
    forn(i, s.size()) {
//        cerr << "Adding " << i << ' ' << s[i] << '\n';
        pid[i].resize(s[i].size() + 1);
        sid[i].resize(s[i].size() + 1);
        forn(j, s[i].size() + 1) pid[i][j] = get_id(ph[i][j]);
        forn(j, s[i].size() + 1) sid[i][j] = get_id(ph[i].back() - ph[i][(int)s[i].size() - j]);
    }

    V = en.size();
    cerr << V << '\n';
    vector< vector<TEdge> > e;
    e.resize(2 * V);
    forn(z, 2) e[z].pb({z ^ 1, -1});
    for (auto [h, id]: en) {
        forn(i, s.size()) {
            Hash addh = h + ph[i].back();
            if (en.count(addh)) {
                int addid = en[addh];
                forn(z, 2) e[2 * id + z].pb({2 * addid + z, i});
            }

            if (s[i].size() <= h.len) {
                Hash remh = h - ph[i].back();
                if (en.count(remh)) {
                    int remid = en[remh];
                    forn(z, 2) e[2 * id + z].pb({2 * remid + z, i});
                }
            } else {
                Hash remh = ph[i].back() - h;
                if (en.count(remh)) {
                    int remid = en[remh];
                    forn(z, 2) e[2 * id + z].pb({2 * remid + (z ^ 1), i});
                }
            }
        }
    }
    return e;
}

vvi reduce_graph(const vector< vector<TEdge> > &e, int l, int r) {
    vvi newE(e.size());
    forn(i, e.size()) for (auto edge: e[i]) if (edge.id == -1 || edge.id >= l && edge.id < r) newE[i].pb(edge.to);
    return newE;
}


bool is_stable(const vector<string> &s, int l, int r) {
    auto escc = scc();
    fore(i, l, r - 1) for1(j, (int)s[i].size() - 1) {
        int id1 = sid[i][j];
        int id2 = pid[i][s[i].size() - j];
        if (escc[2 * id1] == escc[2 * id2 + 1]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(z, Z) {
        pq[z][0] = 1;
        forn(i, maxn - 1) pq[z][i + 1] = pq[z][i] * Q[z] % P[z];
    }

    int n;
    cin >> n;
    vector<string> s(n);
    forn(i, n) cin >> s[i];

    auto allE = buildGraph(s);

    int ans = 0;
    int R = 0;
    forn(l, n) {
        while (R < n) {
            e = reduce_graph(allE, l, R + 1);
            if (is_stable(s, l, R + 1)) ++R;
            else break;
        }
        ans += R - l;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}