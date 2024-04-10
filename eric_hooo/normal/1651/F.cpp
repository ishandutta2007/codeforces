#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef pair <long long, long long> pll;

pll operator + (const pll &A, const pll &B) {
	return mp(A.fi + B.fi, A.se + B.se);
}

pll operator - (const pll &A, const pll &B) {
	return mp(A.fi - B.fi, A.se - B.se);
}

deque <pip> a;
int C[200010], R[200010], K[200010];
int mem[200010];
pll Pre[200010];
vector <int> node[200010];

struct Node {
	long long RSum, CSum;
	Node *lson, *rson;
	void pushup() {
		RSum = lson->RSum + rson->RSum;
		CSum = lson->CSum + rson->CSum;
	}
}POOL[5000000], *CUR = POOL;

void Build(Node *&T, int l, int r) {
	if (T == NULL) T = CUR++;
	if (l == r) {
		T->RSum = T->CSum = 0;
		return ;
	}
	int mid = l + r >> 1;
	Build(T->lson, l, mid), Build(T->rson, mid + 1, r);
}

Node *Update(Node *T, int l, int r, int pos) {
	Node *TT = CUR++; TT->lson = T->lson, TT->rson = T->rson;
	if (l == r) {
		TT->RSum += T->RSum + R[l], TT->CSum += T->CSum + C[l];
		return TT;
	}
	int mid = l + r >> 1;
	if (pos <= mid) TT->lson = Update(T->lson, l, mid, pos);
	else TT->rson = Update(T->rson, mid + 1, r, pos);
	TT->pushup();
	return TT;
}

pll Query(Node *T, int l, int r, int L, int R) {
	if (l == L && r == R) return mp(T->RSum, T->CSum);
	int mid = l + r >> 1;
	if (R <= mid) return Query(T->lson, l, mid, L, R);
	if (L > mid) return Query(T->rson, mid + 1, r, L, R);
	return Query(T->lson, l, mid, L, mid) + Query(T->rson, mid + 1, r, mid + 1, R);
}

int Binary(Node *T, int l, int r, int L, int R, int d, long long &h) {
	if (l == L && r == R) {
		long long delta = d * (Pre[r].fi - Pre[l - 1].fi - T->RSum) + T->CSum;
		if (h >= delta) {
			h -= delta;
			return -1;
		}
		if (l == r) return l;
	}
	int mid = l + r >> 1;
	if (R <= mid) return Binary(T->lson, l, mid, L, R, d, h);
	if (L > mid) return Binary(T->rson, mid + 1, r, L, R, d, h);
	int tmp = Binary(T->lson, l, mid, L, mid, d, h);
	return tmp == -1 ? Binary(T->rson, mid + 1, r, mid + 1, R, d, h) : tmp;
}

Node *rt[200010];
vector <int> all;

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &C[i], &R[i]);
		Pre[i] = Pre[i - 1] + mp(R[i], C[i]);
		K[i] = C[i] / R[i];
		all.push_back(K[i]);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 1; i <= n; i++) {
		int p = lower_bound(all.begin(), all.end(), K[i]) - all.begin();
		node[p].push_back(i);
	}
	Build(rt[0], 1, n);
	for (int i = 0; i < all.size(); i++) {
		rt[i + 1] = rt[i];
		for (auto it : node[i]) {
			rt[i + 1] = Update(rt[i + 1], 1, n, it);
		}
	}
	a.push_back(mp(-INF, mp(1, n)));
	int q; scanf("%d", &q);
	long long ans = 0;
	while (q--) {
		int t; long long h; scanf("%d%lld", &t, &h);
		while (a.size() && h) {
			int x = a[0].fi, l = a[0].se.fi, r = a[0].se.se; a.pop_front();
			if (x >= INF) {
				x -= INF;
				int cur = min(mem[l] + 1ll * (t - x) * R[l], (long long)C[l]);
				if (h < cur) cur -= h, a.push_front(mp(INF + t, mp(l, r))), h = 0, mem[l] = cur;
				else h -= cur;
				continue;
			}
			int d = t - x; d = lower_bound(all.begin(), all.end(), d) - all.begin();
			pll tmp = Query(rt[d], 1, n, l, r), tot = Pre[r] - Pre[l - 1];
			long long delta = (t - x) * (tot.fi - tmp.fi) + tmp.se;
			if (h < delta) {
				int pos = Binary(rt[d], 1, n, l, r, t - x, h);
				if (!h) a.push_front(mp(x, mp(pos, r)));
				else {
					assert(pos != -1);
					if (pos < r) a.push_front(mp(x, mp(pos + 1, r)));
					a.push_front(mp(INF + t, mp(pos, pos))), mem[pos] = min(1ll * (t - x) * R[pos], (long long)C[pos]) - h;
					h = 0;
				}
			} else h -= delta;
		}
		if (!a.size() || a[0].se.fi > 1) a.push_front(mp(t, mp(1, a.size() ? a[0].se.fi - 1 : n)));
		ans += h;
	}
	printf("%lld\n", ans);
	return 0;
}