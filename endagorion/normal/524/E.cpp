#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
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

struct TNode {
    int L, R;
    int left, right;
    int key;

    TNode(int L = -1, int R = -1)
        : L(L)
        , R(R)
        , left(-1)
        , right(-1)
        , key(-1e9)
    {
    }
};

const int MAXT = 500000;
TNode t[MAXT];
int tc = 0;

void relax(int node) {
    if (t[node].R - t[node].L == 1) return;
    t[node].key = min(t[t[node].left].key, t[t[node].right].key);
}

int build_tree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L == 1) return node;
    int M = (L+R) / 2;
    t[node].left = build_tree(L, M);
    t[node].right = build_tree(M, R);
    return node;
}

void set_key(int node, int i, int x) {
    if (i < t[node].L || i >= t[node].R) return;
    if (i == t[node].L && i + 1 == t[node].R) {
        t[node].key = x;
        return;
    }
    set_key(t[node].left, i, x);
    set_key(t[node].right, i, x);
    relax(node);
}

int get_min(int node, int L, int R) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return 1e9;
    if (L <= t[node].L && t[node].R <= R) return t[node].key;
    return min(get_min(t[node].left, L, R), get_min(t[node].right, L, R));
}

const int MAXN = 300000;
pii p[MAXN];
pair<pii, pii> rect[MAXN];
int ans[MAXN];

int N, M, K, Q;

void process() {
    tc = 0;
    build_tree(0, M);
    vector<vector<pii> > evs(N + 1);
    forn(i, Q) {
        evs[rect[i].fi.se].pb(mp(i, 0));
    }
    forn(i, K) {
        evs[p[i].fi].pb(mp(i, 1));
    }
    forn(i, N + 1) {
        for (pii ev: evs[i]) {
            int x = ev.fi, t = ev.se;
            if (t == 0) {
                if (get_min(0, rect[x].se.fi, rect[x].se.se) >= rect[x].fi.fi) ans[x] = 1;
            } else {
                set_key(0, p[x].se, p[x].fi);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    scanf("%d%d%d%d", &N, &M, &K, &Q);
    forn(i, K) scanf("%d%d", &p[i].fi, &p[i].se), --p[i].fi, --p[i].se;
    forn(i, Q) {
        scanf("%d%d%d%d", &rect[i].fi.fi, &rect[i].se.fi, &rect[i].fi.se, &rect[i].se.se);
        --rect[i].fi.fi; --rect[i].se.fi;
    }

    process();
    forn(i, Q) swap(rect[i].fi, rect[i].se);
    forn(i, K) swap(p[i].fi, p[i].se);
    swap(N, M);
    process();
    forn(i, Q) {
        printf(ans[i] ? "YES\n" : "NO\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}