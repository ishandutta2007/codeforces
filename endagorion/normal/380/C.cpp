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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 1100000;
vector<pii> q[maxn];

char s[maxn];
int ans[maxn];

struct TNode {
    int x, y;
    int w;
    int left, right;

    TNode(int x = 0)
        : x(x)
        , y(rand())
        , w(1)
        , left(0)
        , right(0)
    {
    }
};

TNode tree[maxn];
int tc = 1;

void relax(int node) {
    tree[node].w = 1 + tree[tree[node].left].w + tree[tree[node].right].w;
}

int merge(int left, int right) {
    if (!left) return right;
    if (!right) return left;
    if (tree[left].y < tree[right].y) {
        tree[right].left = merge(left, tree[right].left);
        relax(right);
        return right;
    } else {
        tree[left].right = merge(tree[left].right, right);
        relax(left);
        return left;
    }
}

void split(int node, int x, int &left, int &right) {
    if (!node) {
        left = right = 0;
        return;
    }
    if (tree[node].x < x) {
        split(tree[node].right, x, left, right);
        tree[node].right = left;
        relax(node);
        left = node;
    } else {    
        split(tree[node].left, x, left, right);
        tree[node].left = right;
        relax(node);
        right = node;
    }
}

int notLess(int node, int x) {
    if (!node) return 0;
    if (tree[node].x >= x) {
        return 1 + tree[tree[node].right].w + notLess(tree[node].left, x);
    } else {
        return notLess(tree[node].right, x);
    }
}

int insert(int node, int x) {
    int left, right;
    split(node, x, left, right);
    tree[tc] = TNode(x);
    return merge(left, merge(tc++, right));
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    tree[0].w = 0;

    scanf("%s", s);
    int N = strlen(s);
    int M;
    scanf("%d", &M);
    forn(i, M) {    
        int l, r;
        scanf("%d%d", &l, &r);
        --l; --r;
        q[r].pb(mp(l, i));
    }

    int root = 0;
    vector<int> st;
    forn(i, N) {
        if (s[i] == '(') {
            st.pb(i);
        } else {
            if (!st.empty()) {
                root = insert(root, st.back());
                st.pop_back();
            }
        }

        forn(j, q[i].size()) {
            int x = q[i][j].first, id = q[i][j].second;
            ans[id] = 2 * notLess(root, x);
        }
    }

    forn(i, M) {
        printf("%d\n", ans[i]);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}