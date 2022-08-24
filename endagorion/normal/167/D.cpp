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

struct TCartNode {
	int x, y;
	int w;
	TCartNode *left, *right;
	int used, nused;

	TCartNode(int _x, int _y);
};

TCartNode *null;

TCartNode::TCartNode(int _x, int _y)
	: x(_x)
	, y(_y)
	, w(1)
	, left(null)
	, right(null)
	, used(0)
	, nused(0)
{
}

void relax(TCartNode *node) {
	if (node == null) {
		return;
	}

	node->w = 1 + node->left->w + node->right->w;
	node->used = node->left->nused + node->right->nused;
	node->nused = max(node->used, 1 + max(node->left->used + node->right->nused, node->left->nused + node->right->used));
}

void split(TCartNode *node, int x, TCartNode **left, TCartNode **right) {
	if (node == null) {
		*left = *right = null;
		return;
	}

	if (node->x > x) {
		split(node->left, x, left, right);
		node->left = *right;
		*right = node;
	} else {
		split(node->right, x, left, right);
		node->right = *left;
		*left = node;
	}
	relax(node);
}

TCartNode *merge(TCartNode *left, TCartNode *right) {
	if (left == null) {
		return right;
	}
	if (right == null) {
		return left;
	}

	if (left->y > right->y) {
		left->right = merge(left->right, right);
		relax(left);
		return left;
	} else {
		right->left = merge(left, right->left);
		relax(right);
		return right;
	}
}

TCartNode *insert(TCartNode	*root, TCartNode *node) {
	TCartNode *left, *right;
	split(root, node->x, &left, &right);
	return merge(left, merge(node, right));
}

const long long P = 1000000000 + 9;

int main() {
	fout.precision(10);
	fout << fixed;

	null = new TCartNode(0, 0);
	null->w = 0;
	null->left = null->right = null;
	null->used = -1;
	null->nused = 0;

	int N, K;
	fin >> N >> K;
	long long x, y;
	long long a, b, c, d;

	vector<TCartNode *> nodes(N);
	TCartNode *root = null;

	for (int i = 0; i < K; ++i) {
		fin >> x >> y;
		nodes[i] = new TCartNode(x, y);
		root = insert(root, nodes[i]);
	}
	
	fin >> a >> b >> c >> d;
	for (int i = K; i < N; ++i) {
		x = (a * x + b) % P;
		y = (c * y + d) % P;
		nodes[i] = new TCartNode(x, y);
		root = insert(root, nodes[i]);
	}

	int M;
	fin >> M;
	for (int i = 0; i < M; ++i) {
		int l, r;
		fin >> l >> r;
		TCartNode *left, *middle, *right;
		split(root, l - 1, &left, &middle);
		split(middle, r, &middle, &right);
		fout << middle->nused << '\n';
		root = merge(left, merge(middle, right));
	}

	return 0;
}