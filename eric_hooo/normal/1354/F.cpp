#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

struct Node {
	int a, b, id;
	bool operator < (const Node &A) const {
		return b < A.b;
	}
}a[100];

int dp[100][100];
int last[100][100];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].a, &a[i].b);
			a[i].id = i + 1;
		}
		if (k == 1) {
			int ppp = 0;
			for (int i = 1; i < n; i++) {
				if (a[ppp].a < a[i].a) ppp = i;
			}
			printf("1\n%d\n", ppp + 1);
			continue;
		}
		sort(a, a + n);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				dp[i][j] = -2000000000;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= k; j++) {
				if (dp[i][j] == -2000000000) continue;
				// choose
				if (dp[i + 1][j + 1] < dp[i][j] + a[i].a + a[i].b * j) {
					dp[i + 1][j + 1] = dp[i][j] + a[i].a + a[i].b * j;
					last[i + 1][j + 1] = 1;
				}
				// 
				if (dp[i + 1][j] < dp[i][j] + a[i].b * (k - 1)) {
					dp[i + 1][j] = dp[i][j] + a[i].b * (k - 1);
					last[i + 1][j] = 0;
				}
			}
		}
		int x = n, y = k;
		vector <int> A, B;
		while (x) {
			if (last[x][y]) A.push_back(a[x - 1].id);
			else B.push_back(a[x - 1].id);
			y -= last[x][y], x--;
		}
		reverse(A.begin(), A.end());
		printf("%d\n", A.size() + B.size() * 2);
		for (int i = 0; i < A.size() - 1; i++) {
			printf("%d ", A[i]);
		}
		for (int i = 0; i < B.size(); i++) {
			printf("%d -%d ", B[i], B[i]);
		}
		printf("%d\n", A.back());
	}
	return 0;
}