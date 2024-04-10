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

bool cmp(pii a, pii b) {
    if (max(a.fi, b.fi) <= 29) return (1 << a.fi) - 1 + a.se < (1 << b.fi) - 1 + b.se;
    return a < b;
}

struct TCmp {
    bool operator()(pair<pii, pii> a, pair<pii, pii> b) const {
        if (cmp(a.fi, b.fi)) return true;
        if (cmp(b.fi, a.fi)) return false;
        return a.se < b.se;
    }
};

const int maxn = 210000, LOG = 20;
const i64 P = 998244353;
vi e[2][maxn];
pii dist[2 * maxn][LOG + 1];

i64 deg(i64 x, i64 d) {
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
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
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[0][u].pb(v);
        e[1][v].pb(u);
    }

    set<pair<pii, pii>, TCmp > q;
    forn(i, 2 * n) forn(j, LOG + 1) dist[i][j] = mp(1e9, 1e9);
    dist[0][0] = mp(0, 0);
    q.insert(mp(dist[0][0], mp(0, 0)));
    while (!q.empty()) {
        auto w = *q.begin();
        q.erase(w);
        auto p = w.se;
        int v = p.fi / 2, z = p.fi & 1;
        int layer = p.se;
        pii d = w.fi;
        for (int u: e[z][v]) {
            pii nd = d;
            ++nd.se;
            pii U = {2 * u + z, layer};
            if (cmp(nd, dist[U.fi][U.se])) {
                q.erase(mp(dist[U.fi][U.se], U));
                dist[U.fi][U.se] = nd;
                q.insert(mp(dist[U.fi][U.se], U));
            }
        }
        {
            pii U = {2 * v + (z ^ 1), min(LOG, layer + 1)};
            pii nd = d;
            ++nd.fi;
            if (cmp(nd, dist[U.fi][U.se])) {
                q.erase(mp(dist[U.fi][U.se], U));
                dist[U.fi][U.se] = nd;
                q.insert(mp(dist[U.fi][U.se], U));
            }
        }
    }

    pii ans = mp(1e9, 1e9);
    forn(z, 2) forn(j, LOG + 1) {
        auto res = dist[2 * (n - 1) + z][j];
        if (cmp(res, ans)) ans = res;
    }

    cout << (deg(2, ans.fi) + ans.se + P - 1) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}