#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pll;

pll operator + (const pll &A, const pll &B) {
	return mp(A.fi + B.fi, A.se + B.se);
}

pll operator - (const pll &A, const pll &B) {
	return mp(A.fi - B.fi, A.se - B.se);
}

pll operator * (const pll &A, const int &x) {
	return mp(A.fi, A.se + x);
}

pll operator - (const pll &A) {
	return mp(-A.fi, -A.se);
}

const long long INF = 0x3f3f3f3f3f3f3f3f;

int n;
int N;
long long k;
int a[100010];
long long S[100010];
vector <long long> all;
long long ans, tot;
long long bd[100010]; // < bd[i]
vector <int> spc[100010];
vector <int> pos[100010];
int alive[100010];
pll dp[100010];

int GetId(long long x) {return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;}

struct BIT {
	long long T[100010];
	void modify(int x, long long v) {
		while (x <= 100005) T[x] += v, x += x & -x;
	}
	long long query(int x) {
		long long res = 0;
		while (x) res += T[x], x -= x & -x;
		return res;
	}
	void clear() {memset(T, 0, sizeof(T));}
}bit, sum;

struct MIN_BIT {
	int T[100010];
	void clear() {memset(T, 0x3f, sizeof(T));}
	void modify(int x, int v) {
		while (x <= 100005) T[x] = min(T[x], v), x += x & -x;
	}
	int query(int x) {
		int res = 0x3f3f3f3f;
		while (x) res = min(res, T[x]), x -= x & -x;
		return res;
	}
}minj;

bool Check(long long lim) {
	tot = 0, ans = 0;
	bit.clear(), sum.clear(), minj.clear();
	memset(alive, 0, sizeof(alive));
	for (int i = 0; i <= n; i++) {
		int tmp = GetId(S[i] - lim + 1) - 1;
		int pos = minj.query(tmp);
		if (pos != 0x3f3f3f3f) alive[i]++, alive[pos]--;
		tot += bit.query(tmp);
		ans += bit.query(tmp) * S[i] - sum.query(tmp);
		tmp = GetId(S[i]);
		bit.modify(tmp, 1), sum.modify(tmp, S[i]);
	}
	return tot + n <= k;
}

struct Semgent_tree {
	pll T[400010];
	pll tag[400010];
	void addtag(int now, pll x) {
		tag[now] = tag[now] + x, T[now] = T[now] + x;
	}
	void pushdown(int now) {
		if (tag[now] == pll(0, 0)) return ;
		addtag(now << 1, tag[now]), addtag(now << 1 | 1, tag[now]);
		tag[now] = pll(0, 0);
	}
	void pushup(int now) {
		T[now] = max(T[now << 1], T[now << 1 | 1]);
	}
	void Build(int now, int l, int r) {
		tag[now] = mp(0, 0);
		if (l == r) {
			T[now] = mp(-S[l], 0);
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, pll x) {
		if (l == L && r == R) {
			addtag(now, x);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, x);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, x);
		else Update(now << 1, l, mid, L, mid, x), Update(now << 1 | 1, mid + 1, r, mid + 1, R, x);
		pushup(now);
	}
	pll Query(int now, int l, int r, int L, int R) {
		if (l == L && r == R) return T[now];
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

vector <int> seq; // premin
vector <int> st;

struct Node {
	int sum;
	long long sss;
	Node *lson, *rson;
	void pushup() {
		sum = lson->sum + rson->sum, sss = lson->sss + rson->sss;
	}
}POOL[2000000], *CUR = POOL;

Node *rt[100010];

Node *Build(int l, int r) {
	Node *T = CUR++; T->lson = T->rson = NULL, T->sum = 0;
	if (l == r) return T;
	int mid = l + r >> 1;
	T->lson = Build(l, mid), T->rson = Build(mid + 1, r);
	T->pushup();
	return T;
}

Node *Update(Node *T, int l, int r, int p) {
	Node *nT = CUR++; nT->lson = T->lson, nT->rson = T->rson, nT->sum = T->sum, nT->sss = T->sss;
	if (l == r) {
		nT->sum++, nT->sss += S[p];
		return nT;
	}
	int mid = l + r >> 1;
	if (p <= mid) nT->lson = Update(nT->lson, l, mid, p);
	else nT->rson = Update(nT->rson, mid + 1, r, p);
	nT->pushup();
	return nT;
}

int LLL;

int GetLef(Node *R, int l, int r) {
	if (0 == R->sum) return 0x3f3f3f3f;
	if (l == r) return l;
	int mid = l + r >> 1;
	int tmp = GetLef(R->lson, l, mid);
	return tmp == 0x3f3f3f3f ? GetLef(R->rson, mid + 1, r) : tmp;
}

pll GetSum(Node *T, int l, int r, int L, int R) {
	if (l == L && r == R) return mp(T->sss, T->sum);
	int mid = l + r >> 1;
	if (R <= mid) return GetSum(T->lson, l, mid, L, R);
	if (L > mid) return GetSum(T->rson, mid + 1, r, L, R);
	return GetSum(T->lson, l, mid, L, mid) + GetSum(T->rson, mid + 1, r, mid + 1, R);
}

pll Query(long long l, long long r, int R) { // (l, r]
	r = GetId(r + 1) - 1, l = GetId(l + 1) - 1;
	// cerr << "             l:" << l << " " << r << endl;
	LLL = GetLef(rt[r], 0, n);
	return GetSum(rt[r], 0, n, 0, R);
}

int old[100010];
pll mem[100010];
int Mem[100010];

pll Solve(long long coef) {
	pll ans = mp(0, 0);
	memcpy(old, alive, sizeof(old));
	for (int i = 1; i <= n; i++) {
		pll tmp = Query(S[i] - bd[i], S[i] + coef, i - 1);
		mem[i] = tmp, Mem[i] = LLL;
		if (LLL < i) alive[LLL]--, alive[i]++;
		tmp.fi = (S[i] + coef) * tmp.se - tmp.fi;
		ans = ans + tmp;
	}
	for (int i = n; i >= 1; i--) {
		alive[i - 1] += alive[i];
	}
	dp[0] = ans;
	seq.clear(), st.clear();
	seg.Build(1, 0, n);
	seg.Update(1, 0, n, 0, 0, ans);
	st.push_back(-1);
	seq.push_back(0), st.push_back(0);
	for (int i = 1; i <= n; i++) {
		dp[i] = !alive[i] ? pll(-INF, -1) : dp[i - 1];
		pll tmp = mem[i]; LLL = Mem[i];
		tmp.fi = (S[i] + coef) * tmp.se - tmp.fi;
		int pos = lower_bound(seq.begin(), seq.end(), S[i] - bd[i], [&](const int &x, const long long &y) -> bool {
			return S[x] > y && x < LLL;
		}) - seq.begin();
		if (pos) dp[i] = max(dp[i], seg.Query(1, 0, n, 0, seq[pos - 1]) + mp(S[i] + coef, 1));
		if (S[i] <= S[seq.back()]) seq.push_back(i);
		while (st.size() > 1 && dp[st.back()] < dp[i]) {
			int p = st.back(); st.pop_back();
			seg.Update(1, 0, n, st.back() + 1, p, -dp[p]);
		}
		seg.Update(1, 0, n, st.back() + 1, i, dp[i]), st.push_back(i);
	}
	memcpy(alive, old, sizeof(old));
	dp[n] = dp[n];
	return dp[n];
}

int main() {
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		S[i] = S[i - 1] + a[i];
	}
	for (int i = 0; i <= n; i++) {
		all.push_back(S[i]);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	N = all.size();
	long long l = -5000000001, r = 5000000001;
	// while (l < r) {
	// 	l += 1000000000000000, r += 1000000000000000;
	// 	long long mid = l + r >> 1;
	// 	l -= 1000000000000000, r -= 1000000000000000, mid -= 1000000000000000;
	// 	if (Check(mid)) r = mid;
	// 	else l = mid + 1;
	// }
	// Check(l), l--;
	for (int i = 0; i <= n; i++) {
		// if (tot + n < k) {
		// 	int id = GetId(S[i] - l), has = 0;
		// 	if (id - 1 < all.size() && all[id - 1] == S[i] - l) {
		// 		has = pos[id].size();
		// 	}
		// 	long long need = k - tot - n;
		// 	if (has <= need) {
		// 		bd[i] = l, tot += pos[id].size(), ans += l * (int)pos[id].size();
		// 		if (pos[id].size()) alive[pos[id][0]]--, alive[i]++;
		// 	} else {
		// 		bd[i] = l, tot += need, ans += need * l;
		// 		if (pos[id].size()) alive[pos[id][0]]--, alive[i]++;
		// 		for (int i = need; i < pos[id].size(); i++) {
		// 			spc[i].push_back(pos[id][i]);
		// 		}
		// 	}
		// } else {
		// 	bd[i] = l + 1;
		// }
		pos[GetId(S[i])].push_back(i);
	}
	for (int i = 0; i <= n; i++) {
		bd[i] = 10000000000000;
	}
	// cerr << "           tot:" << tot << " " << ans << endl;
	rt[0] = Build(0, n);
	for (int i = 1; i <= N; i++) {
		rt[i] = rt[i - 1];
		for (auto x : pos[i]) {
			rt[i] = Update(rt[i], 0, n, x);
		}
	}
	// Solve(2500000000);
	// cerr << "      dp:" << dp[n].se << " " << dp[n].fi - dp[n].se * 2500000000 << endl;
	// return 0;
	l = -5000000000, r = 5000000000;
	while (l < r) {
		l += 1000000000000000, r += 1000000000000000;
		long long mid = l + r >> 1;
		l -= 1000000000000000, r -= 1000000000000000, mid -= 1000000000000000;
		if (Solve(mid).se < k) l = mid + 1;
		else r = mid;
	}
	Solve(l);
	ans += dp[n].fi - l * k;
	printf("%lld\n", ans);
	return 0;
}