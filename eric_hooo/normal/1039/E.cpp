#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

const int INF = 0x3f3f3f3f;
const int B = 600;

int MN, MX;

bool chmax(int &x, int y) {
	return x < y ? x = y, 1 : 0;
}

bool chmin(int &x, int y) {
	return x > y ? x = y, 1 : 0;
}

namespace SEG {
	int mx[1 << 18], mn[1 << 18];
	void pushup(int now) {
		mx[now] = max(mx[now << 1], mx[now << 1 | 1]);
		mn[now] = min(mn[now << 1], mn[now << 1 | 1]);
	}
	void Build(int now, int l, int r, int *a) {
		if (l == r) {
			mx[now] = mn[now] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid, a), Build(now << 1 | 1, mid + 1, r, a);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R, int &mx, int &mn, int lim) {
		if (l == L && r == R && max(mx, SEG :: mx[now]) - min(mn, SEG :: mn[now]) <= lim) {
			chmax(mx, SEG :: mx[now]), chmin(mn, SEG :: mn[now]);
			return r;
		}
		if (l == r) return l - 1;
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R, mx, mn, lim);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R, mx, mn, lim);
		int tmp = Query(now << 1, l, mid, L, mid, mx, mn, lim);
		return tmp == mid ? Query(now << 1 | 1, mid + 1, r, mid + 1, R, mx, mn, lim) : tmp;
	}
}

int n, q, w;
int a[100010];
int K[100010];
vector <int> qry[100010];
int ans[100010];

void Solve(int l, int r) {
	static vector <pip> edge;
	static vector <pii> qry;
	static int wei[B][B];
	edge.clear();
	int S = r - l;
	for (int i = 0; i <= S; i++) for (int j = i; j <= S; j++) {
		wei[i][j] = abs(a[l + i] - a[l + j]);
	}
	for (int i = S; i >= 0; i--) for (int j = i; j <= S; j++) {
		if (i < S) chmax(wei[i][j], wei[i + 1][j]);
		if (j > 0) chmax(wei[i][j], wei[i][j - 1]);
	}
	for (int i = 0; i <= S; i++) {
		for (int j = i; j <= S; j++) {
			int nj = j; while (nj <= S && wei[i][j] == wei[i][nj]) nj++;
			edge.push_back(mp(wei[i][j], mp(i, nj)));
			j = nj - 1;
		}
	}
	sort(edge.begin(), edge.end());
	qry.clear();
	for (int i = l; i <= r; i++) {
		for (auto id : :: qry[i]) {
			qry.push_back(mp(id, i));
		}
		vector <int>().swap(:: qry[i]);
	}
	sort(qry.begin(), qry.end(), [&](pii x, pii y) -> bool {return K[x.fi] < K[y.fi];});
	auto it = edge.begin();
	static int f[B], g[B], step[B];
	memset(g, -1, sizeof(g));
	auto Flush = [&]() -> void {
		for (int i = S; i >= 0; i--) {
			if (g[i] > S) f[i] = i, step[i] = 0;
			else f[i] = f[g[i]], step[i] = step[g[i]] + 1;
		}
	};
	// cerr << "       edge:" << edge.size() << endl;
	// while (it != edge.end()) {
	// 	chmax(g[it->se.fi], it->se.se);
	// 	if (it->se.se > 0) Flush();
	// 	it++;
	// }
	// for (int i = 1; i <= q; i++) {
	// 	SEG :: Query(1, 1, n, l, n, MX = -INF, MN = INF, K[i]);
	// }
	for (auto jt : qry) {
		int id = jt.fi, pos = jt.se;
		int NeedFlush = 0;
		while (it != edge.end() && it->fi <= K[id]) NeedFlush |= chmax(g[it->se.fi], it->se.se), it++;
		if (NeedFlush) Flush();
		ans[id] += step[pos - l] + 1;
		pos = SEG :: Query(1, 1, n, f[pos - l] + l, n, MX = -INF, MN = INF, K[id]);
		:: qry[pos + 1].push_back(id);
	}
}

int main() {
	scanf("%d%d%d", &n, &w, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	SEG :: Build(1, 1, n, a);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &K[i]), K[i] = w - K[i];
		qry[1].push_back(i);
	}
	for (int l = 1; l <= n; ) {
		int r = min(n, l / B * B + B - 1);
		Solve(l, r);
		l = r + 1;
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", ans[i] - 1);
	}
	return 0;
}