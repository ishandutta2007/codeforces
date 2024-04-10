#include <bits/stdc++.h>
using namespace std;

#define MAXN 200013
#define MOD 1000000007
#define MAXLG 31
typedef long long LL;
typedef pair<int, int> pii;

int N, K;
LL ans = 0;
priority_queue<pii, vector<pii>, greater<pii> > pq;
LL nCk[MAXN];
LL sparse[MAXLG];
bool active[MAXN];

LL inv(int n) {
	// want to compute n^(MOD - 2) % MOD
	sparse[0] = n;
	for (int i = 1; i < MAXLG; i++) {
		sparse[i] = (sparse[i - 1] * sparse[i - 1]) % MOD;
	}
	int ep = MOD - 2;
	LL ret = 1;
	for (int i = MAXLG - 1; i >= 0; i--) {
		int x = (1<<i);
		if (ep - x >= 0) {
			ret = (ret * sparse[i]) % MOD;
			ep -= x;
		}
	}
	return ret;
}

void calc_nck() {
	nCk[K] = 1;
	for (int n = K + 1; n <= N; n++) {
		nCk[n] = (((nCk[n - 1] * n) % MOD) * inv(n - K)) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int l, r;
		cin >> l >> r;
		pq.push({ l, i });
		pq.push({ r + 1, i });
	}

	calc_nck();

	int prev = pq.top().first;
	int c = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.first != prev) {
			ans += (p.first - prev) * nCk[c];
			ans %= MOD;
			prev = p.first;
		}
		active[p.second] ^= 1;
		c += active[p.second] - !active[p.second];
	}

	cout << ans << endl;
	return 0;
}