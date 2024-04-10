#include <iostream>
#include <tuple>
#include <sstream>
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
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

struct TNode {
    ld p, T;
    ld ans, pq;
    int y;
    int left, right;

    TNode(ld p = 0.0, ld T = 0.0)
        : p(p)
        , T(T)
        , ans(p * T)
        , pq(1 - p)
        , y(rand())
        , left(0)
        , right(0)
    {
    }
};

const int MAXT = 2000000;
TNode t[MAXT];
int tc = 1;

bool cmp(int node1, int node2) {
    TNode &n1 = t[node1], &n2 = t[node2];
    return n1.T < n2.T;
}

void relax(int node) {
    TNode &n = t[node];
    n.ans = 0.0;
    n.pq = 1.0;
    if (n.left) {
        n.ans += t[n.left].ans;
        n.pq *= t[n.left].pq;
    }
    n.ans += n.pq * n.p * n.T;
    n.pq *= 1 - n.p;
    if (n.right) {
        n.ans += n.pq * t[n.right].ans;
        n.pq *= t[n.right].pq;
    }
}

int merge(int left, int right) {
    if (!left) return right;
    if (!right) return left;
    if (t[left].y < t[right].y) {
        t[left].right = merge(t[left].right, right);
        relax(left);
        return left;
    } else {
        t[right].left = merge(left, t[right].left);
        relax(right);
        return right;
    }
}

void split(int node, int s, int &left, int &right) {
    if (!node) {
        left = right = 0;
        return;
    }
    if (cmp(node, s)) {
        split(t[node].right, s, left, right);
        t[node].right = left;
        relax(node);
        left = node;
    } else {
        split(t[node].left, s, left, right);
        t[node].left = right;
        relax(node);
        right = node;
    }
}

int ins(int node, ld p, ld T) {
    int nnode = tc++;
    t[nnode] = TNode(p, T);
    int left, right;
    split(node, nnode, left, right);
    return merge(left, merge(nnode, right));
}

const int maxn = 1100;
int prob[maxn][maxn];
ld q[maxn], pq[maxn], ans[maxn];

ld get_ans(int r) {
    return (1 + t[r].ans) / (1 - t[r].pq);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    forn(i, n) forn(j, n) cin >> prob[i][j];
    q[n - 1] = 0.0;
    forn(i, n - 1) q[i] = 0, pq[i] = 1.0, ans[i] = 1e9;
    vi root(n);
    forn(i, n) root[i] = 0;
    set<pair<ld, int> > s;
    s.insert(mp(0.0, n - 1));
    while (!s.empty()) {
        int v = s.begin()->se;
        s.erase(s.begin());
//        cerr << v << ' ' << ans[v] << '\n';
        forn(i, n) {
            if (ans[i] < ans[v] + 1e-9) continue;
            if (!prob[i][v]) continue;
            s.erase(mp(ans[i], i));
            q[i] += pq[i] * 0.01 * prob[i][v] * ans[v];
            pq[i] *= (1 - 0.01 * prob[i][v]);
            ans[i] = (1 + q[i]) / (1 - pq[i]);
            s.insert(mp(ans[i], i));
        }
    }
    cout << ans[0] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}