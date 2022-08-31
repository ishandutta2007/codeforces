#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e6;
const int MAXM = 1.1e6;
int N, M;
int dp[20][20];
int ndp[20][20];
int cnt[MAXM];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		cnt[a]++;
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= M; i++) {
		for (int a = 0; a <= 2; a++) {
			for (int b = a; b <= a+2; b++) {
				ndp[a][b] = -1;
			}
		}
		for (int a = 0; a <= 2; a++) {
			for (int b = a; b <= a+2; b++) {
				if (dp[a][b] == -1) continue;
				for (int c = b; c <= b+2 && c <= cnt[i]; c++) {
					ndp[b-a][c-a] = max(ndp[b-a][c-a], a + dp[a][b] + (cnt[i] - c) / 3);
				}
			}
		}
		for (int a = 0; a <= 2; a++) {
			for (int b = a; b <= a+2; b++) {
				dp[a][b] = ndp[a][b];
			}
		}
		/*
		for (int a = 0; a <= 2; a++) {
			for (int b = a; b <= a+2; b++) {
				if (dp[a][b] == -1) continue;
				cerr << i << ' ' << a << ' ' << b << ' ' << dp[a][b] << '\n';
			}
		}*/
	}
	cout << dp[0][0] << '\n';

	return 0;
}