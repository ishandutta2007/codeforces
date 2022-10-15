#include <bits/stdc++.h>
using namespace std;

#define MAXN 4000
#define MAXNUM 1000005

int N, B[MAXN];
int nmap[MAXNUM];
int nmapn = 0;
int dp[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	memset(nmap, -1, sizeof nmap);
	for (int i = 0; i < N; i++) {
		// need to conv. to ints in range [0, N - 1]
		cin >> B[i];
		if (nmap[B[i]] == -1) {
			nmap[B[i]] = nmapn++;
		}
		B[i] = nmap[B[i]];
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < nmapn; j++) {
			dp[j][B[i]] = dp[B[i]][j] + 1;
		}
	}

	for (int i = 0; i < nmapn; i++) {
		for (int j = 0; j < nmapn; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans << endl;
	return 0;
}