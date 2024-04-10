#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

namespace SAM {
	int son[400010][27], len[400010], fa[400010], lst, TOT, DFN;
	int dfn[400010], sz[400010];
	vector <int> G[400010];
	void Init() {TOT = 0, lst = ++TOT;}
	int Append(int x) {
		int p = lst, np = ++TOT; lst = np, len[np] = len[p] + 1;
		while (p && !son[p][x]) son[p][x] = np, p = fa[p];
		if (p) {
			int q = son[p][x];
			if (len[q] == len[p] + 1) fa[np] = q;
			else {
				int nq = ++TOT; memcpy(son[nq], son[q], sizeof(son[q])), len[nq] = len[p] + 1;
				fa[nq] = fa[q], fa[q] = fa[np] = nq;
				while (p && son[p][x] == q) son[p][x] = nq, p = fa[p];
			}
		} else fa[np] = 1;
		return lst;
	}
	void GetDfn(int x) {
		dfn[x] = ++TOT, sz[x] = 1;
		for (auto v : G[x]) {
			GetDfn(v), sz[x] += sz[v];
		}
	}
	void PreCalc() {
		for (int i = 2; i <= TOT; i++) {
			G[fa[i]].push_back(i);
		}
		GetDfn(1);
	}
}

int n, q;
int nd[100010], N;
int len[100010], beg[100010];
char s[100010];
pii rng[100010];
int L[100010], R[100010], K[100010];
long long ans[100010];

const int Magic = 316;

namespace BigSolver {
	vector <int> qry[100010];
	void Append(int id) {
		qry[K[id]].push_back(id);
	}
	void Solve() {
		for (int i = 0; i < n; i++) {
			if (!qry[i].size()) continue;
			static int sum[100010]; for (int j = 0; j <= N; j++) sum[j] = 0;
			; for (int j = 0; j < len[i]; j++) sum[nd[beg[i] + j] + 1]++;
			; for (int j = 0; j < N; j++) sum[j + 1] += sum[j];
			static long long sss[100010]; for (int j = 0; j <= n; j++) sss[j] = 0;
			; for (int j = 0; j < n; j++) sss[j + 1] = sss[j] + sum[rng[j].se + 1] - sum[rng[j].fi];
			; for (auto id : qry[i]) ans[id] = sss[R[id] + 1] - sss[L[id]];
		}
	}
}

namespace SmallSolver {
	vector <int> qry;
	void Append(int id) {
		qry.push_back(~id);
		qry.push_back(id);
	}
	int Rnk(int x) {return x < 0 ? L[~x] - 1 : R[x];}
	namespace DS {
		int T[100010], S[400];
		void Clear() {memset(T, 0, sizeof(T)), memset(S, 0, sizeof(S));}
		void Modify(int l, int r, int v) {
			// cerr << "    Modify:" << l << " " << r << " " << v << endl;
			r++;
			while (l < r && (l & 255)) T[l++] += v;
			while (l < r && (r & 255)) T[--r] += v;
			l >>= 8, r >>= 8;
			while (l < r) S[l++] += v;
		}
		int Query(int x) {
			// cerr << "       x:" << x << endl;
			return T[x] + S[x >> 8];
		}
	}
	void Solve() {
		sort(qry.begin(), qry.end(), [&](int x, int y) -> bool {return Rnk(x) < Rnk(y);});
		auto it = qry.begin();
		DS :: Clear();
		for (int i = 0; i < n; i++) {
			DS :: Modify(rng[i].fi, rng[i].se, 1);
			while (it != qry.end() && Rnk(*it) < i) it++;
			while (it != qry.end() && Rnk(*it) == i) {
				int id = *it < 0 ? ~*it : *it, coef = *it < 0 ? -1 : 1;
				for (int j = 0; j < len[K[id]]; j++) {
					ans[id] += DS :: Query(nd[beg[K[id]] + j]) * coef;
				}
				it++;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &q);
	SAM :: Init(), N = 0;
	for (int i = 0; i < n; i++) {
		static char buf[100010]; scanf("%s", buf);
		len[i] = strlen(buf), beg[i] = N;
		for (int j = 0; j < len[i]; j++) {
			s[N] = buf[j];
			nd[N++] = SAM :: Append(buf[j] - 'a');
		}
		SAM :: Append(26);
	}
	SAM :: PreCalc();
	// cerr << "   nd:"; for (int i = 0; i < N; i++) cerr << " " << nd[i]; cerr << endl;
	{
		static vector <int> all; for (int i = 0; i < N; i++) all.push_back(SAM :: dfn[nd[i]]);
		sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
		assert(all.size() == N);
		; for (int i = 0; i < N; i++) nd[i] = lower_bound(all.begin(), all.end(), SAM :: dfn[nd[i]]) - all.begin();
		for (int i = 0; i < n; i++) {
			int now = 1;
			for (int j = 0; j < len[i]; j++) {
				now = SAM :: son[now][s[beg[i] + j] - 'a'];
			}
			int l = SAM :: dfn[now], r = SAM :: dfn[now] + SAM :: sz[now] - 1;
			rng[i].fi = lower_bound(all.begin(), all.end(), l) - all.begin();
			rng[i].se = lower_bound(all.begin(), all.end(), r + 1) - all.begin() - 1;
		}
	}
	for (int i = 0; i < q; i++) {
		scanf("%d%d%d", &L[i], &R[i], &K[i]), L[i]--, R[i]--, K[i]--;
		if (len[K[i]] >= Magic) BigSolver :: Append(i);
		else SmallSolver :: Append(i);
	}
	BigSolver :: Solve();
	SmallSolver :: Solve();
	for (int i = 0; i < q; i++) {
		printf("%lld\n", ans[i]);
	}
	return 0;
}