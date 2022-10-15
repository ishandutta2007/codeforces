#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 703
int N;
int A[MAXN];
bool adj[MAXN][MAXN];
bool dp[MAXN][MAXN][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (__gcd(A[i], A[j]) > 1)
				adj[i][j] = true;

	for (int i = 0; i <= N; i++) {
		dp[i+1][i][0] = dp[i+1][i][1] = true;
	}

	for (int len = 1; len < N; len++) {
		for (int i = 1; i + len - 1 <= N; i++) {
			int j = i + len - 1;
			for (int k = i; k <= j; k++) {
				bool b = dp[i][k-1][1] && dp[k+1][j][0];
				dp[i][j][0] |= b && adj[k][i-1];
				dp[i][j][1] |= b && adj[k][j+1];
			}
		}
	}

	bool ans = false;
	for (int m = 1; m <= N; m++) {
		if (dp[1][m-1][1] && dp[m+1][N][0])
			ans = true;
	}

	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}