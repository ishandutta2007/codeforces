#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

template <typename T>
void chmin(T &x, T y) {x = min(x, y);}

const long long INF = 0x3f3f3f3f3f3f3f3f;

typedef pair <int, int> pii;

pii operator + (const pii &A, const pii &B) {return mp(A.fi + B.fi, A.se + B.se);}

int Dist(pii x, pii y) {return abs(x.fi - y.fi) + abs(x.se - y.se);}

int n;
pii a[100010][2];
int mem[100010][2][2];

namespace SEG {
	struct Data {
		int l, r;
		long long a[2][2];
		void init(int x) {
			l = r = x;
			a[0][0] = a[1][1] = 0, a[0][1] = a[1][0] = Dist(:: a[x][0], :: a[x][1]);
		}
	}T[1 << 18];
	Data operator + (const Data &A, const Data &B) {
		Data res; res.l = A.l, res.r = B.r, memset(res.a, 0x3f, sizeof(res.a));
		for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++) for (int r = 0; r < 2; r++) for (int s = 0; s < 2; s++) {
			chmin(res.a[p][s], A.a[p][q] + mem[A.r][q][r] + B.a[r][s]);
		}
		return res;
	}
	void pushup(int now) {
		T[now] = T[now << 1] + T[now << 1 | 1];
	}
	void Build(int now, int l, int r) {
		if (l == r) {
			T[now].init(l);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	Data Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return Query(now << 1, l, mid, L, mid) + Query(now << 1 | 1, mid + 1, r, mid + 1, R);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d%d", &a[i][0].fi, &a[i][0].se, &a[i][1].fi, &a[i][1].se);
	}
	for (int i = 1; i + 1 < n; i++) {
		for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++) {
			mem[i][p][q] = Dist(a[i][p] + mp(!p, p), a[i + 1][q]) + 1;
		}
	}
	SEG :: Build(1, 1, n - 1);
	int m; scanf("%d", &m);
	while (m--) {
		pii S, T; scanf("%d%d%d%d", &S.fi, &S.se, &T.fi, &T.se);
		int s = max(S.fi, S.se), t = max(T.fi, T.se);
		if (s > t) swap(s, t), swap(S, T);
		if (s == t) printf("%d\n", Dist(S, T));
		else {
			auto tmp = SEG :: Query(1, 1, n - 1, s, t - 1);
			long long ans = INF;
			for (int p = 0; p < 2; p++) for (int q = 0; q < 2; q++) {
				ans = min(ans, Dist(S, a[s][p]) + tmp.a[p][q] + Dist(a[t - 1][q] + mp(!q, q), T));
			}
			printf("%lld\n", ans + 1);
		}
	}
	return 0;
}