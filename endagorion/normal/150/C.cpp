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

long long uniform() {
	long long ans = 0;
	for (int i = 0; i < 5; ++i) {
		ans = (ans * RAND_MAX + rand()) % (long long)1e15;
	}
	return ans;
}

struct TCartNode {
	long long key, height;
	size_t size;
	long long sum, maxr, maxl, maxs;
	TCartNode *left, *right;

	TCartNode();
	TCartNode(long long _key);
	void relax();
};

TCartNode *null;

TCartNode::TCartNode()
	: key(0)
	, height(0)
	, sum(0)
	, size(0)
	, maxr(0)
	, maxl(0)
	, maxs(0)
	, left(NULL)
	, right(NULL)
{
}

TCartNode::TCartNode(long long _key)
	: key(_key)
	, height(uniform())
	, size(1)
	, left(null)
	, right(null)
{
	relax();
}

void TCartNode::relax() {
	size = 1 + left->size + right->size;
	sum = key + left->sum + right->sum;
	maxr = max(0LL, max(right->maxr, left->maxr + key + right->sum));
	maxl = max(0LL, max(left->maxl, right->maxl + key + left->sum));
	maxs = max(0LL, max(key + left->maxr + right->maxl, max(left->maxs, right->maxs)));
}

void split(TCartNode *node, size_t leftSize, TCartNode **left, TCartNode **right) {
	if (node == null) {
		*left = *right = (TCartNode*)null;
		return;
	}

	if (node->left->size + 1 <= leftSize) {
		split(node->right, leftSize - 1 - node->left->size, left, right);
		node->right = *left;
		*left = node;
	} else {
		split(node->left, leftSize, left, right);
		node->left = *right;
		*right = node;
	}
	node->relax();
}

TCartNode *merge(TCartNode *left, TCartNode *right) {
	if (left == null) {
		return right;
	}

	if (right == null) {
		return left;
	}

	if (left->height < right->height) {
		right->left = merge(left, right->left);
		right->relax();
		return right;
	} else {
		left->right = merge(left->right, right);
		left->relax();
		return left;
	}
}

int main() {
	null = new TCartNode();

	int n, m, c;
	fin >> n >> m >> c;
	vector<long long> x(n), p(n - 1);
	for (int i = 0; i < n; ++i) {
		fin >> x[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		fin >> p[i];
	}
	TCartNode *tree = null;
	for (int i = 0; i < n - 1; ++i) {
		TCartNode *node = new TCartNode((x[i + 1] - x[i]) * 100 - 2 * p[i] * c);
		tree = merge(tree, node);
	}

	double ans = 0.0;

	for (int i = 0; i < m; ++i) {
		int l, r;
		fin >> l >> r;
		--l; --r;
		TCartNode *left, *middle, *right;
		split(tree, l, &left, &middle);
		split(middle, r - l, &middle, &right);
		ans += 0.005 * middle->maxs;
		tree = merge(merge(left, middle), right);
	}

	fout.precision(10);
	fout << ans << '\n';

	return 0;
}