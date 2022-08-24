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
	long long x, y;
	int w;

	TNode(long long _x);
};

TNode *null = 0;

long long uniform() {
	return rand() * RAND_MAX + rand();
}

TNode::TNode(long long _x)
	: left(null)
	, right(null)
	, x(_x)
	, y(uniform())
	, w(1)
{
}

void relax(TNode *node) {
	node->w = 1 + node->left->w + node->right->w;
}

void split(TNode *node, TNode **left, TNode **right, long long key) {
	if (node == null) {
		*left = *right = null;
		return;
	}

	TNode *newNode = new TNode(0);
	*newNode = *node;
	if (node->x <= key) {
		split(node->right, left, right, key);
		newNode->right = *left;
		*left = newNode;
	} else {
		split(node->left, left, right, key);
		newNode->left = *right;
		*right = newNode;
	}
	relax(newNode);
}

TNode *merge(TNode *left, TNode *right) {
	if (left == null) {
		return right;
	}
	if (right == null) {
		return left;
	}

	TNode *newNode = new TNode(0);
	if (left->y > right->y) {
		*newNode = *left;
		newNode->right = merge(left->right, right);
	} else {
		*newNode = *right;
		newNode->left = merge(left, right->left);
	}

	relax(newNode);
	return newNode;
}

TNode *insert(TNode *node, long long x) {
	TNode *left, *right;
	split(node, &left, &right, x);
	return merge(left, merge(new TNode(x), right));
}

int atMost(TNode *node, long long key) {
	if (node == null) {
		return 0;
	}
	if (node->x <= key) {
		return 1 + node->left->w + atMost(node->right, key);
	} else {
		return atMost(node->left, key);
	}
}

int main() {
	fout.precision(10);
	fout << fixed;

	null = new TNode(0);
	null->left = null->right = null;
	null->w = 0;

	int N;
	long long K;
	fin >> N >> K;

	TNode *root = new TNode(0);

	vector< long long > A(N);
	vector< long long > S(N + 1);
	vector< TNode* > persTree(N + 1);
	persTree[0] = root;
	for (int i = 0; i < N; ++i) {
		fin >> A[i];
		S[i + 1] = S[i] + A[i];
		persTree[i + 1] = insert(persTree[i], S[i + 1]);
	}

	long long l = -1e14, r = 1e14;
	while (r - l > 1) {
		long long m = (l + r) / 2;
		long long q = 0;
		for (int i = 0; i < N; ++i) {
			q += atMost(persTree[i], S[i + 1] - m);
		}
		if (q >= K) {
			l = m;
		} else {
			r = m;
		}
	}

	fout << l << '\n';

	return 0;
}