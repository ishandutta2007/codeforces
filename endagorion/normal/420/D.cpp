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

const int maxn = 1000000;
int x[maxn], y[maxn];

struct TNode {
    int x, y;
    int w;
    int left, right;

    TNode(int x = -1)
        : x(x)
        , y(rand())
        , w(1)
        , left(0)
        , right(0)
    {
    }
};

TNode tree[2 * maxn];
int tc = 1;

int getW(int node) {
    if (!node) return 0;
    return tree[node].w;
}

void relax(int node) {
    tree[node].w = 1 + getW(tree[node].left) + getW(tree[node].right);
}

int newNode(int x) {
    tree[tc] = TNode(x);
    return tc++;
}

int merge(int left, int right) {
    if (!left) return right;
    if (!right) return left;
    if (tree[left].y > tree[right].y) {
        tree[left].right = merge(tree[left].right, right);
        relax(left);
        return left;
    } else {
        tree[right].left = merge(left, tree[right].left);
        relax(right);
        return right;
    }
}

void split(int node, int ls, int &left, int &right) {
    if (!node) {
        left = right = 0;
        return;
    }
    if (getW(tree[node].left) >= ls) {
        split(tree[node].left, ls, left, right);
        tree[node].left = right;
        relax(node);
        right = node;
    } else {
        split(tree[node].right, ls - getW(tree[node].left) - 1, left, right);
        tree[node].right = left;
        relax(node);
        left = node;
    }
}

bool was[maxn];
int fw = 0;

void print(int node) {
    if (!node) return;
    print(tree[node].left);
    if (tree[node].x == -1) {
        while (was[fw]) ++fw;
        tree[node].x = fw++;
    }
    printf("%d ", tree[node].x + 1);
    print(tree[node].right);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    forn(i, M) {
        scanf("%d%d", &x[i], &y[i]);
        --x[i];
        --y[i];
    }
    int root = 0;
    forn(i, N) {
        root = merge(root, i + 1);
    }

    bool ok = true;
    forn(i, M) {
        int x = ::x[M - i - 1], y = ::y[M - i - 1];
        int left, right;
        split(root, 1, left, right);
        if (tree[left].x == -1 && !was[x]) {
            was[x] = true;
            tree[left].x = x;
        }
        if (tree[left].x != x) {
            ok = false;
            break;
        }
        int mid1, mid2;
        split(right, y, mid1, mid2);
        root = merge(mid1, merge(left, mid2));
    }
    if (ok) {
        print(root);
    } else {
        printf("-1\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}