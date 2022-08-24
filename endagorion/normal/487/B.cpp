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

struct TResult {
    int minX, maxX;

    TResult(int minX = 2e9, int maxX = -2e9)
        : minX(minX)
        , maxX(maxX) 
    {
    }

    TResult operator+(const TResult &res) const {
        return TResult(min(minX, res.minX), max(maxX, res.maxX));
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

const int MAXN = 110000;
TNode t[4 * MAXN];
int a[MAXN];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L == 1) {
        t[node].res = TResult(a[L], a[L]);
        return node;
    }

    int M = (L + R) / 2;
    t[node].left = buildTree(L, M);
    t[node].right = buildTree(M, R);
    t[node].res = t[t[node].left].res + t[t[node].right].res;
    return node;
}

TResult query(int node, int L, int R) {
    if (max(L, t[node].L) >= min(R, t[node].R)) return TResult();
    if (L <= t[node].L && t[node].R <= R) return t[node].res;
    return query(t[node].left, L, R) + query(t[node].right, L, R);
}

vi add[2 * MAXN], del[2 * MAXN];
int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, S, L;
    cin >> N >> S >> L;
    forn(i, N) cin >> a[i];
    int root = buildTree(0, N);
    forn(i, N + 1) ans[i] = 1e9;
    add[0].pb(0);
    del[1].pb(0);
    multiset<int> q;
    forn(i, N + 1) {
        for (int x: add[i]) q.insert(x);
        for (int x: del[i]) q.erase(q.find(x));
        if (q.empty() ) continue;
        int x = *q.begin();
        ans[i] = x;
        if (i + L > N) continue;
        TResult res = query(root, i, i + L);
        if (res.maxX - res.minX > S) continue;
        int l = i + L, r = N + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            TResult res = query(root, i, m);
            if (res.maxX - res.minX <= S) l = m;
            else r = m;
        }
        add[i + L].pb(x + 1);
        del[r].pb(x + 1);
    }
    if (ans[N] > 1e8) cout << -1 << '\n';
    else cout << ans[N] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}