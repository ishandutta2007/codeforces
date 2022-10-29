#include <iostream>
const int Q = 1e5+1;

struct TNode 
{
	bool flip;
	int l, r, count;
	TNode *lc, *rc;
	TNode()
	{
		flip = false;
		count = 0;
		lc = rc = nullptr;
	}
};
TNode* root[Q];

void build(TNode* node, int l, int r)
{
	node->l = l;
	node->r = r;
	if (l == r)
		return;
	node->lc = new TNode;
	build(node->lc, l, (l + r) / 2);
	node->rc = new TNode;
	build(node->rc, (l + r) / 2 + 1, r);
}

TNode* flip(TNode* node)
{
	// std::cout << "flip " << node->l << " " << node->r << std::endl;
	node->flip ^= true;
	node->count = node->r - node->l + 1 - node->count;
	return node;
}

void lazy(TNode* node)
{
	if (!node->flip)
		return;
	// std::cout << "lazy " << node->l << " " << node->r << std::endl;
	node->flip = false;
	TNode* l = new TNode;
	*l = *node->lc;
	node->lc = flip(l);
	TNode* r = new TNode;
	*r = *node->rc;
	node->rc = flip(r);
}

TNode* update(TNode* node, int pos, int type)
{
	// std::cout << "update " << node->l << " " << node->r << std::endl;
	if (pos < node->l || node->r < pos)
		return node;
	// std::cout << "pos " << pos << std::endl;
	TNode* res = new TNode;
	*res = *node;
	if (res->l == res->r)
	{
		if (type == 1)
			res->count = 1;
		else 
			res->count = 0;
		// std::cout << "count " << res->count << std::endl;
		return res;
	}
	lazy(node);
	*res = *node;
	res->lc = update(node->lc, pos, type);
	res->rc = update(node->rc, pos, type);
	res->count = res->lc->count + res->rc->count;
	// std::cout << "count " << res->count << std::endl;
	return res;
}

TNode* flip(TNode* node, int l, int r)
{
	if (r < node->l || node->r < l)
		return node;
	TNode* res = new TNode;
	*res = *node;
	if (l <= res->l && res->r <= r)
		return flip(res);
	lazy(node);
	*res = *node;
	res->lc = flip(node->lc, l, r);
	res->rc = flip(node->rc, l, r);
	res->count = res->lc->count + res->rc->count;
	return res;
}

int main()
{
	int n, m, q; std::cin >> n >> m >> q;
	root[0] = new TNode;
	build(root[0], 1, m * n);
	for (int i = 1; i <= q; ++i)
	{
		int t; std::cin >> t;
		if (t == 1 || t == 2)
		{
			int x, y; std::cin >> x >> y;
			root[i] = update(root[i - 1], m * (x - 1) + y, t);
		}
		else if (t == 3)
		{
			int x; std::cin >> x;
			root[i] = flip(root[i - 1], m * (x - 1) + 1, m * x);
		}
		else 
		{
			int k; std::cin >> k;
			root[i] = root[k];
		}
		// std::cout << "lazy 3-4 " << root[i]->lc->rc->flip << std::endl;
		std::cout << root[i]->count << std::endl;
	}
	return 0;
}