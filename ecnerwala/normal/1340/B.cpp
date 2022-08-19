#include<bits/stdc++.h>
using namespace std;

const string DIGS[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N, K; cin >> N >> K;
	vector<string> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<vector<bool>> poss(N+1, vector<bool>(K+1));
	poss[N][K] = true;

	vector<vector<int>> diffs(N, vector<int>(10));
	for (int i = 0; i < N; i++) {
		for (int d = 0; d < 10; d++) {
			int diff = 0;
			bool good = true;
			for (int v = 0; v < 7; v++) {
				if (DIGS[d][v] < A[i][v]) {
					good = false;
				} else if (DIGS[d][v] > A[i][v]) {
					diff++;
				}
			}
			diffs[i][d] = (good ? diff : -1);
		}
	}

	for (int i = N-1; i >= 0; i--) {
		for (int d = 0; d < 10; d++) {
			int diff = diffs[i][d];
			if (diff == -1) continue;
			for (int a = 0; a+diff <= K; a++) {
				if (poss[i+1][a+diff]) poss[i][a] = true;
			}
		}
	}

	if (!poss[0][0]) {
		cout << -1 << '\n';
		exit(0);
	}

	string ans;
	int cur = 0;
	for (int i = 0; i < N; i++) {
		assert(poss[i][cur]);
		for (int d = 9; true; d--) {
			assert(d >= 0);
			int diff = diffs[i][d];
			if (diff == -1) continue;
			if (cur+diff <= K && poss[i+1][cur+diff]) {
				ans += char('0'+d);
				cur += diff;
				break;
			}
		}
	}
	cout << ans << '\n';

	return 0;
}