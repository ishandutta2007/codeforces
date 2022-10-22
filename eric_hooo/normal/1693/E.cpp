#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

// namespace SEG {
// 	pii T[1 << 19];
// 	void pushup(int now) {
// 		T[now] = max(T[now << 1], T[now << 1 | 1]);
// 	}
// 	void Build(int now, int l, int r) {
// 		if (l == r) {
// 			T[now] = mp(-1, l);
// 			return ;
// 		}
// 		int mid = l + r >> 1;
// 		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
// 		pushup(now);
// 	}
// 	void Update(int now, int l, int r, int p, int x) {
// 		if (l == r) {
// 			T[now] = mp(x, l);
// 			return ;
// 		}
// 		int mid = l + r >> 1;
// 		if (p <= mid) Update(now << 1, l, mid, p, x);
// 		else Update(now << 1 | 1, mid + 1, r, p, x);
// 		pushup(now);
// 	}
// 	pii Query(int now, int l, int r, int L, int R) {
// 		if (l == L && r == R) return T[now];
// 		int mid = l + r >> 1;
// 		if (R <= mid) return Query(now << 1, l, mid, L, R);
// 		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
// 		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
// 	}
// }

int main() {
	int n; scanf("%d", &n);
	// int N = n + 1;
	// SEG :: Build(1, 0, N);
	// SEG :: Update(1, 0, N, 0, 0);
	// SEG :: Update(1, 0, N, N, 0);
	static int a[200010];
	static int f[200010];
	static vector <int> all[200010];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		// printf("(%d, %d)\n", i, a[i]);
		if (all[a[i]].size() < 2) all[a[i]].push_back(i);
		else all[a[i]].back() = i;
	}
	long long ans = 0;
	static const int Magic = 300;
	static int head[200010], nxt[200010]; memset(head, -1, sizeof(head));
	auto AddQry = [&](int x, int id) -> void {
		nxt[id] = head[x], head[x] = id;
	};
	; for (int i = 1; i <= n; i++) AddQry(a[i], i);
	auto Solve = [&](int l, int r) -> void {
		// cout << "     Solve:" << l << " " << r << endl;
		int len = r - l + 1;
		static vector <int> cut; cut.clear(), cut.push_back(1), cut.push_back(n + 1);
		; for (int i = l; i <= r; i++) {
			for (auto x : all[i]) cut.push_back(x), cut.push_back(x + 1);
			// if (a[i].size() == 1) cut.push_back(a[i][0]), cut.push_back(a[i][0] + 1);
			// else if (a[i].size() == 2) {
			// 	cut.push_back(a[i][0]), cut.push_back(a[i][0] + 1), cut.push_back(a[i][1]), cut.push_back(a[i][1] + 1);
			// }
		}
		sort(cut.begin(), cut.end()), cut.resize(unique(cut.begin(), cut.end()) - cut.begin());
		static int P[Magic + 10], Q[Magic + 10]; memset(P, 0, sizeof(P)), memset(Q, 0, sizeof(Q));
		static int mem_f[Magic * 4 + 10][Magic + 10], mem_g[Magic * 4 + 10][Magic + 10];
		static int bel[200010];
		auto Calc = [&](int *f, int *g) -> void {
			int nxt_p = -1, nxt_q = -1;
			for (int i = 0; i < len; i++) {
				// cout << "      P:" << P[i] << " " << Q[i] << endl;
				nxt_p = !i || P[i - 1] ? i - 1 : nxt_p;
				nxt_q = !i || Q[i - 1] ? i - 1 : nxt_q;
				int lst = min(nxt_p, nxt_q);
				f[i] = lst == -1 ? (nxt_p == -1) | (nxt_q == -1) << 1 : f[lst];
				g[i] = lst == -1 ? 0 : g[lst] + 1;
			}
		};
		; for (auto x : cut) if (a[x] >= l && a[x] <= r) Q[a[x] - l]++;
		for (int i = 0; i + 1 < cut.size(); i++) {
			int x = cut[i];
			; for (int j = x; j < cut[i + 1]; j++) bel[j] = i;
			if (a[x] >= l && a[x] <= r) Q[a[x] - l]--;
			Calc(mem_f[i], mem_g[i]);
			if (a[x] >= l && a[x] <= r) P[a[x] - l]++;
		}
		static int pre_maxj[200010], suc_maxj[200010];
		; for (int i = 1; i <= n; i++) pre_maxj[i] = max(pre_maxj[i - 1], a[i] < l ? a[i] : 0);
		; for (int i = n; i >= 1; i--) suc_maxj[i] = max(suc_maxj[i + 1], a[i] < l ? a[i] : 0);
		for (int i = l; i <= r; i++) {
			int id = head[i];
			while (id != -1) {
				int nxt_id = nxt[id];
				int pos = bel[id], flag = mem_f[pos][i - l];
				ans += mem_g[pos][i - l] + 1;
				AddQry(min(flag & 1 ? pre_maxj[id - 1] : 0x3f3f3f3f, flag & 2 ? suc_maxj[id + 1] : 0x3f3f3f3f), id);
				id = nxt_id;
			}
		}
	};
	for (int r = n; r >= 1; r -= Magic) {
		int l = max(1, r - Magic + 1);
		Solve(l, r);
	}
	// static multiset <int> P, Q;
	// ; for (int i = 0; i < 1; i++) P.insert(a[i]);
	// ; for (int i = 1; i <= n + 1; i++) Q.insert(a[i]);
	// for (int i = 1; i <= n; i++) {
	// 	Q.erase(Q.find(a[i]));
	// 	int cur = a[i], step = 0;
	// 	while (cur) cur = min(*--P.lower_bound(cur), *--Q.lower_bound(cur)), step++;
	// 	ans += step;
	// 	P.insert(a[i]);
	// }
	// static int dp[2010][2010];
	// for (int it = 1; it <= n; it++) {
	// 	for (int i = 1; i <= n; i++) {
	// 		int lef = 0, rig = n + 1;
	// 		for (int j = 1; j < i; j++) {
	// 			if (a[lef] < a[j] && a[j] < it) lef = j;
	// 		}
	// 		for (int j = i + 1; j <= n; j++) {
	// 			if (a[rig] < a[j] && a[j] < it) rig = j;
	// 		}
	// 		// while (a[lef] >= it) lef--;
	// 		// while (a[rig] >= it) rig++;
	// 		dp[it][i] = min(dp[a[lef]][i], dp[a[rig]][i]) + 1;
	// 	}
	// }
	// for (int i = 1; i <= n; i++) {
	// 	ans += dp[a[i]][i];
	// }
	// for (int i = 1; i <= n; i++) {
	// 	for (auto x : all[i]) {
	// 		int lef = SEG :: Query(1, 0, N, 0, x - 1).se;
	// 		int rig = SEG :: Query(1, 0, N, x + 1, N).se;
	// 		lef = rig = x;
	// 		while (a[lef] >= i) lef--;
	// 		while (a[rig] >= i) rig++;
	// 		int val_lef = f[lef], val_rig = f[rig];
	// 		{
	// 			static set <int> P, Q; P.clear(), Q.clear();
	// 			; for (int t = 0; t < x; t++) P.insert(a[t]);
	// 			; for (int t = x + 1; t <= n + 1; t++) Q.insert(a[t]);
	// 			{
	// 				int cur = i, cnt = 0;
	// 				while (cur > a[lef]) {
	// 					int p = *--P.lower_bound(cur), q = *--Q.lower_bound(cur);
	// 					cur = min(p >= a[lef] ? p : 0x3f3f3f3f, q >= a[lef] ? q : 0x3f3f3f3f);
	// 					cnt++;
	// 				}
	// 				val_lef += cnt;
	// 			}
	// 			{
	// 				int cur = i, cnt = 0;
	// 				while (cur > a[rig]) {
	// 					int p = *--P.lower_bound(cur), q = *--Q.lower_bound(cur);
	// 					cur = min(p >= a[rig] ? p : 0x3f3f3f3f, q >= a[rig] ? q : 0x3f3f3f3f);
	// 					cnt++;
	// 				}
	// 				val_rig += cnt;
	// 			}
	// 		}
	// 		// {
	// 		// 	// int maxj = a[lef], P = -1;
	// 		// 	// while (lef > 1) {
	// 		// 	// 	lef--;
	// 		// 	// 	if (a[lef] < i && a[lef] > maxj) val_lef++;
	// 		// 	// 	// if (a[lef] < i && a[lef] > maxj) maxj = a[lef], val_lef += f[lef], P = lef;
	// 		// 	// }
	// 		// 	// // if (P != -1) val_lef += f[P];
	// 		// }
	// 		// {
	// 		// 	int maxj = a[rig], P = -1;
	// 		// 	while (rig < n) {
	// 		// 		rig++;
	// 		// 		if (a[rig] < i && a[rig] > maxj) val_rig++;
	// 		// 		// if (a[rig] < i && a[rig] > maxj) maxj = a[rig], val_rig += f[rig], P = rig;
	// 		// 	}
	// 		// 	// if (P != -1) val_rig += f[P];
	// 		// }
	// 		f[x] = min(val_lef, val_rig);
	// 		cout << "                 x:" << x << " " << f[x] << " : " << val_lef << " " << val_rig << endl;
	// 		ans += f[x];
	// 	}
	// 	for (auto x : all[i]) {
	// 		SEG :: Update(1, 0, N, x, i);
	// 	}
	// }
	printf("%lld\n", ans);
	return 0;
}