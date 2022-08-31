#include <cstdio>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;

struct Node {
	int l, r;
	vector<int> choose;
	Node *ls, *rs;

	void add(int l, int r, int x) {
		if (this->l == l && this->r == r) {
			choose.push_back(x);
			return;
		}
		if (r <= ls->r)
			return ls->add(l, r, x);
		if (l >= rs->l)
			return rs->add(l, r, x);
		ls->add(l, ls->r, x);
		rs->add(rs->l, r, x);
	}

	void dfs(int dep);
};

const int N = 10010;

int n, q;
Node* seg;
bitset<N> ans;

bitset<N> stk[30];

Node* build(int l, int r) {
	static Node pool[N * 2];
	static Node* ptop = pool;
	Node* p = ptop;
	++ptop;
	p->l = l;
	p->r = r;
	if (l == r)
		return p;
	int mid = (l + r) / 2;
	p->ls = build(l, mid);
	p->rs = build(mid + 1, r);
	return p;
}

int main() {
	scanf("%d%d", &n, &q);
	seg = build(1, n);
	while (q--) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		seg->add(l, r, x);
	}
	stk[0].set(0);
	seg->dfs(0);
	int c = 0;
	for (int i = 1; i <= n; ++i)
		c += ans[i];
	printf("%d\n", c);
	for (int i = 1; i <= n; ++i)
		if (ans[i])
			printf("%d ", i);
	return 0;
}

void Node::dfs(int dep) {
	for (int x : choose)
		stk[dep] |= stk[dep] << x;
	if (l == r)
		ans |= stk[dep];
	else {
		stk[dep + 1] = stk[dep];
		ls->dfs(dep + 1);
		stk[dep + 1] = stk[dep];
		rs->dfs(dep + 1);
	}
}