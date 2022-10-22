#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;

long long dp[maxn][maxn][maxn];
long long a[maxn], b[maxn], c[maxn], number[maxn];
long long best[maxn][maxn][maxn];
long long N, M, K;

int solve(int i, int j, int k) {
	long long many = 0;
	if (i != 1)
		if (best[i][j][k] > 0) {
			long long newt = a[j] + k;
			newt -= K;
			newt -= a[best[i][j][k]];
			solve(i - 1, best[i][j][k], newt);
			many = dp[i][j][k] - dp[i - 1][best[i][j][k]][newt];
		}
		else {
			long long newt = a[j] + k;
			newt /= K;
			newt -= a[-best[i][j][k]];
			solve(i - 1, -best[i][j][k], newt);
			many = dp[i][j][k] - dp[i - 1][-best[i][j][k]][newt];
		}
	else
		many = dp[i][j][k];
	cout << number[j] << " " << many << "\n";
	return 0;
}

int main() {

	cin >> N >> M >> K;
	for (int i = 1; i <= M; ++i)
		cin >> a[i] >> b[i] >> c[i], number[i] = i;
	
	for (int i = 1; i <= M; ++i)
		for (int j = i + 1; j <= M; ++j)
			if (c[i] > c[j])
				swap(a[i], a[j]), swap(b[i], b[j]), swap(c[i], c[j]), swap(number[i], number[j]);
	
	for (int i = 1; i <= M; ++i)
		for (int j = 0; j <= b[i] - a[i]; ++j)
			dp[1][i][j] = a[i] + j;
	

	for (int i = 2; i <= N; ++i)
		for (int j = i; j <= M; ++j)
			for (int l = 0; l <= b[j] - a[j]; ++l)
				for (int k = i - 1; k < j && c[k] < c[j]; ++k)
				 {
						long long poz = a[j] + l - K;
						if (poz >= a[k] && poz <= b[k] && dp[i - 1][k][poz - a[k]] != 0) {
							poz -= a[k];
							if (dp[i - 1][k][poz] + a[j] + l > dp[i][j][l])
								dp[i][j][l] = dp[i - 1][k][poz] + a[j] + l,
								best[i][j][l] = k;
						}
						poz = a[j] + l;
						if (poz % K)
							continue;
						poz /= K;
						if (poz >= a[k] && poz <= b[k] && dp[i - 1][k][poz - a[k]] != 0) {
							poz -= a[k];
							if (dp[i - 1][k][poz] + a[j] + l > dp[i][j][l])
								dp[i][j][l] = dp[i - 1][k][poz] + a[j] + l,
								best[i][j][l] = -k;
						}
				}
	
	int pos = 0;
	int row = 1;
	for (int i = 1; i <= M; ++i)
		for (int l = 0; l <= b[i] - a[i]; ++l)
			if (dp[N][i][l] > dp[N][row][pos])
				row = i, pos = l;
	
	if (dp[N][row][pos] == 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	solve(N, row, pos);
}