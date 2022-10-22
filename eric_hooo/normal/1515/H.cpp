#include <bits/stdc++.h>
#define SUM(x) ((x) ? (x)->sum : 0)
#define NED(x, d) ((x) ? (x)->ned[(d)] : NULL)
#define M0(x) ((x) ? (x)->m0 : 0)
#define M1(x) ((x) ? (x)->m1 : 0)
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int N = (1 << 20) - 1;

struct Node {
	int sum, rev;
	int m0, m1;
	Node *lson, *rson;
	Node() {rev = sum = 0, lson = rson = NULL;}
	void pushup(int dep) {
		sum = SUM(lson) + SUM(rson);
		m0 = M0(lson) | M0(rson) | (lson != NULL) << dep, m1 = M1(lson) | M1(rson) | (rson != NULL) << dep;
	}
	void REV(Node *T, int r, int dep) {
		if (!T) return ;
		T->rev ^= r; if (dep >= 0 && (r >> dep & 1)) swap(T->lson, T->rson);
		int t0 = T->m0 & r, t1 = T->m1 & r;
		T->m0 += t1 - t0, T->m1 += t0 - t1;
	}
	void pushdown(int dep) {
		if (!rev) return ;
		REV(lson, rev, dep - 1), REV(rson, rev, dep - 1), rev = 0;
	}
}POOL[1 << 24], *CUR = POOL, *BEG, *T;

typedef pair <Node *, Node *> pnn;

int a[1 << 20];
int sum[1 << 20 | 10];

Node *Build(int l, int r, int dep) {
//	if (sum[r + 1] - sum[l] == 0) return NULL;
	Node *T = CUR++;
	if (l == r) {
		T->sum = a[l] > 0;
		return T;
	}
	int mid = l + r >> 1;
	T->lson = Build(l, mid, dep - 1), T->rson = Build(mid + 1, r, dep - 1), T->pushup(dep);
	return T;
}

pnn Split(Node *T, int l, int r, int dep, int L, int R) {
	if (!T) return pnn(NULL, NULL);
	if (l == L && r == R) return pnn(T, NULL);
	T->pushdown(dep);
	int mid = l + r >> 1;
	Node *nT = CUR++;
	if (R <= mid) {
		pnn tmp = Split(T->lson, l, mid, dep - 1, L, R);
		nT->lson = tmp.fi, T->lson = tmp.se;
		nT->pushup(dep), T->pushup(dep); return mp(nT, T);
	} else if (L > mid) {
		pnn tmp = Split(T->rson, mid + 1, r, dep - 1, L, R);
		nT->rson = tmp.fi, T->rson = tmp.se;
		nT->pushup(dep), T->pushup(dep); return mp(nT, T);
	} else {
		pnn t1 = Split(T->lson, l, mid, dep - 1, L, mid);
		pnn t2 = Split(T->rson, mid + 1, r, dep - 1, mid + 1, R);
		nT->lson = t1.fi, nT->rson = t2.fi, T->lson = t1.se, T->rson = t2.se;
		nT->pushup(dep), T->pushup(dep); return mp(nT, T);
	}
}

Node *Merge(Node *T1, Node *T2, int dep) {
	if (!T1 || !T2) return T1 ? T1 : T2;
	if (dep == -1) {T1->sum |= T2->sum; return T1;}
	T1->pushdown(dep), T2->pushdown(dep);
	T1->lson = Merge(T1->lson, T2->lson, dep - 1);
	T1->rson = Merge(T1->rson, T2->rson, dep - 1);
	T1->pushup(dep);
	return T1;
}

void CalcAnd(Node *T, int dep, int x) {
	if (!T) return ;
	if (!(T->m1 >> x & 1)) return ;
	if (!(T->m0 >> x & 1)) {T->REV(T, 1 << x, dep); return ;}
	T->pushdown(dep);
	if (dep == x) {T->lson = Merge(T->lson, T->rson, dep - 1), T->rson = NULL, T->pushup(dep); return ;}
	CalcAnd(T->lson, dep - 1, x), CalcAnd(T->rson, dep - 1, x);
	T->pushup(dep);
}

void XorOp(Node *T, int x) {T->REV(T, x, 19);}

void AndOp(Node *T, int x) {
	for (int i = 0; i < 20; i++) {
		if (!(x >> i & 1)) CalcAnd(T, 19, i);
	}
}

int main() {
	int n, q; scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {int x; scanf("%d", &x), a[x]++;}
	for (int i = 0; i <= N; i++) sum[i + 1] = sum[i] + a[i];
	T = Build(0, N, 19);
	while (q--) {
		int op, l, r, x; scanf("%d%d%d", &op, &l, &r);
		if (op <= 3) {
			scanf("%d", &x);
			pnn tmp = Split(T, 0, N, 19, l, r);
			if (op == 1) AndOp(tmp.fi, x);
			else if (op == 2) XorOp(tmp.fi, N), AndOp(tmp.fi, x ^ N), XorOp(tmp.fi, N);
			else XorOp(tmp.fi, x);
			T = Merge(tmp.fi, tmp.se, 19);
		} else {
			pnn tmp = Split(T, 0, N, 19, l, r);
			printf("%d\n", SUM(tmp.fi));
			T = Merge(tmp.fi, tmp.se, 19);
		}
	}
	return 0;
}