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

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

const unsigned long long P = 1037159;
unsigned long long degs[200001];

struct TNode {
    TNode *left, *right;
    int x, y;
    int key, size;
    int leftmost, rightmost;
    unsigned long long hash;

    TNode(int _x, int _key);
};

TNode *null;

TNode::TNode(int _x, int _key)
    : left(null)
    , right(null)
    , x(_x)
    , y(rand())
    , key(_key)
    , size(1)
    , leftmost(_key)
    , rightmost(_key)
    , hash(0)
{
}

void relax(TNode *a) {
    a->size = 1;
    a->leftmost = a->rightmost = a->key;
    if (a->left != null) {
        a->size += a->left->size;
        a->leftmost = a->left->leftmost;            
    }
    if (a->right != null) {
        a->size += a->right->size;
        a->rightmost = a->right->rightmost;
    }
    a->hash = 0;
    int taken = 0;
    if (a->left != null) {
        a->hash = a->left->hash;
        int next = a->key - a->left->rightmost;
        a->hash += (next + 102976) * degs[a->left->size - 1];
    }
    if (a->right != null) {
        int next = a->right->leftmost - a->key;
        a->hash += (next + 102976) * degs[a->left->size];
        a->hash += a->right->hash * degs[a->left->size + 1];
    }
}

TNode *merge(TNode *a, TNode *b) {
    if (a == null) {
        return b;
    }
    if (b == null) {
        return a;
    }

    TNode *root;
    if (a->y > b->y) {
        a->right = merge(a->right, b);
        root = a;
    } else {
        b->left = merge(a, b->left);
        root = b;
    }
    relax(root);
    return root;
}

void split(TNode *a, int x, TNode *&l, TNode *&r) {
    if (a == null) {
        l = r = null;
        return;
    }
    if (a->x <= x) {
        split(a->right, x, l, r);
        a->right = l;
        relax(a);
        l = a;
    } else {
        split(a->left, x, l, r);
        a->left = r;
        relax(a);
        r = a;
    }
}

TNode *insert(TNode *root, int x, int key) {
    TNode *left, *right;
    split(root, x, left, right);
    return merge(left, merge(new TNode(x, key), right));
}

TNode *erase(TNode *root, int x) {
    TNode *left, *m1, *m2, *right;
    split(root, x - 1, left, m1);
    split(m1, x, m2, right);
    delete(m2);
    return merge(left, right);
}

int main() {
	fout.precision(10);
	fout << fixed;

    null = new TNode(0, 0);
    null->left = null->right = null;
    null->size = 0;
    null->hash = 0;

    degs[0] = 1;
    for (int i = 1; i <= 200000; ++i) {
        degs[i] = P * degs[i - 1];
    }

    int N, M;
    fin >> N >> M;
    vector<int> a(N), b(M), bb(M);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
        --a[i];
    }
    for (int i = 0; i < M; ++i) {
        fin >> b[i];
        --b[i];
        bb[b[i]] = i;
    }

    TNode *subseq = null;
    for (int i = 0; i < N; ++i) {
        subseq = insert(subseq, i, a[i]);
    }
    unsigned long long hashA = subseq->hash;

    TNode *root = null;
    for (int i = 0; i < N; ++i) {
        root = insert(root, bb[i], i);
    }

    int ans = 0;
    for (int i = N; i <= M; ++i) {
        if (root->hash == hashA) {
            ++ans;
        }
        if (i < M) {
            root = erase(root, bb[i - N]);
            root = insert(root, bb[i], i);
        }
    }

    fout << ans << '\n';

	return 0;
}