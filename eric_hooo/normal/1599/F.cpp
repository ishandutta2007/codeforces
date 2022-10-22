#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i != (r); i++)
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int mod = 1000000007, B = 3;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

int n, q;
map <int, int> lst;
vector <int> qry[200010];
int L[200010], R[200010], D[200010];
int ans[200010];
int a[200010];

int Calc(int s, int n, int d, int k) {
	if (k == 0) return n;
	if (k == 1) return (1ll * s * n + 1ll * n * (n - 1) / 2 % mod * d) % mod;
	if (k == 2) return (1ll * n * s % mod * s + n * (n - 1ll) % mod * s % mod * d + (n - 1ll) * n * (n * 2 - 1) / 6 % mod * d % mod * d) % mod;
	return 2333;
}

struct BIT {
	int T[200010];
	void modify(int x, int v) {
		while (x <= 200005) ADD(T[x], v), x += x & -x;
	}
	int query(int x) {
		int res = 0;
		while (x) ADD(res, T[x]), x -= x & -x;
		return res;
	}
	int query(int l, int r) {return (query(r) - query(l - 1) + mod) % mod;}
}S[B];

void Modify(int x, int coef) {
	int val = (mod + coef) % mod;
	rep(i, 0, B) S[i].modify(x, val), val = 1ll * val * a[x] % mod;
}

int main() {
	scanf("%d%d", &n, &q);
	rep(i, 1, n + 1) scanf("%d", &a[i]);
	rep(i, 0, q) scanf("%d%d%d", &L[i], &R[i], &D[i]), qry[R[i]].push_back(i), ans[i] = 1;
	rep(i, 1, n + 1) {
		int x = a[i];
		if (lst.count(x)) Modify(lst[x], -1);
		lst[x] = i;
		Modify(i, 1);
		for (auto id : qry[i]) {
			int l = L[id], r = R[id], n = S[0].query(l, r), d = D[id];
			int s = (S[1].query(l, r) - 1ll * n * (n - 1) / 2 % mod * d % mod + mod) * power(n, mod - 2) % mod;
			rep(it, 0, B) if (S[it].query(l, r) != Calc(s, n, d, it)) ans[id] = 0;
		}
	}
	rep(i, 0, q) printf(ans[i] ? "Yes\n" : "No\n");
	return 0;
}