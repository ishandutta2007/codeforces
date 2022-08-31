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

pii d[8] = {{2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}};

void readp(pii &p) {
    cin >> p.fi >> p.se;
    if (p.fi < 0) assert(false);
    --p.fi; --p.se;
}

pii operator+(pii a, pii b) {
    return {a.fi + b.fi, a.se + b.se};
}

int n, m;

bool ok(pii p) {
    return min(p.fi, p.se) >= 0 && min(n - p.fi, m - p.se) > 0;
}

pii &at(vector<vpi> &v, pii p) {
    return v[p.fi][p.se];
}

vector<vpi> bfs(pii start) {
    vector<vpi> dist(n, vpi(m, mp(1e9, -1)));
    at(dist, start) = mp(0, -1);
    vpi q = {start};
    forn(cur, q.size()) {
        pii v = q[cur];
        forn(dd, 8) {
            pii u = v + d[dd];
            if (!ok(u)) continue;
            if (at(dist, u).fi < 1e8) continue;
            at(dist, u) = mp(at(dist, v).fi + 1, dd);
            q.pb(u);
        }
    }
    return dist;
}

bool win_chad(pii chad, pii virgin, pii ctarget, pii vtarget) {
    auto cdist = bfs(chad);
    auto vdist = bfs(virgin);
    return at(cdist, ctarget).fi <= at(vdist, vtarget).fi || at(cdist, vtarget).fi <= at(vdist, vtarget).fi + 1;
}

void make_move(pii &p, int dd) {
    p = p + d[dd];
    cout << p.fi + 1 << ' ' << p.se + 1 << endl;
}

void make_move_or_capture(pii &w, pii b, int dd) {
    forn(ddd, 8) {
        if (w + d[ddd] == b) {
            make_move(w, ddd);
            exit(0);
        }
    }
    make_move(w, dd);
}

vi path_to(vector<vpi> &dist, pii target) {
    vi path;
    while (1) {
        pii q = at(dist, target);
        if (!q.fi) break;
        path.pb(q.se);
        target = target + d[q.se ^ 4];
    }
    reverse(all(path));
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    pii w, b;
    readp(w); readp(b);
    bool wchad = (w.fi + w.se) % 2 != (b.fi + b.se) % 2;
    bool chad;
    pii wtarget = mp(n / 2 - 1, m / 2 - 1);
    pii btarget = mp(n / 2, m / 2 - 1);
    if (wchad) {
        if (win_chad(w, b, wtarget, btarget)) {
            chad = true;
            cout << "WHITE" << endl;
        } else {
            chad = false;
            cout << "BLACK" << endl;
            swap(w, b);
            swap(wtarget, btarget);
            readp(b);
        }
    } else {
        chad = true;
        forn(dd, 8) {
            pii nw = w + d[dd];
            if (!ok(nw)) continue;
            if (!win_chad(b, nw, btarget, wtarget)) {
                chad = false;
                cout << "WHITE" << endl;
                make_move(w, dd);
                break;
            }
        }
        if (chad) {
            cout << "BLACK" << endl;
            swap(w, b);
            swap(wtarget, btarget);
            readp(b);
        }
    }

    cerr << (chad ? "CHAD" : "VIRGIN") << '\n';

    if (!chad) {
        auto vdist = bfs(w);
        auto path = path_to(vdist, wtarget);
        for (int d: path) {
            make_move(w, d);
            if (w == wtarget) break;
            readp(b);
        }
    } else {
        auto wdist = bfs(w), bdist = bfs(b);
        if (at(wdist, wtarget).fi <= at(bdist, btarget).fi) {
            auto path = path_to(wdist, wtarget);
            for (int d: path) {
//                cerr << d << '\n';
                make_move_or_capture(w, b, d);
                if (w == wtarget) break;
                readp(b);
            }
        } else {
            assert(at(wdist, btarget).fi <= at(bdist, btarget).fi + 1);
            auto path = path_to(wdist, btarget);
            if (btarget > wtarget) {
                path.pb(6);
                path.pb(1);
                path.pb(4);
            } else {
                path.pb(2);
                path.pb(5);
                path.pb(0);
            }
            for (int d: path) {
                make_move_or_capture(w, b, d);
                if (w == wtarget) break;
                readp(b);
            }

        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}