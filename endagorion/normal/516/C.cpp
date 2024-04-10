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

struct TResult {
    i64 res, maxl, maxr, L;

    TResult(i64 res = -1e9, i64 maxl = -1e9, i64 maxr = -1e9, i64 L = 0)
        : res(res)
        , maxl(maxl)
        , maxr(maxr)
        , L(L)
    {
    }

    TResult operator+(const TResult &r) {
        TResult ans;
        ans.res = max(max(res, r.res), maxr + r.maxl);
        ans.maxl = max(maxl, r.maxl + L);
        ans.maxr = max(r.maxr, maxr + r.L);
        ans.L = L + r.L;
        return ans;
    }
};

struct TNode {
    int L, R;
    int left, right;
    TResult res;

    TNode(int L = -1, int R = -1)
        : L(L)
        , R(R)
        , left(-1)
        , right(-1)
        , res()
    {
    }
};

const int MAXT = 500000;
const int MAXN = 110000;
TNode t[MAXT];
i64 d[MAXN], h[MAXN];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L == 1) {
        t[node].res = TResult(h[L] + h[R] + d[L], h[R] + d[L], h[L] + d[L], d[L]);
        return node;
    }
    int M = (L + R) / 2;
    t[node].left = buildTree(L, M);
    t[node].right = buildTree(M, R);
    t[node].res = t[t[node].left].res + t[t[node].right].res;
    return node;
}

TResult getSeg(int node, int L, int R) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return TResult();
    if (L <= t[node].L && t[node].R <= R) return t[node].res;
    return getSeg(t[node].left, L, R) + getSeg(t[node].right, L, R);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N >> M;
    forn(i, N) cin >> d[i];
    forn(i, N) {
        cin >> h[i];
        h[i] *= 2;
    }
    h[N] = h[0];
    buildTree(0, N);
    forn(i, M) {
        int l, r;
        cin >> l >> r;
        --l;
        TResult res;
        if (l < r) {
            res = getSeg(0, r, l == 0 ? N - 1 : N);
            if (l > 1) res = res + getSeg(0, 0, l - 1);
        } else {
            res = getSeg(0, r, l - 1);
        }
        cout << res.res << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}