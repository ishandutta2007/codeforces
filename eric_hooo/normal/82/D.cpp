#include <bits/stdc++.h>
using namespace std;

int a[1010], dp[1010][1010];
int n;

int dfs(int i, int j){
	if (i == n) return a[j];
	if (i == n - 1) return max(a[j], a[n - 1]);
	if (~dp[i][j]) return dp[i][j];
	int res = 0x3f3f3f3f;
	res = min(res, dfs(i + 2, j) + max(a[i], a[i + 1]));
	res = min(res, dfs(i + 2, i) + max(a[j], a[i + 1]));
	res = min(res, dfs(i + 2, i + 1) + max(a[j], a[i]));
	return dp[i][j] = res;
}

void rec(int i, int j){
	if (i == n){
		printf("%d\n", j + 1);
		return ;
	}
	if (i == n - 1){
		printf("%d %d\n", j + 1, n);
		return ;
	}
	if (dfs(i, j) == dfs(i + 2, j) + max(a[i], a[i + 1])){
		printf("%d %d\n", i + 1, i + 2);
		rec(i + 2, j);
	} else if (dfs(i, j) == dfs(i + 2, i) + max(a[j], a[i + 1])){
		printf("%d %d\n", j + 1, i + 2);
		rec(i + 2, i);
	} else {
		printf("%d %d\n", j + 1, i + 1);
		rec(i + 2, i + 1);
	}
}

int main(){
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d\n", dfs(1, 0));
	rec(1, 0);
	return 0;
}