#include<cstdio>
#include<vector>
int n, m;
std::vector<int> el[200100];
int dist[200100];
int chk[200100];
int da[200100];
void dfs(int x, int d) {
	chk[x] = 1;
	dist[x] = d;
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] == 1)continue;
		dfs(y, d + 1);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		el[x].push_back(y);
		el[y].push_back(x);
	}
	dfs(1, 0);
	if (m == 2) {
		printf("Yes\n");
		for (int i = 1; i <= n; i++) {
			printf("%d ", dist[i] % 2 + 1);
		}
		return 0;
	}
	int pa = 1;
	for (int i = 1; i <= n; i++) {
		if (dist[pa] < dist[i])pa = i;
		chk[i] = 0;
	}
	dfs(pa, 0);
	int pb = 1;
	for (int i = 1; i <= n; i++) {
		if (dist[pb] < dist[i])pb = i;
		chk[i] = 0;
		da[i] = dist[i];
	}
	dfs(pb, 0);
	for (int i = 1; i <= n; i++) {
		if (da[i] >= m - 1 && dist[i] >= m - 1 && da[i] + dist[i] != da[pb]) {
			printf("No\n");
			return 0;
		}
		else if (da[i] >= dist[i]) {
			dist[i] = da[pb] - da[i];
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= n; i++) {
		printf("%d ", dist[i] % m + 1);
	}
	return 0;
}