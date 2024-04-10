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

const int maxn = 110000;
const i64 P = 1000000000 + 7;

void add(i64 &x, i64 y) {
    (x += y) %= P;
}

vi single[maxn];

struct TEdge {
    int me, to, other;
    int id;
};

vector<TEdge> e[maxn];

pii from_signed(int x) {
    return {abs(x) - 1, x > 0};
}

vi64 operator+(const vi64 &a, const vi64 &b) {
    vi64 c;
    forn(i, a.size()) c[i] = (a[i] + b[i]) % P;
    return c;
}

vi64 operator*(const vi64 &a, const vi64 &b) {
    vi64 c(a.size());
    forn(i, a.size()) forn(j, b.size()) add(c[(i + j) % a.size()], a[i] * b[j]);
    return c;
}

vvi64 psingle(int v) {
    vi cnt(2);
    for (int x: single[v]) cnt[x] ^= 1;
    vvi64 ans(2, vi64(2));
    forn(z, 2) ++ans[z][cnt[z]];
    return ans;
}

int vis[maxn];
int killed[maxn];

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

    forn(i, n) {
        int k;
        cin >> k;
        if (k == 1) {
            int x;
            cin >> x;
            auto [v, z] = from_signed(x);
            single[v].pb(z);
        } else {
            int x, y;
            cin >> x >> y;
            auto [v, zv] = from_signed(x);
            auto [u, zu] = from_signed(y);
            e[v].pb({zv, u, zu, i});
            e[u].pb({zu, v, zv, i});
        }
    }

    vi64 ans = {1, 0};
    forn(v, m) {
        if (e[v].size() >= 2 || vis[v]) continue;
        vvi64 res = psingle(v);
        int u = v;
        while (1) {
            while (!e[u].empty() && killed[e[u].back().id]) e[u].pop_back();
            if (e[u].empty()) break;
            vis[u] = 1;
            auto edge = e[u].back();
            killed[edge.id] = 1;
            e[u].pop_back();
            vvi64 nres(2, vi64(2));
            forn(zv, 2) forn(c, 2) forn(zu, 2) {
                int nc = c ^ (zv == edge.me || zu == edge.other ? 1 : 0);
                add(nres[zu][nc], res[zv][c]);
            }
            u = edge.to;
            res = nres;
        }
        vis[u] = 1;
        if (u != v) forn(z, 2) res[z] = res[z] * psingle(u)[z];
        vi64 sres(2);
        forn(z, 2) forn(c, 2) add(sres[c], res[z][c]);
        ans = ans * sres;
    }

    forn(v, m) {
        if (vis[v]) continue;
        assert(e[v].size() == 2 && single[v].empty());
        int u = v;
        vector<vvi64> res(2, vvi64(2, vi64(2)));
        forn(z, 2) res[z][z] = psingle(v)[z];
        while (!vis[u]) {
            vis[u] = 1;
            while (!e[u].empty() && killed[e[u].back().id]) e[u].pop_back();
            assert(!e[u].empty() && single[u].empty());
            auto edge = e[u].back();
            killed[edge.id] = 1;
            vector<vvi64> nres(2, vvi64(2, vi64(2)));
            forn(zi, 2) forn(zv, 2) forn(c, 2) forn(zu, 2) {
                int nc = c ^ (zv == edge.me || zu == edge.other ? 1 : 0);
                add(nres[zi][zu][nc], res[zi][zv][c]);
            }
            u = edge.to;
            res = nres;
        }

        vi64 sres(2);
        forn(zi, 2) forn(c, 2) add(sres[c], res[zi][zi][c]);
        ans = ans * sres;
    }

    cout << ans[1] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}