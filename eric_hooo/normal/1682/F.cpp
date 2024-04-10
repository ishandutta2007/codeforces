#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 1000000007;

int Flush(long long x) {return (x % mod + mod) % mod;}

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

int n, q;
int a[200010], b[200010];
long long S[200010];
pii dw[200010], up[200010];
vector <long long> all;

struct BIT {
	int T[200010];
	BIT() {memset(T, 0, sizeof(T));}
	void modify(int x, int v) {
		ADD(T[0], v);
		while (x <= 200005) ADD(T[x], v), x += x & -x;
	}
	int query(int x) {
		int res = 0;
		while (x) ADD(res, T[x]), x -= x & -x;
		return res;
	}
	int tot() const {return T[0];}
}bit0, bit1;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		S[i] = S[i - 1] + b[i];
	}
	for (int i = 0; i <= n; i++) {
		all.push_back(S[i]);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 0; i <= n; i++) {
		int x = lower_bound(all.begin(), all.end(), S[i]) - all.begin() + 1;
		dw[i].fi = bit0.query(x), dw[i].se = bit1.query(x);
		SUB(up[i].fi = bit0.tot(), dw[i].fi), SUB(up[i].se = bit1.tot(), dw[i].se);
		if (i >= 1 && i < n) {
			int v = a[i + 1]; SUB(v, a[i]);
			bit0.modify(x, v), bit1.modify(x, 1ll * v * Flush(S[i]) % mod);
		}
	}
	for (int i = 1; i <= q; i++) {
		int l, r; scanf("%d%d", &l, &r), l--;
		int ans = 0;
		ADD(ans, 1ll * dw[r].fi * Flush(S[r]) % mod), SUB(ans, dw[r].se);
		SUB(ans, 1ll * up[r].fi * Flush(S[r]) % mod), ADD(ans, up[r].se);
		SUB(ans, 1ll * dw[l].fi * Flush(S[l]) % mod), ADD(ans, dw[l].se);
		ADD(ans, 1ll * up[l].fi * Flush(S[l]) % mod), SUB(ans, up[l].se);
		printf("%d\n", ans);
	}
	return 0;
}