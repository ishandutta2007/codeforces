#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAXN = 200000;
const int INF = 1e9;
int a[MAXN], b[MAXN];

struct TNode {
    int left, right;
    int x, y;
    int size;
    int stat;
    int minx;

    TNode(int x = 0)
        : left(0)
        , right(0)
        , x(x)
        , y(rand())
        , size(1)
        , stat(-x)
        , minx(x)
    {
    }

    void recalc();
};

TNode tree[4 * MAXN];
int tc = 1;
int N, L, H;

void TNode::recalc() {
    size = tree[left].size + tree[right].size + 1;
    stat = min(tree[left].stat, min(tree[left].size - x, tree[right].stat + tree[left].size + 1));
    minx = left == 0 ? x : tree[left].minx;
}

int merge(int left, int right) {
    if (!left) {
        return right;
    }
    if (!right) {
        return left;
    }

    int root;
    if (tree[left].y > tree[right].y) {
        tree[left].right = merge(tree[left].right, right);
        root = left;
    } else {
        tree[right].left = merge(left, tree[right].left);
        root = right;
    }
    tree[root].recalc();
    return root;
}

void split(int node, int x, int &left, int &right) {
    if (!node) {
        left = right = 0;
        return;
    }

    if (tree[node].x <= x) {
        split(tree[node].right, x, left, right);
        tree[node].right = left;
        tree[node].recalc();
        left = node;
    } else {
        split(tree[node].left, x, left, right);
        tree[node].left = right;
        tree[node].recalc();
        right = node;
    }
}

int pos(int x) {
    if (x >= H) {
        return -1;
    }
    int l = -1, r = L;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (x + b[m] >= H) {
            r = m;
        } else {
            l = m;
        }
    }
    return r;
}

int insert(int node, int x) {
    int newNode = tc++;
    tree[newNode] = TNode(x);
    int left, right;
    split(node, x, left, right);
    return merge(left, merge(newNode, right));
}

int erase(int node, int x) {
    if (tree[node].x < x) {
        tree[node].right = erase(tree[node].right, x);
        tree[node].recalc();
        return node;
    } 
    if (tree[node].x > x) {
        tree[node].left = erase(tree[node].left, x);
        tree[node].recalc();
        return node;
    }
    return merge(tree[node].left, tree[node].right);
}

bool check(int node) {
    return tree[node].minx < 0 || tree[node].stat >= 0;
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    tree[0].left = tree[0].right = 0;
    tree[0].size = 0;
    tree[0].stat = INF;

    scanf("%d%d%d", &N, &L, &H);

    for (int i = 0; i < L; ++i) {
        scanf("%d", &b[i]);
    }
    vector< pair<int, int> > ps;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
        ps.pb(mp(a[i], i));
    }

    sort(b, b + L);
    int root = 0;
    for (int i = 0; i < L; ++i) {
        root = insert(root, pos(a[i]));
    }
    int count = 0;
    if (check(root)) {
        ++count;
    }
    for (int i = 0; i + L < N; ++i) {
        root = erase(root, pos(a[i]));
        root = insert(root, pos(a[i + L]));
        if (check(root)) {
            ++count;
        }
    }
    cout << count << '\n';

    return 0;
}