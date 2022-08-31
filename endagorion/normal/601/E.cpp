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
    vi toAdd;

    TNode(int L = -1, int R = -1)
        : L(L)
        , R(R)
        , left(-1)
        , right(-1)
        , toAdd()
    {
    }
};

const int MAXT = 110000;
TNode t[MAXT];
int tc = 0;

int buildTree(int L, int R) {
    int node = tc++;
    t[node] = TNode(L, R);
    if (R - L > 1) {
        int M = (L + R) / 2;
        t[node].left = buildTree(L, M);
        t[node].right = buildTree(M, R);
    }
    return node;
}

void addQ(int node, int L, int R, int x) {
    TNode &n = t[node];
    if (max(L, n.L) >= min(R, n.R)) return;
    if (L <= n.L && n.R <= R) {
        n.toAdd.pb(x);
        return;
    }
    addQ(n.left, L, R, x);
    addQ(n.right, L, R, x);
}

const int maxn = 20000;
int act[maxn], w[maxn], v[maxn];

const int maxq = 31000;
int type[maxq], id[maxq], ansq[maxq];

const int maxk = 1001;
int dp[maxk];

const i64 P = 1000000000 + 7;
const i64 Q = 10000000 + 19;

vector<pii> ops;

void change(int i, int x) {
    ops.pb(mp(i, dp[i]));
    dp[i] = x;
}

void revert() {
    int i = ops.back().fi, x = ops.back().se;
    dp[i] = x;
    ops.pop_back();
}

int n, k, q;

void traverse(int node) {
    TNode &n = t[node];
    int sz = ops.size();
    for (int id: n.toAdd) {
        for (int i = k - w[id]; i >= 0; --i) {
            if (dp[i] < 0) continue;
            if (dp[i + w[id]] < dp[i] + v[id]) change(i + w[id], dp[i] + v[id]);
        }
    }
    if (n.R - n.L == 1) {
        if (type[n.L] == 3) {
            i64 ans = 0, t = 1;
//            cerr << n.L << '\n';
            i64 x = 0;
            for1(i, k) {
//                cerr << dp[i] << ' ';
                uax(x, (i64)dp[i]);
//                cerr << x << ' ';
                ans += t * x; ans %= P;
                t *= Q; t %= P;
            }
//            cerr << '\n';
            ansq[n.L] = ans;
        }
    } else {
        traverse(n.left);
        traverse(n.right);
    }
    while (ops.size() > sz) revert();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k;
    forn(i, n) {
        act[i] = 0;
        cin >> v[i] >> w[i];
    }
    cin >> q;
    int root = buildTree(0, q);
    forn(i, q) {
        cin >> type[i];
        if (type[i] == 1) {
            cin >> v[n] >> w[n];
            act[n] = i;
            id[i] = n++;
        } else if (type[i] == 2) {
            cin >> id[i]; --id[i];
//            cerr << id[i] << ' ' << act[id[i]] << ' ' << i << '\n';
            addQ(root, act[id[i]], i, id[i]);
            act[id[i]] = -1;
        }
    }
    forn(i, n) if (act[i] != -1) addQ(root, act[i], q, i);//, cerr << i << ' ' << act[i] << ' ' << n << '\n';
//    dp[0] = 0;
//    for1(i, k) dp[i] = -1;
    traverse(root);
    forn(i, q) {
        if (type[i] == 3) cout << ansq[i] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}