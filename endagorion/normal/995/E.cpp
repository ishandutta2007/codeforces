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

i64 P;

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}

set<i64> vis[2], nvis[2];
map<i64, i64> prv[2], press[2];
vi ans[2];
bool done;

void restore(int z, i64 y) {
    while (prv[z].count(y)) {
        int p = press[z][y];
        if (z && p < 2) p ^= 1;
        ans[z].pb(p);
        y = prv[z][y];
    }
}

void expand(int z) {
    set<i64> nnvis;
    for (i64 x: nvis[z]) {
        if (done) break;
        vi64 opts = {(x + 1) % P, (x + P - 1) % P, deg(x, P - 2)};
        forn(i, 3) {
            i64 y = opts[i];
            if (vis[z].count(y)) continue;
            vis[z].insert(y);
            nnvis.insert(y);
            prv[z][y] = x;
            press[z][y] = i;

            if (vis[z ^ 1].count(y)) {
                forn(zz, 2) restore(zz, y);
                done = true;
                break;
            }
        }
    }
    nvis[z] = nnvis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 u, v;
    cin >> u >> v >> P;
    vis[0] = nvis[0] = {u};
    vis[1] = nvis[1] = {v};

    forn(i, 201) {
        expand(i & 1);
        if (done) break;
    }

    reverse(all(ans[0]));
    cout << ans[0].size() + ans[1].size() << '\n';
    forn(z, 2) for (int x: ans[z]) cout << x + 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}