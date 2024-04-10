#include <cmath>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

struct Node {
	int l, r, val, lazy;
	Node *ls, *rs;

	int get() const;

	void pushDown();
	void change(int l, int r, int x);
	void change(int k, int x);
};

const int N = 35010, K = 51;

int lst[N], a[N];
int dp[N][K];

Node* seg[K];

Node* build(int l, int r);

int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 0; i < k; ++i)
		seg[i] = build(0, n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k; ++j) {
			seg[j - 1]->change(lst[a[i]], i - 1, 1);
			dp[i][j] = seg[j - 1]->get();
		}
		for (int j = 1; j < k; ++j)
			seg[j]->change(i, i, dp[i][j]);
		lst[a[i]] = i;
	}
	printf("%d\n", dp[n][k]);
	return 0;
}

Node* build(int l, int r) {
	static Node pool[N * K * 2];
	static Node* ptop = pool;
	Node* p = ptop++;
	p->l = l;
	p->r = r;
	if (l == r)
		return p;
	int mid = (l + r) / 2;
	p->ls = build(l, mid);
	p->rs = build(mid + 1, r);
	return p;
}

int Node::get() const {
	return val + lazy;
}

void Node::pushDown() {
	val += lazy;
	ls->lazy += lazy;
	rs->lazy += lazy;
	lazy = 0;
}

void Node::change(int l, int r, int x) {
	if (this->l == l && this->r == r) {
		lazy += x;
		return;
	}
	pushDown();
	if (r <= ls->r)
		ls->change(l, r, x);
	else if (l >= rs->l)
		rs->change(l, r, x);
	else {
		ls->change(l, ls->r, x);
		rs->change(rs->l, r, x);
	}
	val = max(ls->get(), rs->get());
}

void Node::change(int k, int x) {
	if (l == r) {
		val = x;
		lazy = 0;
		return;
	}
	pushDown();
	if (k <= ls->r)
		ls->change(k, x);
	else rs->change(k, x);
	val = max(ls->get(), rs->get());
}