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

int GCD(int a, int b) {
    return b ? GCD(b, a % b) : a;
}


struct TResult {
    int g, c;

    TResult(int g = 0, int c = 0)
        : g(g)
        , c(c)
    {
    }

    TResult operator+(TResult res) const {
        int ng = GCD(g, res.g);
        int nc = 0;
        if (g == ng) nc += c;
        if (res.g == ng) nc += res.c;
        return TResult(ng, nc);
    }
};

struct TNode {
    int L, R;
    int left, right;
    TResult res;

    TNode(int L = 0, int R = 0)
        : L(L)
        , R(R)
        , left(-1)
        , right(-1)
        , res()
    {
    }
};

const int MAXT = 300000, MAXN = 110000;
TNode t[MAXT];
int a[MAXN];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L == 1) {
        t[node].res = TResult(a[L], 1);
        return node;
    }
    int M = (L + R) / 2;
    t[node].left = buildTree(L, M);
    t[node].right = buildTree(M, R);
    t[node].res = t[t[node].left].res + t[t[node].right].res;
    return node;
}

TResult query_seg(int node, int L, int R) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return TResult();
    if (L <= t[node].L && t[node].R <= R) return t[node].res;
    return query_seg(t[node].left, L, R) + query_seg(t[node].right, L, R);
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
    forn(i, N) cin >> a[i];
    buildTree(0, N);
    int T;
    cin >> T;
    forn(t, T) {
        int a, b;
        cin >> a >> b;
        --a;
        cout << b - a - query_seg(0, a, b).c << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}