#include<cstdio>
#include<vector>
int n;
int edge[200100][2];
std::vector<int> el[200100];
int ans[200100];
int chk[200100];
void dfs(int x, int pc, int c) {
	ans[x] = c;
	chk[x] = 1;
	int p = 1;
	for (int i : el[x]) {
		if (chk[i] == 0) {
			while (p == pc || p == c)p++;
			dfs(i, c, p);
			p++;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &edge[i][0], &edge[i][1]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
	}
	dfs(1, 0, 1);
	int mans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans[i] > mans)mans = ans[i];
	}
	printf("%d\n", mans);
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}