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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TNode {
    int L, R;
    int left, right;
    int z;
    vi base;

    TNode(int L = -1, int R = -1)
        : L(L)
        , R(R)
        , left(-1)
        , right(-1)
        , z(0)
        , base()
    {
    }
};

const int MAXT = 1000000;
TNode t[MAXT];
int tc = 0;
int a[MAXT];

void ins(vi &v, int x) {
    int j = 0;
    ford(i, 32) {
        if ((x >> i) & 1) {
            if (j < v.size()) {
                if ((v[j] >> i) & 1) x ^= v[j];
                else swap(x, v[j]);
                ++j;
            } else {
                v.pb(x);
                return;
            }
        } else if (j < v.size() && ((v[j] >> i) & 1)) {
            ++j;
        }
    }
}

vi sbase(vi a, const vi &b) {
    for (int x: b) ins(a, x);
    return a;
}

vi mbase(vi a, int z) {
    vi b;
    for (int x: a) {
        int y = x;
        if (x & 1) y ^= (2 * z);
        ins(b, y);
    }
    assert(a.size() == b.size());
    return b;
}

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L == 1) {
        t[node].base.pb(2 * a[L] + 1);
        return node;
    }
    int M = (L + R) / 2;
    t[node].left = buildTree(L, M);
    t[node].right = buildTree(M, R);
    t[node].base = sbase(t[t[node].left].base, t[t[node].right].base);
    return node;
}

void ch(int node, int z) {
    t[node].base = mbase(t[node].base, z);
    t[node].z ^= z;
}

void segXor(int node, int L, int R, int z) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return;
    if (L <= t[node].L && t[node].R <= R) {
        ch(node, z);
        return;
    }
    if (t[node].z) {
        ch(t[node].left, t[node].z);
        ch(t[node].right, t[node].z);
        t[node].z = 0;
    }
    segXor(t[node].left, L, R, z);
    segXor(t[node].right, L, R, z);
    t[node].base = sbase(t[t[node].left].base, t[t[node].right].base);
}

void segBase(int node, int L, int R, vi &base) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return;
    if (L <= t[node].L && t[node].R <= R) {
        base = sbase(base, t[node].base);
        return;
    }
    if (t[node].z) {
        ch(t[node].left, t[node].z);
        ch(t[node].right, t[node].z);
        t[node].z = 0;
    }
    segBase(t[node].left, L, R, base);
    segBase(t[node].right, L, R, base);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, Q;
    cin >> N >> Q;
    forn(i, N) cin >> a[i];
    int root = buildTree(0, N);
    forn(q, Q) {
        if (q % 1000 == 0) cerr << q << '\n';
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            --l;
            segXor(root, l, r, k);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            vi base;
            segBase(root, l, r, base);
            int R = base.size();
            if (!base.empty() && base.back() == 1) --R;
            cout << (1 << R) << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}