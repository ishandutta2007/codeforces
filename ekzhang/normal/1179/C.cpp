#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
#define MAXM 300013
#define MAXFEN 1000013

struct tnode {
	tnode *l, *r;
	int y = rand() ^ (rand() << 16);

	/* Data */
	int x, val;

	/* Lazy */
	int lz;

	/* Aggregate values */
	int sz, mi;

	tnode() { update(); }

	void push() {
		// Propagate lazy
		if (lz) {
			val += lz;
			mi += lz;
			if (l) l->lz += lz;
			if (r) r->lz += lz;
			lz = 0;
		}
	}

	void update() {
		sz = 1;
		mi = val;
		if (l) {
			l->push();
			sz += l->sz;
			mi = min(mi, l->mi);
		}
		if (r) {
			r->push();
			sz += r->sz;
			mi = min(mi, r->mi);
		}
	}

	void set(int x) { push(); this->val = x; update(); }

} vals[MAXN];
int mem = 0;

void split(tnode* t, tnode*& l, tnode*& r, int k) {
	if (!t) { l = r = nullptr; return; }
	t->push();
	if (t->x < k)
		l = t, split(t->r, t->r, r, k);
	else
		r = t, split(t->l, l, t->l, k);
	t->update();
}

void split_at(tnode* t, tnode*& l, tnode*& r, int idx) {
	if (!t) { l = r = nullptr; return; }
	t->push();
	int tidx = t->l ? t->l->sz : 0;
	if (tidx < idx)
		l = t, split_at(t->r, t->r, r, idx - tidx - 1);
	else
		r = t, split_at(t->l, l, t->l, idx);
	t->update();
}

void merge(tnode*& t, tnode* l, tnode* r) {
	if (!l || !r) { t = l ? l : r; return; }
	if (l->y < r->y)
		t = l, t->push(), merge(t->r, t->r, r);
	else
		t = r, t->push(), merge(t->l, l, t->l);
	t->update();
}

int N, M, Q;
int A[MAXN], B[MAXM];
int fen[MAXFEN];
tnode* t = nullptr;

void addp(int b, int d=1) {
	for (int j = b + 1; j < MAXFEN; j += j & -j)
		fen[j] += d;
	tnode *l, *r;
	split(t, l, r, b + 1);
	if (l)
		l->lz += d;
	merge(t, l, r);
}

int qry(int b) {
	int ans = 0;
	for (b++; b; b -= b & -b)
		ans += fen[b];
	return ans;
}

int solve(tnode* t) {
	if (!t)
		return -1;
	t->push();
	if (t->mi >= 0)
		return -1;
	int k = solve(t->r);
	if (k != -1)
		return k;
	if (t->val < 0)
		return t->x;
	return solve(t->l);
}

// void debug(tnode* t) {
// 	if (!t) return;
// 	t->push();
// 	debug(t->l);
// 	cout << t->x << ' ' << t->val << endl;
// 	debug(t->r);
// 	return;
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	tnode *l, *r;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		tnode* n = &vals[i];
		split(t, l, r, A[i]);
		n->x = A[i];
		n->set(-N + (l ? l->sz : 0));
		if (r) r->lz++;
		merge(t, l, n);
		merge(t, t, r);
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		addp(B[i]);
	}

	// debug(t);

	cin >> Q;
	while (Q--) {
		int typ; cin >> typ;
		if (typ == 1) {
			int i, x; cin >> i >> x; --i;
			int xp = A[i];
			A[i] = x;

			tnode *l, *r, *n;
			split(t, l, r, xp);
			split_at(r, n, r, 1);
			assert(n->x == xp);

			if (r) r->lz--;
			merge(t, l, r);

			split(t, l, r, x);
			n->x = x;
			n->set(-N + (l ? l->sz : 0) + (M - qry(x - 1)));

			if (r) r->lz++;
			merge(t, l, n);
			merge(t, t, r);
		}
		else {
			int i, x; cin >> i >> x; --i;
			addp(B[i], -1);
			B[i] = x;
			addp(B[i]);
		}

		// debug(t);

		// query
		cout << solve(t) << '\n';
	}

	cout.flush();
	return 0;
}