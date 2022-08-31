#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3000;

void setmin(int& a, int b) {
	if (b < a) a = b;
}

int N;
int seg[MAXN]; // furthest rightwards segment starting at <= L
int A[MAXN];

int K;
int S, M;

// maximum number of values we can pick <= maxVal
int dp[MAXN][MAXN];
int go(int maxVal) {
	// we'll actually compute minimum number of values we have to skip

	// initialize with skip all
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = i;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			setmin(dp[i+1][j], dp[i][j] + (A[i] <= maxVal));
		}
		if (seg[i] > i) {
			for (int j = 0; j < M; j++) {
				setmin(dp[seg[i]][j+1], dp[i][j]);
			}
		}
	}

	int tot = 0;
	for (int i = 0; i < N; i++) {
		tot += (A[i] <= maxVal);
	}
	int res = tot - dp[N][M];
	return res;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cerr.tie(0);
	cin >> N >> S >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < S; i++) {
		int l, r; cin >> l >> r;
		l--;
		seg[l] = max(seg[l], r);
	}
	for (int l = 0; l < N; l++) {
		seg[l+1] = max(seg[l+1], seg[l]);
	}

	const int INF = int(1e9) + 10;
	if (go(INF) < K) {
		cout << -1 << '\n';
		return 0;
	}
	int mi = -1, ma = INF;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (go(md) >= K) {
			// this is a possible order statistic
			ma = md;
		} else {
			mi = md;
		}
	}
	cout << ma << '\n';

	return 0;
}