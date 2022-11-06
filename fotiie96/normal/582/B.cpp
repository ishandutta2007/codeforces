#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int n, T, m;
const int MAX_N = 100 + 10;
int a[MAX_N], ia[MAX_N];

struct Matrix {
	int a[100][100];
};

Matrix operator*(const Matrix&a, const Matrix&b) {
	Matrix ret;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			int tmp = -1;
			for (int k = 0; k < m; ++k) {
				if (a.a[i][k] != -1 && b.a[k][j] != -1)
					tmp = max(tmp, a.a[i][k] + b.a[k][j]);
			}
			ret.a[i][j] = tmp;
		}
	}
	return ret;
}

Matrix matPow(Matrix m, int pw) {
	if (pw == 1)
		return m;
	return pw % 2 == 0 ? matPow(m * m, pw >> 1) : matPow(m, pw - 1) * m;
}

int main() {
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ia[i] = a[i];
	}
	sort(ia, ia + n);
	m = unique(ia, ia + n) - ia;
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(ia, ia + m, a[i]) - ia;
	}

	Matrix stage;

	memset(stage.a, -1, sizeof stage.a);

	for (int start = 0; start < m; ++start) {
		int dp[MAX_N][MAX_N]; //at,end
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; ++i) {
			if (a[i] >= start) {
				dp[i][a[i]] = max(dp[i][a[i]], 0);
			}
			for (int j = 0; j < m; ++j) {
				if (dp[i][j] != -1) {
					//put nothing
					dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
					if (a[i] >= j)
						dp[i + 1][a[i]] = max(dp[i + 1][a[i]], dp[i][j] + 1);
				}
			}
		}

		int cur = -1;
		for (int j = 0; j < m; ++j) {
			cur = max(cur, dp[n][j]);
			stage.a[start][j] = max(stage.a[start][j], cur);
		}
	}

	Matrix ret = matPow(stage, T);
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = i; j < m; ++j) {
			ans = max(ans, ret.a[i][j]);
		}
	}

	cout << ans << endl;
}