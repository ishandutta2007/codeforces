#include <bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;

int c[5010], d[5010];
vector <int> from[5010];
int ans = 0;
long long dp0[5010][5010], dp1[5010][5010];
int size[5010];

void dfs(int x){
	dp0[x][0] = 0, dp1[x][1] = c[x] - d[x], dp0[x][1] = c[x];
	size[x] = 1;
	for (int i = 0; i < from[x].size(); i++){
		int v = from[x][i];
		dfs(v); 
		for (int k = size[x]; k >= 0; k--){
			for (int j = 0; j <= size[v]; j++){
				dp1[x][k + j] = min(dp1[x][k + j], dp1[x][k] + dp1[v][j]);
				dp1[x][k + j] = min(dp1[x][k + j], dp1[x][k] + dp0[v][j]);
				dp0[x][k + j] = min(dp0[x][k + j], dp0[x][k] + dp0[v][j]);
			}
		}
		size[x] += size[v];
	}
}

int main(){
	int n, b;
	scanf("%d%d", &n, &b);
	for (int i = 1; i <= n; i++){
		scanf("%d%d", &c[i], &d[i]);
		if (i != 1){
			int x; scanf("%d", &x);
			from[x].push_back(i);
		}
	}
	memset(dp0, 0x3f, sizeof(dp0));
	memset(dp1, 0x3f, sizeof(dp1));
	dfs(1);
	int i = 0;
	while (min(dp0[1][i], dp1[1][i]) <= b) i++;
	printf("%d\n", i - 1);
	return 0;
}