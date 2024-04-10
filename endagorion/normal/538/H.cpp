#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int MAXN = 110000;
int l[MAXN], r[MAXN];
vi e[MAXN];
int vis[MAXN], c[MAXN];

bool dfs(int v, int col, pii &l0, pii &l1, vi &v0, vi &v1) {
    if (vis[v]) return c[v] == col;
    vis[v] = 1;
    c[v] = col;
    uax((col ? l1 : l0).fi, l[v]);
    uin((col ? l1 : l0).se, r[v]);
    (col ? v1 : v0).pb(v);
    for (int u: e[v]) {
        if (!dfs(u, col ^ 1, l0, l1, v0, v1)) return false;
    }
    return true;
}

struct TEvent {
    int x, type;
    int id, w;
    pii p;

    TEvent(int x = 0, int type = 0, int id = 0, int w = 0, pii p = mp(0, 0))
        : x(x)
        , type(type)
        , id(id)
        , w(w)
        , p(p)
    {
    }

    bool operator<(const TEvent &ev) const {
        if (x != ev.x) return x < ev.x;
        return type > ev.type;
    }
};

const int MAXT = 110000;
int t[MAXT];

void ins_seg(int l, int r, pii p, int id, int w, vector<TEvent> &evs) {
    assert(r >= l);
    if (l == r) return;
    evs.pb(TEvent(l, 0, id, w, p));
    evs.pb(TEvent(r, 1, id, w, p));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int lt, rt;
    cin >> lt >> rt;
    int N, M;
    cin >> N >> M;
    forn(i, N) cin >> l[i] >> r[i];
    forn(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    vvi vs[2];
    vector<pii> l[2];
    bool ok = true;
    vector<TEvent> evs;
    int K = 0;
    forn(i, N) {
        if (vis[i]) continue;
        pii l0 = mp(0, (int)1e9);
        pii l1 = mp(0, (int)1e9);
        vi v0, v1;
        ok &= dfs(i, 0, l0, l1, v0, v1);
        if (l0.fi > l1.fi) swap(l0, l1), swap(v0, v1);
        ok &= l0.fi <= l0.se;
        ok &= l1.fi <= l1.se;
        if (!ok) break;
        vs[0].pb(v0);
        vs[1].pb(v1);
        l[0].pb(l0);
        l[1].pb(l1);

        if (l0.se >= l1.fi) {
            ins_seg(l0.fi, l1.fi, l1, K, 0, evs);
            if (l0.se > l1.se) {
                ins_seg(l1.fi, l1.se + 1, l0, K, 1, evs);
                ins_seg(l1.se + 1, l0.se + 1, l1, K, 0, evs);
            } else {
                ins_seg(l1.fi, l0.se + 1, mp(l0.fi, l1.se), K, 2, evs);
                ins_seg(l0.se + 1, l1.se + 1, l0, K, 1, evs);
            }
        } else {
            ins_seg(l0.fi, l0.se + 1, l1, K, 0, evs);
            ins_seg(l1.fi, l1.se + 1, l0, K, 1, evs);
        }

        ++K;
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    sort(all(evs));
    multiset<int> ls, rs;
    ls.insert(0);
    rs.insert(1e9);
    int i = 0;
    int A = -1, B = -1;
    ok = false;
    while (i < evs.size()) {
        int x = evs[i].x;
        int j = i;
        while (j < evs.size() && evs[j].x == x) ++j;
        for (int k = i; k < j; ++k) {
            int type = evs[k].type, id = evs[k].id, w = evs[k].w;
            pii p = evs[k].p;
            if (type == 0) {
                t[id] = w;
                ls.insert(p.fi);
                rs.insert(p.se);
            } else {
                ls.erase(ls.find(p.fi));
                rs.erase(rs.find(p.se));
            }
        }
        int nx = (j == evs.size() ? (int)1e9 + 1 : evs[j].x) - 1;
        int lx = *ls.rbegin();
        int rx = *rs.begin();
        i = j;

        if (ls.size() == K + 1 && lx <= rx && max(lx + x, lt) <= min(rx + nx, rt)) {
            if (x + lx >= lt) A = x, B = lx;
            else if (x + rx >= lt) A = x, B = lt - x;
            else A = lt - rx, B = rx;
        } else continue;

        forn(k, N) {
            if (t[k] == 2) {
                t[k] = (l[0][k].fi <= B && B <= l[0][k].se ? 1 : 0);
            }
        }
        ok = true;
        break;
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << "POSSIBLE\n";
        cout << A << ' ' << B << '\n';
        vi ans(N);
        forn(i, K) forn(j, 2) for (int x: vs[j][i]) ans[x] = j ^ t[i];
        forn(i, N) cout << ans[i] + 1;
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}