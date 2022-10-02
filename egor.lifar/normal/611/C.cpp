#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>


using namespace std;


int n, m;
string s[501];
int d[501][501];
int d1[501][501][4];
int dp[501][501];
int dp1[501][501][4];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int getsum(int i, int j, int i1, int j1) {
	return dp[i1][j1] - (i > 0 ? dp[i - 1][j1]:0) - (j > 0 ? dp[i1][j - 1]:0) + (i > 0 && j > 0 ? dp[i - 1][j - 1]: 0);
}


int getsum1(int i, int j, int i1, int j1, int k) {
	return dp1[i1][j1][k] - (i > 0 ? dp1[i - 1][j1][k]:0) - (j > 0 ? dp1[i1][j - 1][k]:0) + (i > 0 && j > 0 ? dp1[i - 1][j - 1][k]: 0);
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int i1 = i + dx[k];
				int j1 = j + dy[k];
				if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
					continue;
				}
				if (s[i][j] == '.' && s[i1][j1] == '.') {
					d[i][j]++;
					d1[i][j][k]++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[i][j] = d[i][j] + (i > 0 ? dp[i - 1][j]:0) + (j > 0 ? dp[i][j - 1]:0) - (i > 0 && j > 0 ? dp[i - 1][j - 1]:0);
			for (int k = 0; k < 4; k++) {
				dp1[i][j][k] = d1[i][j][k] + (i > 0 ? dp1[i - 1][j][k]:0) + (j > 0 ? dp1[i][j - 1][k]:0) - (i > 0 && j > 0 ? dp1[i - 1][j - 1][k]:0);
			}
		}
	}	
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--;
		c1--;
		r2--;
		c2--;
		int ans = getsum(r1, c1, r2, c2);
		if (c2 < m - 1) {
			ans -= getsum1(r1, c2 + 1, r2, c2 + 1, 1);
		}
		if (c1 > 0) {
			ans -= getsum1(r1, c1 - 1, r2, c1 - 1, 0);
		}
		if (r2 < n - 1) {
			ans -= getsum1(r2 + 1, c1, r2 + 1, c2, 3);
		}
		if (r1 > 0) {
			ans -= getsum1(r1 - 1, c1, r1 - 1, c2, 2);
		}
		ans /= 2;
		printf("%d\n", ans);
	}
	return 0;
}