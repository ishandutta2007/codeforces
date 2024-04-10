#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int ans[200010];

struct Node {
	int x, id, add, tag, fix;
	Node *lson, *rson;
	void init(int X, int ID) {
		x = X, id = ID, add = tag = 0, fix = rand() << 15 | rand(), lson = rson = NULL;
	}
	void addtag(int p, int q) {tag += p, x += p, add += q, ans[id] += q;}
	void pushdown() {
		if (!add && !tag) return ;
		if (lson) lson->addtag(tag, add);
		if (rson) rson->addtag(tag, add);
		tag = add = 0;
	}
}POOL[200010], *CUR = POOL, *rt = NULL;

typedef pair <Node *, Node *> pnn;

Node *newnode(int x, int id) {CUR->init(x, id); return CUR++;}

Node *merge(Node *l, Node *r) {
	if (!l || !r) return l ? l : r;
	if (l->fix > r->fix) {l->pushdown(), l->rson = merge(l->rson, r); return l;}
	else {r->pushdown(), r->lson = merge(l, r->lson); return r;}
}

pnn split(Node *T, int x) {
	if (!T) return pnn(NULL, NULL);
	T->pushdown();
	if (x < T->x) {pnn t = split(T->lson, x); T->lson = t.se; return mp(t.fi, T);}
	else {pnn t = split(T->rson, x); T->rson = t.fi; return mp(T, t.se);}
}

void Insert(int x, int id) {
	pnn t = split(rt, x);
	rt = merge(t.fi, merge(newnode(x, id), t.se));
}

void Append(Node *T, Node *&rt) {
	if (!T) return ;
	T->pushdown();
	Append(T->lson, rt), Append(T->rson, rt);
	T->init(T->x, T->id);
	pnn t = split(rt, T->x);
	rt = merge(t.fi, merge(T, t.se));
}

void Flush(Node *T) {
	if (!T) return ;
	T->pushdown();
	Flush(T->lson), Flush(T->rson);
}

vector <pii> a;

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a.push_back(mp(x, y));
	}
	sort(a.begin(), a.end(), [](const pii &a, const pii &b) {return a.se != b.se ? a.se > b.se : a.fi < b.fi;});
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int x; scanf("%d", &x);
		Insert(x, i);
	}
	for (auto it : a) {
		int x = it.fi;
		pnn t1 = split(rt, x - 1);
		if (t1.se) t1.se->addtag(-x, 1);
		pnn t2 = split(t1.se, x + x - 1);
		Append(t2.fi, t1.fi);
		rt = merge(t1.fi, t2.se);
	}
	Flush(rt);
	for (int i = 0; i < q; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}