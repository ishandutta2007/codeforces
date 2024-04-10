#include <bits/stdc++.h>
using namespace std;

int n, m; long long k;

long long a[30][30];
int M;
int dir[2][2] = {0, 1, 1, 0};
map <long long, int> all[30];
long long ans;

void dfs(int x, int y, int coef, long long sum) {
	if (x + y == M) {
		if (coef == 1) all[x][sum]++;
		else ans += all[x][sum ^ a[x][y] ^ k];
		return ;
	}
	sum ^= a[x][y];
	for (int i = 0; i < 2; i++) {
		int xx = x + dir[i][0] * coef, yy = y + dir[i][1] * coef;
		if (xx >= 0 && yy >= 0 && xx < n && yy < m) dfs(xx, yy, coef, sum);
	}
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	M = n + m - 2 >> 1;
	dfs(0, 0, 1, 0);
	dfs(n - 1, m - 1, -1, 0);
	cout << ans << endl;
	return 0;
}