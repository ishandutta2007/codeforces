#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

char a[1010][1010];
int sum[1010][2];
int f[1010][1010][2];
int vis[1010][2];
int x, y;

int main(){
	int n, m;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 1; i <= n; i++){
		scanf("%s", a[i] + 1);
		for (int j = 1; j <= m; j++){
			if (a[i][j] == '#') sum[j][0]++;
			else sum[j][1]++;
		}
	}
	memset(f, INF, sizeof(f));
	f[1][1][0] = sum[1][0], f[1][1][1] = sum[1][1];
	for (int i = 2; i <= m; i++){
		for (int j = x; j <= y; j++){
			f[i][1][0] = min(f[i][1][0], f[i - 1][j][1] + sum[i][0]);
			f[i][1][1] = min(f[i][1][1], f[i - 1][j][0] + sum[i][1]);
		}
		for (int j = 2; j <= y; j++){
			f[i][j][0] = f[i - 1][j - 1][0] + sum[i][0];
			f[i][j][1] = f[i - 1][j - 1][1] + sum[i][1];
		}
	}
	int ans = INF;
	for (int i = x; i <= y; i++){
		ans = min(ans, min(f[m][i][0], f[m][i][1]));
	}
	printf("%d\n", ans);
	return 0;
}