#include <cstdio>

#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

struct node {
	int l, r, d, lazy;
	node *ls, *rs;

	void push_down();
	int get_d() const;
	int query(int l, int r);
	void change(int l, int r, int k);
};

const int N = 300010;

int a[N * 2];
int ql[N], qr[N], qk[N];

node* build(int* l, int* r);

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d", &ql[i], &qr[i], &qk[i]);
		a[i * 2 - 1] = ql[i];
		a[i * 2] = ++qr[i];
	}
	sort(a + 1, a + q * 2 + 1);
	a[0] = 1;
	a[q * 2 + 1] = n + 1;
	int *fst = a, *lst = unique(a, a + q * 2 + 2) - 1;
	node* seg = build(fst, lst);
	for (int i = 1; i <= q; ++i) {
		seg->change(ql[i], qr[i], qk[i]);
		printf("%d\n", seg->get_d());
	}
	return 0;
}

node* build(int* l, int* r) {
	static node pool[N * 4];
	static node* top = pool;
	node* p = top;
	++top;
	p->l = *l;
	p->r = *r;
	p->d = *r - *l;
	if (l + 1 == r)
		return p;
	int* mid = l + (r - l) / 2;
	p->ls = build(l, mid);
	p->rs = build(mid, r);
	return p;
}

void node::push_down() {
	if (lazy == 0)
		return;
	d = (lazy - 1) * (r - l);
	ls->lazy = lazy;
	rs->lazy = lazy;
	lazy = 0;
}

int node::get_d() const {
	if (lazy == 0)
		return d;
	if (lazy == 1)
		return 0;
	return r - l;
}

void node::change(int l, int r, int k) {
	if (this->l == l && this->r == r) {
		lazy = k;
		return;
	}
	push_down();
	if (r <= ls->r)
		ls->change(l, r, k);
	else if (l >= rs->l)
		rs->change(l, r, k);
	else {
		ls->change(l, ls->r, k);
		rs->change(rs->l, r, k);
	}
	d = ls->get_d() + rs->get_d();
}

int node::query(int l, int r) {
	if (this->l == l && this->r == r)
		return get_d();
	push_down();
	if (r <= ls->r)
		return ls->query(l, r);
	if (l >= rs->l)
		return rs->query(l, r);
	return ls->query(l, ls->r) + rs->query(rs->l, r);
}