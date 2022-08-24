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

struct TNode {
    TNode *left, *right;
    int count;
    long long x, y, sum, dists;

    TNode(long long _x = 0);
};

TNode *null;

TNode::TNode(long long _x)
    : left(null)
    , right(null)
    , count(1)
    , x(_x)
    , y(rand() << 16 + rand())
    , sum(x)
    , dists(0)
{
}

void relax(TNode *node) {
    node->count = 1 + node->left->count + node->right->count;
    node->sum = node->x + node->left->sum + node->right->sum;
    node->dists = node->left->dists + node->right->dists;
    node->dists += node->right->sum - node->x * node->right->count;
    node->dists += node->x * node->left->count - node->left->sum;
    node->dists += node->right->sum * node->left->count - node->left->sum * node->right->count;
}

TNode *merge(TNode *l, TNode *r) {
    if (l == null) {
        return r;
    }
    if (r == null) {
        return l;
    }

    TNode *root;
    if (l->y > r->y) {
        l->right = merge(l->right, r);
        root = l;
    } else {
        r->left = merge(l, r->left);
        root = r;
    }
    relax(root);
    return root;
}

void split(TNode *root, long long x, TNode *&l, TNode *&r) {
    if (root == null) {
        l = r = null;
        return;
    }
    if (root->x <= x) {
        split(root->right, x, l, r);
        root->right = l;
        relax(root);
        l = root;
    } else {
        split(root->left, x, l, r);
        root->left = r;
        relax(root);
        r = root;
    }
}

TNode *insert(TNode *root, long long x) {
    TNode *l, *r;
    split(root, x, l, r);
    TNode *res = merge(l, merge(new TNode(x), r));
    return res;
}

TNode *erase(TNode *root, long long x) {
    TNode *l, *m, *r;
    split(root, x, l, r);
    split(l, x - 1, l, m);
    return merge(l, r);
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    null = new TNode();
    null->left = null->right = null;
    null->count = 0;
    null->x = null->sum = 0;

    int N;
    scanf("%d", &N);

    TNode *root = null;
    vector<long long> x(N);
    for (int i = 0; i < N; ++i) {
        scanf("%I64d", &x[i]);
        root = insert(root, x[i]);
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int c;
        scanf("%d", &c);
        if (c == 1) {
            int p, d;
            scanf("%d%d", &p, &d);
            --p;
            root = erase(root, x[p]);
            x[p] += d;
            root = insert(root, x[p]);
        } else {
            long long l, r;
            scanf("%I64d%I64d", &l, &r);
            TNode *left, *middle, *right;
            split(root, l - 1, left, right);
            split(right, r, middle, right);
            printf("%I64d\n", middle->dists);
            root = merge(left, merge(middle, right));
        }
    }

	return 0;
}