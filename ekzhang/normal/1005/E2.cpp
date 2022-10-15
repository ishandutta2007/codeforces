#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define MAXLGN 19
int N, M;
int A[MAXN];

inline int sgn(int x) {
	return x ? (x > 0 ? 1 : -1) : 0;
}

struct tnode {
	tnode* l;
	tnode* r;
	int x, y;
	int val, sum;
	tnode() { y = rand() ^ (rand() << 16); }
	void update() { sum = val + (l ? l->sum : 0) + (r ? r->sum : 0); }
} vals[2 * MAXN * MAXLGN];
int mem = 0;
tnode* fen[2 * MAXN];

void split(tnode* t, tnode*& l, tnode*& r, int k) {
	if (!t) {
		l = r = nullptr;
		return;
	}
	if (t->x < k) {
		l = t;
		split(t->r, t->r, r, k);
	}
	else {
		r = t;
		split(t->l, l, t->l, k);
	}
	t->update();
}

void merge(tnode*& t, tnode* l, tnode* r) {
	if (!l || !r) {
		t = l ? l : r;
		return;
	}
	if (l->y < r->y) {
		t = l;
		merge(t->r, t->r, r);
	}
	else {
		t = r;
		merge(t->l, l, t->l);
	}
	t->update();
}

void upd(tnode*& t, int y, int val) {
	tnode *l, *r;
	split(t, l, t, y);
	split(t, t, r, y + 1);
	if (!t) t = &vals[mem++], t->x = y;
	t->val += val;
	t->update();
	merge(t, l, t);
	merge(t, t, r);
}

void update(int x, int y, int val) {
	for (x += MAXN; x < 2 * MAXN; x += x & -x) {
		upd(fen[x], y, val);
	}
}

int qry(tnode*& t, int y) {
	tnode* r;
	split(t, t, r, y);
	int ret = r ? r->sum : 0;
	merge(t, t, r);
	return ret;
}

int query(int x, int y) {
	int ret = 0;
	for (x += MAXN; x; x -= x & -x) {
		ret += qry(fen[x], y);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] = sgn(A[i] - M);
	}

	int d = 0, e = 0;
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		update(d + e, d - e, 1);
		if (A[i]) d += A[i];
		else ++e;
		ans += query(d + e - 1, d - e);
	}

	cout << ans << endl;
	return 0;
}