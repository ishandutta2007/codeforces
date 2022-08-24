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

const int MAXN = 1100000;
vi lft[MAXN], rgt[MAXN];
int leftf[MAXN], anyf[MAXN];
int lc[MAXN], rc[MAXN];
char s[10];

struct TNode {
    int left, right;
    int L, R;
    int maxk;

    TNode(int L = -1, int R = -1)
        : left(-1)
        , right(-1)
        , L(L)
        , R(R)
        , maxk(-1e9)
    {
    }
};

const int MAXT = 2100000;

TNode t[MAXT];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L == 1) return node;
    int M = (L + R) / 2;
    t[node].left = buildTree(L, M);
    t[node].right = buildTree(M, R);
    return node;
}

int getMax(int node, int L, int R) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return -1e9;
    if (L <= t[node].L && t[node].R <= R) return t[node].maxk;
    return max(getMax(t[node].left, L, R), getMax(t[node].right, L, R));
}

void setMax(int node, int i, int x) {
    if (i >= t[node].R || i < t[node].L) return;
    if (i == t[node].L && i + 1 == t[node].R) {
        t[node].maxk = x;
        return;
    }
    setMax(t[node].left, i, x);
    setMax(t[node].right, i, x);
    t[node].maxk = max(t[t[node].left].maxk, t[t[node].right].maxk);
}

bool buildAns(int l, int r) {
    if (anyf[l] > r) return false;
    for (int x: rgt[l]) {
        if (x <= leftf[l]) return false;
    }
    if (leftf[l] == l) {
        lc[l] = -1;
        if (r == l) return true;
        rc[l] = l + 1;
        return buildAns(l + 1, r);
    }
    lc[l] = l + 1;
    if (!buildAns(lc[l], leftf[l])) return false;
    if (leftf[l] == r) return true;
    rc[l] = leftf[l] + 1;
    return buildAns(rc[l], r);
}

void print(int v) {
    if (v == -1) return;
    print(lc[v]);
    printf("%d ", v + 1);
    print(rc[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, C;
    scanf("%d%d", &N, &C);
    bool ok = true;
    int root = buildTree(0, N);
    forn(i, C) {
        int x, y;
        scanf("%d%d%s", &x, &y, s);
        --x; --y;
        ok &= x < y;
        if (s[0] == 'L') lft[x].pb(y);
        else rgt[x].pb(y);
    }
    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    ford(i, N) {
        leftf[i] = anyf[i] = i;
        for (int x: lft[i]) {
            uax(leftf[i], getMax(root, i, x + 1));
        }
        for (int x: rgt[i]) {
            uax(anyf[i], getMax(root, i, x + 1));
        }
        uax(anyf[i], leftf[i]);
        setMax(root, i, anyf[i]);
    }   
    forn(i, N) lc[i] = rc[i] = -1;
    if (!buildAns(0, N - 1)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    print(0);
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}