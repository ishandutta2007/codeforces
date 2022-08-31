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
	TCartNode *left, *right;
	int x, y;
	int id;
	int key, maxKey;
	int w;

	TCartNode(int _x = 0, int _id = 0, int _key = 0);
};

TCartNode *null;

int uniform() {
	int res = 0;
	for (int i = 0; i < 5; ++i) {
		res = res * RAND_MAX + rand();
	}
	return res;
}

TCartNode::TCartNode (int _x, int _id, int _key)
	: x(_x)
	, y(uniform())
	, id(_id)
	, key(_key)
	, maxKey(_key)
	, w(1)
	, left(null)
	, right(null)
{
}

void relax(TCartNode *node) {
	if (node == null) {
		return;
	}
	node->w = node->left->w + node->right->w + 1;
	node->maxKey = max(node->key, max(node->left->maxKey, node->right->maxKey));
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

void split(TCartNode *node, int x, TCartNode **left, TCartNode **right) {
	if (node == null) {
		*left = *right = null;
		return;
	}

	if (node->x <= x) {
		split(node->right, x, left, right);
		node->right = *left;
		*left = node;
	} else {
		split(node->left, x, left, right);
		node->left = *right;
		*right = node;
	}
	relax(node);
}

TCartNode *insert(TCartNode *root, TCartNode *node) {
	TCartNode *left, *right;
	split(root, node->x, &left, &right);
	return merge(left, merge(node, right));
}

struct TMan {
	int r, a, id;
	TMan(int _r = 0, int _a = 0, int _id = 0)
		: r(_r)
		, a(_a)
		, id(_id)
	{
	}

	bool operator<(const TMan &b) const {
		return r < b.r;
	}
};

struct TQuery {
	int a, id;
	TQuery(int _a = 0, int _id = 0)
		: a(_a)
		, id(_id)
	{
	}
};

int main() {
	fout.precision(10);
	fout << fixed;

	null = new TCartNode(0, -1, 0);
	null->left = null->right = null;
	null->w = 0;
	null->maxKey = -1;

	int N, K;
	fin >> N >> K;
	vector<TMan> men(N);
	for (int i = 0; i < N; ++i) {
		fin >> men[i].r;
		men[i].id = i;
	}

	for (int i = 0; i < N; ++i) {
		fin >> men[i].a;
	}

	vector< vector<TQuery> > queries(N);
	int M;
	fin >> M;
	for (int i = 0; i < M; ++i) {
		int x, y;
		fin >> x >> y;
		--x; --y;
		if (men[x].r >= men[y].r) {
			queries[x].push_back(TQuery(men[y].a, i));
		} else {
			queries[y].push_back(TQuery(men[x].a, i));
		}
	}

	sort(men.begin(), men.end());

	TCartNode *root = null;
	vector<int> leader(N);
	for (size_t i = 0; i < men.size();) {
		size_t j = i;
		while (j < men.size() && men[i].r == men[j].r) {
			root = insert(root, new TCartNode(men[j].a, men[j].id));
			++j;
		}
		for (size_t k = i; k < j; ++k) {
			TCartNode *left, *middle, *right;
			split(root, men[k].a - K - 1, &left, &middle);
			split(middle, men[k].a + K, &middle, &right);
			leader[men[k].id] = middle->w;
			root = merge(left, merge(middle, right));
		}
		i = j;
	}

	root = null;
	sort(men.rbegin(), men.rend());
	vector<int> ans(M, -1);
	for (size_t i = 0; i < men.size();) {
		size_t j = i;
		while (j < men.size() && men[i].r == men[j].r) {
			root = insert(root, new TCartNode(men[j].a, men[j].id, leader[men[j].id]));
			++j;
		}
		for (size_t k = i; k < j; ++k) {
			for (size_t q = 0; q < queries[men[k].id].size(); ++q) {
				TQuery query = queries[men[k].id][q];
				int high = min(men[k].a, query.a) + K;
				int low = max(men[k].a, query.a) - K;
				TCartNode *left, *middle, *right;
				split(root, low - 1, &left, &middle);
				split(middle, high, &middle, &right);
				ans[query.id] = max(ans[query.id], middle->maxKey);
				root = merge(left, merge(middle, right));
			}
		}
		i = j;
	}

	for (int i = 0; i < M; ++i) {
		fout << ans[i] << '\n';
	}

	return 0;
}