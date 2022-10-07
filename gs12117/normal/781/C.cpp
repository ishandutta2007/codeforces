#include<cstdio>
#include<vector>
int n, m, p;
int edge[200100][2];
std::vector<int> el[200100];
int ans[400100];
int ansn;
int chk[200100];
void dfs(int x) {
	chk[x] = 1;
	ans[ansn] = x;
	ansn++;
	for (int i : el[x]) {
		if (chk[i] == 0) {
			dfs(i);
			ans[ansn] = x;
			ansn++;
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &edge[i][0], &edge[i][1]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
	}
	dfs(1);
	int t = 0;
	for (int i = 0; i < p; i++) {
		int lim = t + (2 * n + p - 1) / p;
		if (lim > ansn)lim = ansn;
		if (ansn == t)t--;
		printf("%d ", lim - t);
		for(int j = t; j < lim; j++) {
			printf("%d ", ans[j]);
		}
		printf("\n");
		t = lim;
	}
	return 0;
}