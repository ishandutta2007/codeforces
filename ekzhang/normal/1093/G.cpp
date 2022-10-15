#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define MAXSEG 524288
#define INF 1000000000
int N, K, Q;
struct minmax_st {
	int stmi[MAXSEG];
	int stma[MAXSEG];

	void update(int i, int x, int lo=0, int hi=-1, int node=0) {
		if (hi == -1)
			hi = N - 1;
		if (lo > i || hi < i)
			return;
		if (lo == hi) {
			stmi[node] = stma[node] = x;
			return;
		}
		int mid = (lo + hi) / 2;
		update(i, x, lo, mid, 2 * node + 1);
		update(i, x, mid + 1, hi, 2 * node + 2);
		stmi[node] = min(stmi[2 * node + 1], stmi[2 * node + 2]);
		stma[node] = max(stma[2 * node + 1], stma[2 * node + 2]);
	}

	int qma(int s, int e, int lo=0, int hi=-1, int node=0) {
		if (hi == -1) hi = N - 1;
		if (hi < s || lo > e) return -INF;
		if (lo >= s && hi <= e) return stma[node];
		int mid = (lo + hi) / 2;
		return max(qma(s, e, lo, mid, 2 * node + 1), 
				qma(s, e, mid + 1, hi, 2 * node + 2));
	}

	int qmi(int s, int e, int lo=0, int hi=-1, int node=0) {
		if (hi == -1) hi = N - 1;
		if (hi < s || lo > e) return INF;
		if (lo >= s && hi <= e) return stmi[node];
		int mid = (lo + hi) / 2;
		return min(qmi(s, e, lo, mid, 2 * node + 1), 
				qmi(s, e, mid + 1, hi, 2 * node + 2));
	}
} m[32];
int dd[32];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	const int maxmask = (1<<K);
	for (int i = 0; i < N; i++) {
		memset(dd, 0, sizeof dd);
		for (int j = 0; j < K; j++) {
			int x; cin >> x;
			for (int k = 0; k < maxmask; k++) {
				if (k & (1<<j))
					dd[k] -= x;
				else
					dd[k] += x;
			}
		}
		for (int k = 0; k < maxmask; k++)
			m[k].update(i, dd[k]);
	}

	cin >> Q;
	while (Q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i; cin >> i; --i;
			memset(dd, 0, sizeof dd);
			for (int j = 0; j < K; j++) {
				int x; cin >> x;
				for (int k = 0; k < maxmask; k++) {
					if (k & (1<<j))
						dd[k] -= x;
					else
						dd[k] += x;
				}
			}
			for (int k = 0; k < maxmask; k++) {
				m[k].update(i, dd[k]);
			}
		}
		else {
			int l, r;
			cin >> l >> r;
			--l, --r;
			int ans = 0;
			for (int k = 0; k < maxmask; k++) {
				int cur = m[k].qma(l, r) - m[k].qmi(l, r);
				ans = max(ans, cur);
			}
			cout << ans << '\n';
		}
	}

	cout.flush();
	return 0;
}