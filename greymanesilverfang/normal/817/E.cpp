// 3 types of queries: Add number x, remove number x, 
// and count how many remaining numbers xor sum of which with x is less than y

#include <cstdio>
using namespace std;

struct TNode {
	int cnt;
	TNode *child[2];
	TNode() : cnt(0) {
		child[0] = child[1] = nullptr;
	}
} *root;

void update(int x, int cnt) {
	TNode *cur = root;
	for (int i = 27; i--;) {
		if (cur->child[x>>i&1] == nullptr)
			cur->child[x>>i&1] = new TNode;
		(cur = cur->child[x>>i&1])->cnt += cnt;
	}
}

int query(int x, int y) {
	int res = 0;
	TNode *cur = root;
	for (int i = 27; i-- && cur != nullptr;) {
		if (y>>i&1 && cur->child[(y^x)>>i&1^1] != nullptr)
			res += cur->child[(y^x)>>i&1^1]->cnt;
		cur = cur->child[(y^x)>>i&1];
	}
	return res;
}

int main() {
	root = new TNode;
	int q; scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int t; scanf("%d", &t);
		if (t < 3) {
			int x; scanf("%d", &x);
			update(x, 3 - t * 2);
		} else {
			int x, y; scanf("%d%d", &x, &y);
			printf("%d\n", query(x, y));
		}
	}
}