#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mod = 1000000009;

typedef pair <int, int> pii;

pii a[100010];
int n;

struct Node {
	int fix, ans, up, sz;
	Node *lson, *rson;
	int lsize() {return lson ? lson->sz : 0;}
	void init(int x) {fix = x, ans = 0, up = 1, sz = 1, lson = rson = NULL;}
	void pushup() {
		ans = 0, up = 1, sz = 1;
		if (lson) {
			ans += lson->ans, sz += lson->sz;
			if (lson->up && up) up = 0, ans++;
		}
		if (rson) {
			ans += rson->ans, sz += rson->sz;
			if (rson->up && up) up = 0, ans++;
		}
	}
}POOL[2000000], *CUR = POOL;

typedef pair <Node *, Node *> pnn;

Node *Merge(Node *L, Node *R) {
	if (!L || !R) return L ? L : R;
	if (L->fix > R->fix) {
		L->rson = Merge(L->rson, R);
		L->pushup();
		return L;
	} else {
		R->lson = Merge(L, R->lson);
		R->pushup();
		return R;
	}
}

pnn Split(Node *T, int k) {
	if (!T) return pnn(NULL, NULL);
	if (k <= T->lsize()) {
		pnn t = Split(T->lson, k);
		T->lson = t.se, T->pushup();
		return mp(t.fi, T);
	} else {
		pnn t = Split(T->rson, k - T->lsize() - 1);
		T->rson = t.fi, T->pushup();
		return mp(T, t.se);
	}
}

struct Segment_tree {
	Node *T[400010];
	vector <int> rng, sz;
	void Build(int now, int l, int r) {
		T[now] = NULL;
		for (int i = l; i <= r; i++) {
			CUR->init(a[i].se);
			T[now] = Merge(T[now], CUR);
			CUR++;
		}
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	void Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) {
			rng.push_back(now);
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) Query(now << 1, l, mid, L, R);
		else if (L > mid) Query(now << 1 | 1, mid + 1, r, L, R);
		else Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
	int Query(int L, int R) {
		if (L > R) return 0;
		rng.clear(), Query(1, 1, n, L, R);
		sz.clear();
		Node *rt = NULL;
		for (auto now : rng) {
			sz.push_back(T[now]->sz);
			rt = Merge(rt, T[now]);
		}
		int ans = rt->ans;
		for (int i = 0; i < rng.size(); i++) {
			int now = rng[i], s = sz[i];
			pnn t = Split(rt, s);
			T[now] = t.fi, rt = t.se;
		}
		return ans;
	}
}seg;

int main() {
	int k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d%d", &a[i].fi, &a[i].se);
	}
	int A, B, C, D; scanf("%d%d%d%d", &A, &B, &C, &D);
	for (int i = k + 1; i <= n; i++) {
		a[i].fi = (1ll * a[i - 1].fi * A + B) % mod;
		a[i].se = (1ll * a[i - 1].se * C + D) % mod;
	}
	sort(a + 1, a + n + 1);
	seg.Build(1, 1, n);
	int q; scanf("%d", &q);
	while (q--) {
		int L, R; scanf("%d%d", &L, &R);
		L = lower_bound(a + 1, a + n + 1, mp(L, -1)) - a;
		R = upper_bound(a + 1, a + n + 1, mp(R, 2000000000)) - a - 1;
		printf("%d\n", seg.Query(L, R));
	}
	return 0;
}