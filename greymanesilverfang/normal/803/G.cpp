// #segment_tree #rmq

#include <algorithm>
#include <cstdio>
#define get_f(i, j) f[i][(j - 1) % n + 1]
const int N = 1e5+1, INF = 1e9+7;
int n, k, b[N], f[30][N];
struct TNode
{
	int l, r, lz, res;
	TNode *lc, *rc;
	TNode(int _l, int _r) : l(_l), r(_r), lz(), lc(), rc() 
	{
		int k = 31 - __builtin_clz(r - l + 1);
		res = std::min(get_f(k, l), get_f(k, r - (1 << k) + 1));
	}
};
TNode *root;

void build_rmq()
{
	for (int i = 1; i <= n; ++i)
		get_f(0, i) = b[i];
	for (int i = 0; 1 << i < n * k; ++i)
		for (int j = 1; j <= n; ++j)
			get_f(i + 1, j) = std::min(get_f(i, j), get_f(i, j + (1 << i)));
}

void modify(int x, TNode* n)
{
	n->res = n->lz = x;
}

void lazy(TNode* n)
{
	int mid = (n->l + n->r) / 2;
	if (n->lc == nullptr)
		n->lc = new TNode(n->l, mid);
	if (n->rc == nullptr)
		n->rc = new TNode(mid + 1, n->r);
	if (n->lz == 0)
		return;
	modify(n->lz, n->lc);
	modify(n->lz, n->rc);
	n->lz = 0;
}

void refresh(TNode* n)
{
	n->res = std::min(n->lc->res, n->rc->res);
}

void update(int l, int r, int x, TNode* n = root)
{
	if (n->r < l || r < n->l)
		return;
	if (l <= n->l && n->r <= r)
	{
		modify(x, n);
		return;
	}
	lazy(n);
	update(l, r, x, n->lc);
	update(l, r, x, n->rc);
	refresh(n);
}

int query(int l, int r, TNode* n = root)
{
	if (n->r < l || r < n->l)
		return INF;
	if (l <= n->l && n->r <= r)
		return n->res;
	lazy(n);
	return std::min(query(l, r, n->lc), query(l, r, n->rc));
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	build_rmq();
	root = new TNode(1, n * k);
	int q; scanf("%d", &q);
	for (int i = 1; i <= q; ++i)
	{
		int t; scanf("%d", &t);
		switch (t)
		{
			case 1:
			{
				int l, r, x; scanf("%d%d%d", &l, &r, &x);
				update(l, r, x);
				break;
			}
			case 2:
			{
				int l, r; scanf("%d%d", &l, &r);
				printf("%d\n", query(l, r));
				break;
			}
		}
	}
	return 0;
}