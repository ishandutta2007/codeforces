#include <bits/stdc++.h>
using namespace std;

char mp[50][50];
int f[50][50][50][50];
int vis[50][50][50][50];
int sum[50][50][50][2];

int dfs(int a, int b, int c, int d){
	if (vis[a][b][c][d]) return f[a][b][c][d];
	vis[a][b][c][d] = 1;
	if (a == b){
		int cnt = 0, res = 0;
		for (int i = c; i <= d; i++){
			if (mp[a][i] == '0') cnt++;
			else res += cnt * (cnt + 1) / 2, cnt = 0;
		}
		res += cnt * (cnt + 1) / 2;
		return f[a][b][c][d] = res;
	}
	int mid = (a + b) >> 1;
	int res = dfs(a, mid, c, d) + dfs(mid + 1, b, c, d);
	for (int i = c; i <= d; i++){
		for (int j = i; j <= d; j++){
			res += min(mid - a + 1, sum[mid][i][j][0]) * min(b - mid, sum[mid + 1][i][j][1]);
		}
	}
	return f[a][b][c][d] = res;
}

int check(int a, int b, int c){
	for (int i = b; i <= c; i++){
		if (mp[a][i] == '1') return 0;
	}
	return 1;
}

int main(){
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++){
		scanf("%s", mp[i] + 1);
	}
	for (int mid = 1; mid <= n; mid++){
		for (int a = 1; a <= m; a++){
			for (int b = 1; b <= m; b++){
				int l = mid;
				while (l >= 1 && check(l, a, b)) l--;
				l++, sum[mid][a][b][0] = mid - l + 1;
				int r = mid;
				while (r <= n && check(r, a, b)) r++;
				r--, sum[mid][a][b][1] = r - mid + 1;
			}
		}
	}
	while (q--){
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", dfs(a, c, b, d));
	}
	return 0;
}