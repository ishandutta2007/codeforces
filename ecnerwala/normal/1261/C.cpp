#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, M; cin >> N >> M;
	vector<string> G(N);
	for (int i = 0; i < N; i++) {
		cin >> G[i];
	}
	vector<vector<int>> maxSquare(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (G[i][j] == '.') maxSquare[i][j] = 0;
			else if (i == 0 || j == 0) {
				maxSquare[i][j] = 1;
			} else {
				maxSquare[i][j] = 1 + min(maxSquare[i-1][j-1], min(maxSquare[i-1][j], maxSquare[i][j-1]));
			}
		}
	}
	vector<vector<int>> coverDist(N, vector<int>(M));
	int mi = 0;
	int ma = int(2e6);
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		int s = 2 * md + 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (maxSquare[i][j] >= s) {
					coverDist[i][j] = s;
				} else {
					coverDist[i][j] = 0;
				}
			}
		}
		for (int i = N-1; i >= 0; i--) {
			for (int j = M-1; j >= 0; j--) {
				if (i > 0) {
					coverDist[i-1][j] = max(coverDist[i-1][j], coverDist[i][j] - 1);
				}
				if (j > 0) {
					coverDist[i][j-1] = max(coverDist[i][j-1], coverDist[i][j] - 1);
				}
				if (i > 0 && j > 0) {
					coverDist[i-1][j-1] = max(coverDist[i-1][j-1], coverDist[i][j] - 1);
				}
			}
		}
		bool isGood = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (G[i][j] == '.') continue;
				if (coverDist[i][j] == 0) isGood = false;
			}
		}
		if (isGood) {
			mi = md;
		} else {
			ma = md;
		}
	}

	cout << mi << '\n';
	int s = 2 * mi + 1;
	vector<string> ans(N, string(M, '.'));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maxSquare[i][j] >= s) {
				ans[i - mi][j - mi] = 'X';
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}