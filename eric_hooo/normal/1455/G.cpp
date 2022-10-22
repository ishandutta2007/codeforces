#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int N = 200000;

struct Node {
	long long x, minj;
	Node *lson, *rson;
	Node() {x = 0, minj = INF, lson = rson = NULL;}
	void addtag(long long t) {x += t, minj += t;}
	void pushdown() {
		if (!x) return ;
		if (lson) lson->addtag(x);
		if (rson) rson->addtag(x);
		x = 0;
	}
	void pushup() {minj = min(lson ? lson->minj : INF, rson ? rson->minj : INF);}
}POOL[10000000], *CUR = POOL;

void Update(Node *&T, int l, int r, int pos, long long v) {
	if (!T) T = CUR++;
	if (l == r) {T->x = T->minj = v; return ;}
	T->pushdown();
	int mid = l + r >> 1;
	pos <= mid ? Update(T->lson, l, mid, pos, v) : Update(T->rson, mid + 1, r, pos, v);
	T->pushup();
}

long long Query(Node *T, int l, int r, int pos) {
	if (!T) return INF;
	if (l == r) return T->minj;
	T->pushdown();
	int mid = l + r >> 1;
	return (pos <= mid ? Query(T->lson, l, mid, pos) : Query(T->rson, mid + 1, r, pos));
}

Node *Merge(Node *L, Node *R, int sz) {
	if (!L || !R) return L ? L : R;
	if (sz == 1) {
		L->minj = min(L->minj, R->minj);
		return L;
	}
	L->pushdown(), R->pushdown();
	L->lson = Merge(L->lson, R->lson, sz + 1 >> 1);
	L->rson = Merge(L->rson, R->rson, sz >> 1);
	L->pushup();
	return L;
}

Node *Build(int x, long long v) {
	Node *T = CUR++;
	return Update(T, 0, N, x, v), T;
}

long long GetMin(Node *T) {return !T ? INF : T->minj;}

vector <Node *> st;

int main() {
	Node *cur = Build(0, 0);
	int n, ban; scanf("%d%d", &n, &ban);
	for (int i = 0; i < n; i++) {
		char op[5]; int x, w; scanf("%s", op);
		if (op[0] == 'e') cur = Merge(cur, st.back(), N + 1), st.pop_back();
		else if (op[0] == 'i') scanf("%d", &x), st.push_back(cur), cur = Build(x, Query(cur, 0, N, x)), Update(st.back(), 0, N, x, INF);
		else scanf("%d%d", &x, &w), Update(cur, 0, N, x, GetMin(cur) - w), cur->addtag(w);
		Update(cur, 0, N, ban, INF);
	}
	printf("%lld\n", GetMin(cur));
	return 0;
}