#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define LB(a, x) (lower_bound((a).begin(), (a).end(), (x)))
using namespace std;

typedef pair <int, int> pii;

const int mod = 1000000007;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void MUL(int &x, int y) {
	x = 1ll * x * y % mod;
}

char s[500010];
int hei[500010];
vector <int> son[500010];
vector <int> pos[2][500010];
vector <int> sum[500010];
vector <int> inv[500010];
vector <int> pre[500010];
int ql[500010], qr[500010];
int val[500010], Type[500010], B[500010], L[500010], R[500010];
int ans[500010];
long long pw[500010];
vector <pii> all, qry;
set <pii> S;
int TOT;

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		b >>= 1, a = a * a % mod;
	}
	return ans;
}

void Calc(int now) {
	if (Type[now] == 0) {
		int S = 0; sum[now].push_back(S);
		for (auto x : son[now]) ADD(S, val[x]), sum[now].push_back(S);
		val[now] = S;
	} else if (Type[now] == 1) {
		int r = 1, f = 1, zero = 0; sum[now].push_back(f), inv[now].push_back(power(f, mod - 2)), pre[now].push_back(zero);
		for (auto x : son[now]) {
			MUL(r, val[x]);
			if (val[x]) MUL(f, val[x]);
			else zero++;
			sum[now].push_back(f);
			inv[now].push_back(power(f, mod - 2));
			pre[now].push_back(zero);
		}
		val[now] = r;
	} else if (Type[now] == 2) {
		int S = 0; sum[now].push_back(S);
		for (int i = L[now]; i <= R[now]; i++) {
			S = (S * 10ll + (int)(s[i] - '0')) % mod;
			sum[now].push_back(S);
		}
		val[now] = S;
	}
}

int Solve(int l, int r) {
	int H = hei[l - 1];
	auto it = LB(pos[0][H], l);
	if (it != pos[0][H].end() && *it <= r) {
		int lst = l, now = ++TOT; Type[TOT] = 0;
		L[now] = l, R[now] = r;
		while (it != pos[0][H].end() && *it <= r) {
			son[now].push_back(Solve(lst, *it - 1));
			lst = *it + 1, it = LB(pos[0][H], *it + 1);
		}
		son[now].push_back(Solve(lst, r));
		Calc(now);
		return now;
	}
	it = LB(pos[1][H], l);
	if (it != pos[1][H].end() && *it <= r) {
		int lst = l, now = ++TOT; Type[TOT] = 1;
		L[now] = l, R[now] = r;
		while (it != pos[1][H].end() && *it <= r) {
			son[now].push_back(Solve(lst, *it - 1));
			lst = *it + 1, it = LB(pos[1][H], *it + 1);
		}
		son[now].push_back(Solve(lst, r));
		Calc(now);
		return now;
	}
	if (s[l] == '(') {
		assert(s[r] == ')');
		int now = Solve(l + 1, r - 1);
		B[now]++, L[now]--, R[now]++;
		return now;
	}
	int now = ++TOT; Type[TOT] = 2;
	L[now] = l, R[now] = r;
	Calc(now);
	return now;
}

int GetSon(int now, int x) {
	int l = 0, r = son[now].size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (R[son[now][mid]] < x) l = mid + 1;
		else r = mid;
	}
	if (x < L[son[now][l]] || x > R[son[now][l]]) return -1;
	return l;
}

int Merge(int x, int y, int Type) {
	if (x == -1 || y == -1) return -1;
	if (Type == 0) return (x + y) % mod;
	return 1ll * x * y % mod;
}

int GetSum(int now, int l, int r) {
	if (Type[now] == 0) return (sum[now][r] - sum[now][l] + mod) % mod;
	if (pre[now][r] != pre[now][l]) return 0;
	return 1ll * sum[now][r] * inv[now][l] % mod;
}

int Query(int now, int ql, int qr) {
	int l = L[now], r = R[now];
	if (ql < l) ql = l;
	if (qr > r) qr = r;
	int lh = max(0, B[now] - (ql - l)), rh = max(0, B[now] - (r - qr));
	if (lh != rh) return -1;
	ql += lh, qr -= rh;
	if (ql == l + B[now] && qr == r - B[now]) return val[now];
	if (Type[now] == 2) {
		int Base = l + B[now];
		return (sum[now][qr - Base + 1] - 1ll * sum[now][ql - Base] * pw[qr - ql + 1] % mod + mod) % mod;
	}
	int lp = GetSon(now, ql), rp = GetSon(now, qr);
	if (lp == -1 || rp == -1) return -1;
	if (lp == rp) return Query(son[now][lp], ql, qr);
	int ans = Merge(Query(son[now][lp], ql, qr), Query(son[now][rp], ql, qr), Type[now]);
	lp++;
	ans = Merge(ans, GetSum(now, lp, rp), Type[now]);
	return ans;
}

int main() {
//	freopen("calc.in", "r", stdin);
//	freopen("calc.out", "w", stdout);
	pw[0] = 1; for (int i = 1; i <= 500005; i++) pw[i] = pw[i - 1] * 10 % mod;
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int q; scanf("%d", &q);
	for (int i = 1; i <= n; i++) hei[i] = hei[i - 1] + (s[i] == '(' ? 1 : s[i] == ')' ? -1 : 0);
	for (int i = 1; i <= n; i++) {
		if (s[i] == '+') pos[0][hei[i]].push_back(i);
		else if (s[i] == '*') pos[1][hei[i]].push_back(i);
	}
	Solve(1, n);
	for (int i = 0; i < q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		ql[i] = l, qr[i] = r;
		qry.push_back(mp(l, i));
	}
	for (int i = 1; i <= TOT; i++) all.push_back(mp(L[i], i));
	sort(all.begin(), all.end()), sort(qry.begin(), qry.end());
	int pos = 0;
	for (auto it : qry) {
		int l = it.fi, id = it.se, r = qr[id];
		while (pos < all.size() && all[pos].fi <= l) S.insert(mp(R[all[pos].se], -all[pos].se)), pos++;
		auto jt = S.lower_bound(mp(r, -0x3f3f3f3f));
		ans[id] = Query(-jt->se, l, r);
	}
	for (int i = 0; i < q; i++) printf("%d\n", ans[i]);
	return 0;
}