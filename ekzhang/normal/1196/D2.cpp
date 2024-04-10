#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int Q, N, K;
string S;
int pre[MAXN][3];
const string alpha = "RGB";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> Q;
	while (Q--) {
		cin >> N >> K >> S;
		for (int i = 1; i <= N; i++) {
			int v = (alpha.find(S[i - 1]) + N - i) % 3;
			pre[i][0] = pre[i][1] = pre[i][2] = 0;
			pre[i][v]++;
		}
		for (int i = 1; i <= N; i++) {
			pre[i][0] += pre[i - 1][0];
			pre[i][1] += pre[i - 1][1];
			pre[i][2] += pre[i - 1][2];
		}

		int ans = 0;
		for (int i = 0; i + K <= N; i++) {
			for (int c = 0; c < 3; c++)
				ans = max(ans, pre[i + K][c] - pre[i][c]);
		}

		cout << K - ans << '\n';
	}

	cout.flush();
	return 0;
}