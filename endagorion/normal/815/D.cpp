#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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

struct TNode {
    int L, R;
    int l, r;
    i64 sum, val;
    i64 minx, maxx;
};

const int MAXT = 2100000;
TNode t[MAXT];
int tc = 1;

int buildTree(int L, int R) {
    int node = tc++;
    TNode &n = t[node];
    n = {L, R, -1, -1, 0, -1, 0, 0};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void addval(int node, i64 x) {
    if (!node) return;
    TNode &n = t[node];
    n.val = x;
    n.sum = x * (n.R - n.L);
    n.minx = n.maxx = x;
}

void relax(int node) {
    if (!node) return;
    TNode &n = t[node];
    n.sum = t[n.l].sum + t[n.r].sum;
    n.minx = min(t[n.l].minx, t[n.r].minx);
    n.maxx = max(t[n.l].maxx, t[n.r].maxx);
}

void push(int node) {
    if (!node || t[node].val == -1) return;
    TNode &n = t[node];
    addval(n.l, n.val);
    addval(n.r, n.val);
    n.val = -1;
}

void maxset(int node, int R, int x) {
    TNode &n = t[node];
    if (n.L >= R) return;
    if (n.R <= R) {
        if (n.maxx <= x) {
            addval(node, x);
            return;
        }
        if (n.minx >= x) {
            return;
        }
    }
    push(node);
    maxset(n.l, R, x);
    maxset(n.r, R, x);
    relax(node);
}

i64 p, q, r;

i64 boundsum(int node, int lx, int ly) {
    TNode &n = t[node];
    if (n.R <= lx) return 0;
    if (n.L >= lx) {
        if (n.maxx <= ly) return (n.R - n.L) * (r - ly);
        if (n.minx >= ly) return (n.R - n.L) * r - n.sum;
    }
    push(node);
    return boundsum(n.l, lx, ly) + boundsum(n.r, lx, ly);
}

struct TPoint {
    int x, y, z;

    bool operator<(const TPoint &p) const {
        return x < p.x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n >> p >> q >> r;
//    scanf("%d%lld%lld%lld", &n, &p, &q, &r);
    int root = buildTree(0, q);
    vector<TPoint> ps(n);
    forn(i, n) {
        cin >> ps[i].x >> ps[i].y >> ps[i].z;
//        scanf("%d%d%d", &ps[i].x, &ps[i].y, &ps[i].z);
        //--ps[i].x, --ps[i].y, --ps[i].z;
    }
//    multiset<int> yb = {0}, zb = {0};
//    forn(i, n) yb.insert(ps[i].y), zb.insert(ps[i].z);
    sort(all(ps));
    i64 ans = 0;
    i64 px = 0;
//    for (TPoint p: ps) {
    vi maxy(n + 1), maxz(n + 1);
    ford(i, n) maxy[i] = max(maxy[i + 1], ps[i].y), maxz[i] = max(maxz[i + 1], ps[i].z);
    forn(i, n) {
        TPoint p = ps[i];
        if (p.x > px) ans += (p.x - px) * boundsum(root, maxy[i], maxz[i]);
//        yb.erase(yb.find(p.y));
//        zb.erase(zb.find(p.z));
        maxset(root, p.y, p.z);
        px = p.x;
    }
//    ans += (p - px) * boundsum(root, *yb.rbegin(), *zb.rbegin());
    ans += (p - px) * boundsum(root, 0, 0);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}