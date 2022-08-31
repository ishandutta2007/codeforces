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
#define rall(x) (x).rbegin(), (x).rend()
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

struct TResult {
    int lx, rx, maxs, l;

    TResult(int lx = 0, int rx = 0, int maxs = 0, int l = 0)
        : lx(lx)
        , rx(rx)
        , maxs(maxs)
        , l(l)
    {
    }

    TResult operator+(const TResult &r) const {
        TResult res;
        res.l = l + r.l;
        if (lx == l) res.lx = lx + r.lx;
        else res.lx = lx;
        if (r.rx == r.l) res.rx = r.rx + rx;
        else res.rx = r.rx;
        res.maxs = max(max(res.lx, res.rx), max(maxs, r.maxs));
        res.maxs = max(res.maxs, rx + r.lx);
        return res;
//        return TResult(lx, r.rx, max(max(maxs, r.maxs), rx + r.lx));
    }
};

struct TNode {
    int L, R;
    int left, right;
    TResult res;

    TNode(int L = 0, int R = 0)
        : L(L)
        , R(R)
        , left(0)
        , right(0)
        , res()
    {
    }
};

const int MAXT = 4000000;
TNode tree[MAXT];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    tree[node] = TNode(L, R);
    tree[node].res = TResult(0, 0, 0, R - L);
    if (R - L == 1) {
        return node;
    }
    int M = (L + R) / 2;
    tree[node].left = buildTree(L, M);
    tree[node].right = buildTree(M, R);
    return node;
}

TResult query(int node, int L, int R) {
    if (L <= tree[node].L && tree[node].R <= R) return tree[node].res;
    if (R <= tree[node].L || tree[node].R <= L) return TResult();
    return query(tree[node].left, L, R) + query(tree[node].right, L, R);
}

int set1(int node, int i) {
    if (i < tree[node].L || i >= tree[node].R) return node;
    int newNode = tc++;
    tree[newNode] = tree[node];    
    if (tree[node].R - tree[node].L == 1) {
        tree[newNode].res = TResult(1, 1, 1, 1);
        return newNode;
    }
    tree[newNode].left = set1(tree[node].left, i);
    tree[newNode].right = set1(tree[node].right, i);
    tree[newNode].res = tree[tree[newNode].left].res + tree[tree[newNode].right].res;
    return newNode;
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    vector<pii> a(N);
    forn(i, N) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(rall(a));
    vi roots(N + 1);
    roots[0] = buildTree(0, N);
    forn(i, N) roots[i + 1] = set1(roots[i], a[i].se);
    int Q;
    cin >> Q;
    forn(q, Q) {
        int A, B, W;
        cin >> A >> B >> W;
        --A;
        int l = 0, r = N;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (query(roots[m], A, B).maxs >= W) r = m;
            else l = m;
        }
        cout << a[r - 1].fi << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}