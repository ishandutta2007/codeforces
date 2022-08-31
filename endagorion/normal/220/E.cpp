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

struct TNode {
    TNode *left, *right;
    int x, y;
    int size;

    TNode::TNode(int _x = 0);
};

TNode *null;

void init() {
    null = new TNode();
    null->left = null->right = null;
    null->size = 0;
}

int uniform() {
    return rand() * RAND_MAX + rand();
}

TNode::TNode(int _x)
    : left(null)
    , right(null)
    , x(_x)
    , y(uniform())
    , size(1)
{
}

void relax(TNode *root) {
    root->size = 1 + root->left->size + root->right->size;
}

void split(TNode *root, int x, TNode **left, TNode **right) {
    if (root == null) {
        *left = null;
        *right = null;
        return;
    }
    if (root->x <= x) {
        split(root->right, x, left, right);
        root->right = *left;
        *left = root;
    } else {
        split(root->left, x, left, right);
        root->left = *right;
        *right = root;
    }
    relax(root);
}

TNode *merge(TNode *left, TNode *right) {
    if (left == null) {
        return right;
    }
    if (right == null) {
        return left;
    }

    TNode *root;
    if (left->y > right->y) {
        left->right = merge(left->right, right);
        root = left;
    } else {
        right->left = merge(left, right->left);
        root = right;
    }
    relax(root);
    return root;
}

TNode *insert(TNode *root, int x) {
    TNode *left, *right;
    split(root, x, &left, &right);
    return merge(left, merge(new TNode(x), right));
}

TNode *erase(TNode *root, int x) {
    TNode *left, *middle1, *middle2, *right;
    split(root, x, &left, &right);
    split(left, x - 1, &middle1, &middle2);
    middle2 = merge(middle2->left, middle2->right);
    return merge(middle1, merge(middle2, right));
}

int lessThan(TNode *root, int x) {
    TNode *left, *right;
    split(root, x - 1, &left, &right);
    int ans = left->size;
    root = merge(left, right);
    return ans;
}

int moreThan(TNode *root, int x) {
    return root->size - lessThan(root, x + 1);
}

int main() {
	fout.precision(10);
	fout << fixed;

    init();

    int N;
    long long K;
    fin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        fin >> a[i];
    }
    int L = 0, R = N;
    long long inv = 0;
    TNode *left = null, *right = null;
    left = insert(left, a[0]);
    while (R - L > 1) {
        --R;
        long long newInv = inv;
        newInv += moreThan(left, a[R]) + lessThan(right, a[R]);
        if (newInv <= K) {
            inv = newInv;
            right = insert(right, a[R]);
        } else {
            ++R;
            break;
        }
    }
    long long ans = N - R;
    for (L = 1; L < N; ++L) {
        inv += moreThan(left, a[L]) + lessThan(right, a[L]);
        left = insert(left, a[L]);
        while (inv > K && R < N || L >= R) {
            inv -= moreThan(left, a[R]) + lessThan(right, a[R]);
            right = erase(right, a[R]);
            ++R;
        }
        ans += N - R;
    }

    fout << ans << '\n';

	return 0;
}