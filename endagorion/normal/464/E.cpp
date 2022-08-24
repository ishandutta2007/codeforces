#include <iostream>
#include <vector>
#include <cassert>
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int MAXN = 100000;
const int MAXD = 100100;
const int MAXT = 10000000;

const int H = 2;
const int P[2] = {1000000009, 1001000027};

struct TNode {
    int left, right;
    int L, R;
    int r0;
    int h[H];

    TNode(int L = 0, int R = 0)
        : left(-1)
        , right(-1)
        , L(L)
        , R(R)
        , r0(R - 1)
    {
        forn(i, 2) h[i] = 0;
    }
};

TNode tree[MAXT];
int tc = 0;
int d2[H][MAXD];

void relax(int node) {
    int left = tree[node].left, right = tree[node].right;
    forn(i, H) tree[node].h[i] = (tree[left].h[i] + 1LL * tree[right].h[i] * d2[i][tree[left].R - tree[left].L]) % P[i];
    tree[node].r0 = (tree[right].r0 == -1 ? tree[left].r0 : tree[right].r0);
}

int buildTree(int L, int R, int v) {
    int n = tc++;
    tree[n] = TNode(L, R);
    tree[n].r0 = (v ? -1 : R - 1);
    if (R - L == 1) {
        forn(i, H) tree[n].h[i] = v;
        return n;
    }
    int M = (L + R) / 2;
    tree[n].left = buildTree(L, M, v);
    tree[n].right = buildTree(M, R, v);
    relax(n);
    return n;
}

int find_r0(int n, int i) {
    if (tree[n].R - tree[n].L == 1) return tree[n].L;
    int left = tree[n].left, right = tree[n].right;
    if (tree[left].r0 >= i) return find_r0(left, i);
    return find_r0(right, i);
}                                                                                                                    

void set_seg(int &n, int src, int L, int R) {
    if (L >= tree[n].R || tree[n].L >= R) return;
    if (L <= tree[n].L && tree[n].R <= R) {
        n = src;
        return;
    }
    int nn = tc++;
    tree[nn] = tree[n];
    set_seg(tree[nn].left, tree[src].left, L, R);
    set_seg(tree[nn].right, tree[src].right, L, R);
    relax(nn);
    n = nn;
}

int add1(int n, int i, int r0, int r1) {
    int x = find_r0(n, i);
    set_seg(n, r0, i, x);
    set_seg(n, r1, x, x + 1);
    return n;
}

int cmp(int n1, int n2) {
    bool eq = true;
    forn(i, H) eq &= tree[n1].h[i] == tree[n2].h[i];
    if (eq) return 0;
    if (tree[n1].R - tree[n1].L == 1) {
        return tree[n1].h[0] ? 1 : -1;
    }
    int r = cmp(tree[n1].right, tree[n2].right);
    if (r) return r;
    return cmp(tree[n1].left, tree[n2].left);
}

int d[MAXN], p[MAXN];

struct TComp {
    bool operator()(int i, int j) {
        int r = cmp(d[i], d[j]);
//        cerr << tree[d[i]].h[0] << ' ' << tree[d[j]].h[0] << ' ' << r << '\n';
        if (r) return r < 0;
        return i < j;
    }
};

struct TEdge {
    int to, w;

    TEdge(int to = 0, int w = 0)
        : to(to)
        , w(w)
    {
    }
};

void calc_rem(int n, int p, int &res) {
    if (tree[n].R - tree[n].L == 1) {
        res = (2 * res + tree[n].h[0]) % p;
        return;
    }
    calc_rem(tree[n].right, p, res);
    calc_rem(tree[n].left, p, res);
}

vector<TEdge> e[MAXN];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    forn(i, H) {
        d2[i][0] = 1;
        forn(j, MAXD - 1) d2[i][j + 1] = 2 * d2[i][j] % P[i];
    }

    int N, M;
    cin >> N >> M;
    forn(i, M) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y; 
        e[x].pb(TEdge(y, w));
        e[y].pb(TEdge(x, w));
    }
    int S, T;
    cin >> S >> T;
    --S; --T;

    int r0 = buildTree(0, MAXD, 0), r1 = buildTree(0, MAXD, 1);
    forn(i, N) d[i] = r1, p[i] = -1;
    set<int, TComp> s;
    d[S] = 0;
    s.insert(S);
    while (!s.empty()) {
        int v = *s.begin();
        s.erase(v);
//        cerr << v << '\n';
        forn(i, e[v].size()) {
            int u = e[v][i].to, w = e[v][i].w;
            int newCost = add1(d[v], w, r0, r1);
//            cerr << tree[d[v]].h[0] << ' ' << (1 << w) << ' ' << tree[newCost].h[0] << '\n';
            if (cmp(newCost, d[u]) < 0) {
                p[u] = v;
                s.erase(u);
                d[u] = newCost;
                s.insert(u);
            }
        }
    }
    if (d[T] == r1) {
        cout << -1 << '\n';
    } else {
        int r = 0;
        calc_rem(d[T], 1000000000 + 7, r);
        cout << r << '\n';
        vi ans;
        int v = T;
        while (v != -1) {
            ans.pb(v);
            v = p[v];
        }
        reverse(all(ans));
        cout << ans.size() << '\n';
        forn(i, ans.size()) cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    cerr << tc << " nodes used\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}