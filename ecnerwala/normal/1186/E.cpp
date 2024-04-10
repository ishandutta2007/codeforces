#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e3;
const int MAXM = 1.1e3;
int N, M;
char C[MAXN][MAXM];

ll pref[2][MAXN][MAXM];

int Q;

int bit_parity(ll a) {
	return __builtin_popcountll(a) % 2;
}

int bit_parity(ll a, ll b) {
	return bit_parity(a) ^ bit_parity(b);
}

ll slowSum(ll xhi, ll yhi) {
	ll ans = 0;
	for (ll x = 0; x < xhi; x++) {
		for (ll y = 0; y < yhi; y++) {
			ans += (C[x % N][y % M] - '0') ^ bit_parity(x / N, y / M);
		}
	}
	return ans;
}
// exclusive
ll sumPrefix(ll xhi, ll yhi) {
	ll ans = 0;
	ans += pref[bit_parity(xhi / N, yhi / M)][xhi % N][yhi % M];

	ans += (xhi / N / 2) * (pref[0][N][yhi % M] + pref[1][N][yhi % M]);
	if (xhi / N % 2 == 1) {
		// we have to add the extra one
		ans += pref[bit_parity(xhi / N - 1, yhi / M)][N][yhi % M];
	}

	ans += (yhi / M / 2) * (pref[0][xhi % N][M] + pref[1][xhi % N][M]);
	if (yhi / M % 2 == 1) {
		ans += pref[bit_parity(xhi / N, yhi / M - 1)][xhi % N][M];
	}

	ans += (xhi / N) * (yhi / M) / 2 * (pref[0][N][M] + pref[1][N][M]);
	if (xhi / N % 2 == 1 && yhi / M % 2 == 1) {
		ans += pref[bit_parity(xhi / N - 1, yhi / M - 1)][N][M];
	}

	//cerr << xhi << ' ' << yhi << ' ' << ans << ' '  << slowSum(xhi, yhi) << '\n';
	//assert(ans == slowSum(xhi, yhi));

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			pref[0][i][j] = pref[0][i-1][j] + pref[0][i][j-1] - pref[0][i-1][j-1] + (C[i-1][j-1] - '0');
			pref[1][i][j] = pref[1][i-1][j] + pref[1][i][j-1] - pref[1][i-1][j-1] + (1-(C[i-1][j-1] - '0'));
		}
	}

	for (int q = 0; q < Q; q++) {
		ll xlo, ylo, xhi, yhi; cin >> xlo >> ylo >> xhi >> yhi;
		xlo --, ylo --; // half-open
		cout << sumPrefix(xhi, yhi) - sumPrefix(xhi, ylo) - sumPrefix(xlo, yhi) + sumPrefix(xlo, ylo) << '\n';
	}

	return 0;
}