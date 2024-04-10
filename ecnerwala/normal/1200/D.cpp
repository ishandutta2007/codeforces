#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e3;
int N;
int K;

char G[MAXN][MAXN];
int sum[MAXN][MAXN];

int query(int x1, int x2, int y1, int y2) {
	return sum[x1][y1] + sum[x2][y2] - sum[x1][y2] - sum[x2][y1];
}

int rowVal[MAXN][MAXN];
int colVal[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> G[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + (G[i][j] == 'B');
		}
	}

	int startGood = 0;
	for (int i = 0; i < N; i++) {
		int all = query(i, i+1, 0, N);
		startGood += (all == 0);
		for (int j = 0; j+K <= N; j++) {
			int mid = query(i, i+1, j, j+K);
			rowVal[i][j] = (all > 0) && (all == mid);
		}
	}
	for (int j = 0; j < N; j++) {
		int all = query(0, N, j, j+1);
		startGood += (all == 0);
		for (int i = 0; i+K <= N; i++) {
			int mid = query(i, i+K, j, j+1);
			colVal[i][j] = (all > 0) && (all == mid);
		}
	}

	for (int i = 0; i+K <= N; i++) {
		int s = 0;
		for (int j = 0; j < K; j++) {
			s += colVal[i][j];
		}
		for (int j = 0; j <= N-K; j++) {
			int oldS = s;
			s += colVal[i][j+K];
			s -= colVal[i][j];
			colVal[i][j] = oldS;
		}
	}

	for (int j = 0; j+K <= N; j++) {
		int s = 0;
		for (int i = 0; i < K; i++) {
			s += rowVal[i][j];
		}
		for (int i = 0; i <= N-K; i++) {
			int oldS = s;
			s += rowVal[i+K][j];
			s -= rowVal[i][j];
			rowVal[i][j] = oldS;
		}
	}

	int ans = 0;
	for (int i = 0; i+K <= N; i++) {
		for (int j = 0; j+K <= N; j++) {
			ans = max(ans, startGood + rowVal[i][j] + colVal[i][j]);
		}
	}
	cout << ans << '\n';

	return 0;
}