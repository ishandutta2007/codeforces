#include <bits/stdc++.h>
#define LB(x, y) (lower_bound((x).begin(), (x).end(), y))
using namespace std;

const int B = 3162;

int p[1000010], q[1000010], a[1000010];

struct Node {
	int sum;
	Node *lson, *rson;
	void pushup() {
		sum = lson->sum + rson->sum;
	}
}pool[30000000], *rt[1000010], *CUR = pool;

Node *newnode(int x) {
	CUR->sum = x;
	return CUR++;
}

Node *Build(int l, int r) {
	if (l == r) return newnode(0);
	int mid = l + r >> 1;
	Node *now = newnode(0);
	now->lson = Build(l, mid), now->rson = Build(mid + 1, r);
	now->pushup();
	return now;
}

Node *Update(Node *T, int l, int r, int pos) {
	if (l == r) return newnode(1);
	int mid = l + r >> 1;
	Node *now = newnode(0);
	now->lson = T->lson, now->rson = T->rson;
	if (pos <= mid) now->lson = Update(T->lson, l, mid, pos);
	else now->rson = Update(T->rson, mid + 1, r, pos);
	now->pushup();
	return now;
}

int Query(Node *T, int l, int r, int L, int R) {
	if (l == L && r == R) return T->sum;
	int mid = l + r >> 1;
	if (R <= mid) return Query(T->lson, l, mid, L, R);
	if (L > mid) return Query(T->rson, mid + 1, r, L, R);
	return Query(T->lson, l, mid, L, mid) + Query(T->rson, mid + 1, r, mid + 1, R);
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		q[x] = i;
	}
	rt[0] = Build(1, n);
	for (int i = 1; i <= n; i++) {
		a[i] = q[p[i]];
		rt[i] = Update(rt[i - 1], 1, n, a[i]);
	}
	int q; scanf("%d", &q);
	int lst = 0;
	while (q--) {
		int l, r, L, R; scanf("%d%d%d%d", &l, &r, &L, &R);
		l = (l - 1 + lst) % n, r = (r - 1 + lst) % n, L = (L - 1 + lst) % n + 1, R = (R - 1 + lst) % n + 1;
		if (l > r) swap(l, r);
		if (L > R) swap(L, R);
		int ans = Query(rt[r + 1], 1, n, L, R) - Query(rt[l], 1, n, L, R);
		printf("%d\n", ans);
		lst = ans + 1;
	}
	return 0;
}