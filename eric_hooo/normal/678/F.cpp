#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

typedef pair <int, int> pii;

pii operator - (const pii &A, const pii &B) {
	return mp(A.fi - B.fi, A.se - B.se);
}

long long operator ^ (const pii &A, const pii &B) {
	return 1ll * A.fi * B.se - 1ll * A.se * B.fi;
}

long long operator * (const pii &A, const int &x) {
	return A.se - 1ll * A.fi * x;
}

pii st[300010];

bool Bad(pii a, pii b, pii c) {
	return ((b - a) ^ (c - a)) > 0;
}

void GetHull(pii *a, int &n) {
	int tp = 0;
	for (int i = 0; i < n; i++) {
		while (tp > 1 && Bad(st[tp - 2], st[tp - 1], a[i])) tp--;
		st[tp++] = a[i];
	}
	for (int i = 0; i < tp; i++) {
		a[i] = st[i];
	}
	n = tp;
}

namespace SEG {
	pii POOL[10000000], *CUR = POOL;
	int sz[1 << 20];
	pii *T[1 << 20];
	void Insert(int now, int l, int r, int L, int R) {
		if (l == L && r == R) {
			sz[now]++;
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) Insert(now << 1, l, mid, L, R);
		else if (L > mid) Insert(now << 1 | 1, mid + 1, r, L, R);
		else Insert(now << 1, l, mid, L, mid), Insert(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
	void GiveMem(int now, int l, int r) {
		T[now] = CUR, CUR += sz[now], sz[now] = 0;
		if (l == r) return ;
		int mid = l + r >> 1;
		GiveMem(now << 1, l, mid), GiveMem(now << 1 | 1, mid + 1, r);
	}
	void Insert(int now, int l, int r, int L, int R, pii x) {
		if (l == L && r == R) {
			T[now][sz[now]++] = x;
			return ;
		}
		int mid = l + r >> 1;
		if (R <= mid) Insert(now << 1, l, mid, L, R, x);
		else if (L > mid) Insert(now << 1 | 1, mid + 1, r, L, R, x);
		else Insert(now << 1, l, mid, L, mid, x), Insert(now << 1 | 1, mid + 1, r, mid + 1, R, x);
	}
	void Build(int now, int l, int r) {
		GetHull(T[now], sz[now]);
		if (l == r) return ;
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
	}
	long long Query(int now, int l, int r, int pos, int k) {
		while (sz[now] > 1 && T[now][sz[now] - 1] * k < T[now][sz[now] - 2] * k) sz[now]--;
		long long ans = sz[now] ? T[now][sz[now] - 1] * k : -INF;
		if (l == r) return ans;
		int mid = l + r >> 1;
		return max(ans, pos <= mid ? Query(now << 1, l, mid, pos, k) : Query(now << 1 | 1, mid + 1, r, pos, k));
	}
}

int OP[300010], X[300010], Y[300010];
int dead[300010];
long long ans[300010];
vector <int> ord;

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &OP[i]);
		if (OP[i] == 1) scanf("%d%d", &X[i], &Y[i]), X[i] *= -1;
		else scanf("%d", &X[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (OP[i] == 2) dead[X[i]] = i;
	}
	{ // PreCalc
		for (int i = 1; i <= n; i++) {
			if (OP[i] == 1) ord.push_back(i), SEG :: Insert(1, 1, n, i, dead[i] ? dead[i] : n);
		}
		SEG :: GiveMem(1, 1, n);
		sort(ord.begin(), ord.end(), [&](int x, int y) -> bool {return X[x] < X[y];});
		for (auto id : ord) {
			SEG :: Insert(1, 1, n, id, dead[id] ? dead[id] : n, mp(X[id], Y[id]));
		}
		SEG :: Build(1, 1, n);
	}
	{ // GetAns
		ord.clear();
		for (int i = 1; i <= n; i++) {
			if (OP[i] == 3) ord.push_back(i);
		}
		sort(ord.begin(), ord.end(), [&](int x, int y) -> bool {return X[x] < X[y];});
		for (auto id : ord) {
			ans[id] = SEG :: Query(1, 1, n, id, X[id]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (OP[i] == 3) {
			if (ans[i] == -INF) printf("EMPTY SET\n");
			else printf("%lld\n", ans[i]);
		}
	}
	return 0;
}