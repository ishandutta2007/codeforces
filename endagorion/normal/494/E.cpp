#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
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

const int MAXN = 100000;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

struct TResult {
    int minx, qx;

    TResult(int minx = 0, int qx = 0)
        : minx(minx)
        , qx(qx)
    {
    }

    TResult operator+(const TResult &r) const {
        TResult res(min(minx, r.minx));
        if (minx == res.minx) res.qx += qx;
        if (r.minx == res.minx) res.qx += r.qx;
        return res;
    }
};

struct TNode {
    int L, R;
    int left, right;
    int val;
    TResult res;

    TNode(int L = 0, int R = 0)
        : L(L)
        , R(R)
        , left(-1)
        , right(-1)
        , val(0)
        , res()
    {
    }
};

int len[2 * MAXN];
TNode t[5 * MAXN];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    t[node].res = TResult(0, len[R] - len[L]);
    if (R - L == 1) return node;
    int M = (L + R) / 2;
    t[node].left = buildTree(L, M);
    t[node].right = buildTree(M, R);
    return node;
}

void addx(int node, int x) {
    t[node].val += x;
    t[node].res.minx += x;
}

void push(int node) {
    int x = t[node].val;
    addx(t[node].left, x);
    addx(t[node].right, x);
    t[node].val = 0;
}

void addSeg(int node, int L, int R, int x) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return;
    if (L <= t[node].L && t[node].R <= R) {
        addx(node, x);
        return;
    }
    push(node);
    addSeg(t[node].left, L, R, x);
    addSeg(t[node].right, L, R, x);
    t[node].res = t[t[node].left].res + t[t[node].right].res;
}

struct TEvent {
    int x, l, r, t;

    TEvent(int x = 0, int l = 0, int r = 0, int t = 0)
        : x(x)
        , l(l)
        , r(r)
        , t(t)
    {
    }

    bool operator<(const TEvent &ev) const {
        return x < ev.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M, K;
    cin >> N >> M >> K;
    forn(i, M) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; --b[i];
    }

    bool win = false;
    for (int tt = 1; !win && tt <= K; tt *= 2) {
        tc = 0;
        vi x, y;
        map<int, int> rx, ry;
        forn(i, M) {
            x.pb(a[i] / tt); y.pb(b[i] / tt);
            x.pb(c[i] / tt); y.pb(d[i] / tt);
        }
        x.pb(0); x.pb(N / tt);
        y.pb(0); y.pb(N / tt);
        sort(all(x)); sort(all(y));
        x.erase(unique(all(x)), x.end()); y.erase(unique(all(y)), y.end());
        forn(i, x.size()) rx[x[i]] = i;
        forn(i, y.size()) ry[y[i]] = i;
        forn(i, y.size()) len[i] = y[i];
        int root = buildTree(0, y.size() - 1);
        
        vector<TEvent> evs;
        forn(i, M) {
            evs.pb(TEvent(rx[a[i] / tt], ry[b[i] / tt], ry[d[i] / tt], 1));
            evs.pb(TEvent(rx[c[i] / tt], ry[b[i] / tt], ry[d[i] / tt], -1));
        }
        sort(all(evs));
        i64 ans = 0;
        int px = 0;
        for (TEvent ev: evs) {
            TResult res = t[root].res;
            if (res.minx == 0) ans += 1LL * (x[ev.x] - x[px]) * (N / tt - res.qx);
            else ans += (x[ev.x] - x[px]) * (N / tt);
            addSeg(root, ev.l, ev.r, ev.t);
            px = ev.x;
        }
        win |= ans & 1;
    }
    cout << (win ? "Hamed" : "Malek") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}