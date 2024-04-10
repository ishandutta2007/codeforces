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

const int maxn = 210000;
const i64 P = 998244353;
set<pii> segs[maxn];

i64 fastm(i64 x) {
    if (x >= P) x -= P;
    return x;
}

struct TNode {
    int L, R;
    int l, r;
    i64 sum, a, b;
};

TNode t[2 * maxn];
int tc = 0;

#define dn TNode &n = t[node];

int buildTree(int L, int R) {
    int node = tc++;
    dn;
    n = {L, R, -1, -1, 0, 1, 0};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = buildTree(L, M);
        n.r = buildTree(M, R);
    }
    return node;
}

void addval(int node, i64 a, i64 b) {
    dn;
    (n.a *= a) %= P;
    (n.b = a * n.b + b) %= P;
    (n.sum = a * n.sum + b * (n.R - n.L)) %= P;
}

void push(int node) {
    dn;
    addval(n.l, n.a, n.b);
    addval(n.r, n.a, n.b);
    n.a = 1;
    n.b = 0;
}

void relax(int node) {
    dn;
    n.sum = fastm(t[n.l].sum + t[n.r].sum);
}

void apply(int node, int L, int R, i64 a, i64 b) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        addval(node, a, b);
        return;
    }
    push(node);
    apply(n.l, L, R, a, b);
    apply(n.r, L, R, a, b);
    relax(node);
}

i64 get_sum(int node, int L, int R) {
    dn;
    if (max(L, n.L) >= min(R, n.R)) return 0;
    if (L <= n.L && n.R <= R) return n.sum;
    push(node);
    return fastm(get_sum(n.l, L, R) + get_sum(n.r, L, R));
}

void introseg(int x, int L, int R) {
    int al = L, ar = R;
    while (1) {
        auto it = segs[x].lower_bound(mp(L, 1e9));
        if (it == segs[x].end()) break;
        int l = it->se, r = it->fi;
        if (l > R) break;
        apply(0, max(l, L), min(r, R), 2, 0);
        if (L < l) apply(0, L, l, 1, 1);
        uin(al, l);
        uax(ar, r);
        segs[x].erase(it);
        L = r;
    }
    if (L < R) apply(0, L, R, 1, 1);
    segs[x].insert(mp(ar, al));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    buildTree(0, n);
    forn(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            --l;
            introseg(x, l, r);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            cout << get_sum(0, l, r) << '\n';
        }

//        cerr << get_sum(0, 0, n) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}