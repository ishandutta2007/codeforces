#include <cstdio>

#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int l, r;
	Node *ls, *rs;
	vector<int> req;

	void add(int l, int r, int x) {
		if (this->l == l && this->r == r) {
			req.push_back(x);
			return;
		}
		if (r <= ls->r)
			return ls->add(l, r, x);
		if (l >= rs->l)
			return rs->add(l, r, x);
		ls->add(l, ls->r, x);
		rs->add(rs->l, r, x);
	}

	void add(int k, int x) {
		req.push_back(x);
		if (l == r)
			return;
		if (k <= ls->r)
			ls->add(k, x);
		else
			rs->add(k, x);
	}

	void dfs();
};

const int N = 500010;

int n, q;
int a[N], lst[N], tab[N];
int ans[N];
vector<pair<int, int> > qry[N];

Node* seg;

Node* build(int l, int r);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		lst[i] = tab[a[i]];
		tab[a[i]] = i;
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		qry[r].emplace_back(l, i);
	}
	seg = build(1, n);
	for (int i = 1; i <= n; ++i) {
		seg->add(lst[i] + 1, i, a[i]);
		if (lst[i])
			seg->add(lst[lst[i]] + 1, lst[i], -a[i]);
		for (auto q : qry[i])
			seg->add(q.first, q.second + N);
	}
	for (int x = 1; x < N; ++x)
		if (tab[x])
			seg->add(lst[tab[x]] + 1, tab[x], -x);
	seg->dfs();
	for (int i = 1; i <= q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}

void Node::dfs() {
	if (l != r) {
		ls->dfs();
		rs->dfs();
	}
	static int tm[N];
	vector<pair<int, int> > qs;
	for (int i = 0; i < req.size(); ++i) {
		int x = req[i];
		if (x < 0) {
			while (!qs.empty() && qs.back().second > tm[-x]) {
				ans[qs.back().first] = -x;
				qs.pop_back();
			}
		} else if (x < N)
			tm[x] = i;
		else {
			qs.emplace_back(x - N, i);
		}
	}
}

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