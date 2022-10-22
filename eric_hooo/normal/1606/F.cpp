#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int N = 200000;

int PRT;

struct Tag {
	long long b;
	int k;
	Tag() {b = k = 0;}
	Tag(long long x, int y) {b = x, k = y;}
	bool empty() {return k == 0 && b == 0;}
	Tag operator + (const Tag &A) const {
		return Tag(b + A.b, k + A.k);
	}
	Tag operator >> (const int &x) const {
		return Tag(b - 1ll * x * k, k);
	}
};

struct Node {
	int sz, val;
	Tag tag;
	Node *lson, *rson;
	Node() {}
	Node(int x) {tag = Tag(), val = 0, sz = x, lson = rson = NULL;}
	void pushup() {
		val = (lson ? lson->val : 0);
	}
	void addtag(Tag t) {
		val += t.b, tag = tag + t;
	}
	void pushdown() {
		if (!lson) lson = new Node(sz + 1 >> 1);
		if (!rson) rson = new Node(sz >> 1);
		if (tag.empty()) return ;
		lson->addtag(tag), rson->addtag(tag >> (sz + 1 >> 1));
		tag = Tag();
	}
};

long long Query(Node *T, int l, int r, int x) {
	if (!T) return 0;
	if (l == r) return T->val;
	T->pushdown();
	int mid = l + r >> 1;
	return x <= mid ? Query(T->lson, l, mid, x) : Query(T->rson, mid + 1, r, x);
}

Node *Merge(Node *L, Node *R) {
	if (!L || !R) return L ? L : R;
	L->lson = Merge(L->lson, R->lson);
	L->rson = Merge(L->rson, R->rson);
	L->tag = L->tag + R->tag, L->val += R->val;
	return L;
}

void Flush(Node *&T) {
	if (!T) return ;
	if (T->val < 0) {
		T = NULL;
		return ;
	}
	if (T->sz == 1) return ;
	T->pushdown();
	if (T->rson->val >= 0) Flush(T->rson);
	else Flush(T->lson), Flush(T->rson);
	T->pushup();
}

int n, q;
vector <int> G[200010];
vector <pii> qry[200010];
int ans[200010];
int a[200010];

Node *Solve(int x, int last) {
	Node *tmp = NULL;
	for (auto v : G[x]) if (v != last) {
		Node *qwq = Solve(v, x);
		if (!qwq) qwq = new Node(N + 1);
		if (v == 7) PRT = 1;
		qwq->addtag(Tag(0, 1));
		qwq->addtag(Tag(-1, 0));
		if (v == 7) PRT = 0;
		Flush(qwq);
		if (!qwq) qwq = new Node(N + 1);
		qwq->addtag(Tag(1, 0));
		tmp = Merge(tmp, qwq);
	}
	for (auto it : qry[x]) {
		int k = it.fi, id = it.se;
		ans[id] = Query(tmp, 0, N, k);
	}
	return tmp;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int q; scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int v, k; scanf("%d%d", &v, &k);
		qry[v].push_back(mp(k, i));
	}
	Solve(1, 1);
	for (int i = 0; i < q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}