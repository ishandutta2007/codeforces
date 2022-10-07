#include<cstdio>
#include<cstdlib>
#include<vector>
int n, m;
int edge[200100][2];
std::vector<int> el[100100];
int chk[100100];
int dep[100100];
int ans[100100];
int highest[100100];
int secondhighest[100100];
int sflag;
int random_node() {
	return (rand() * 12117LL + rand()) % n + 1;
}
void fdfs(int x) {
	chk[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] != 0) {
			if (chk[y] == 2)sflag = 1;
			continue;
		}
		else {
			fdfs(y);
		}
	}
	chk[x] = 2;
}
void sdfs(int x, int cdep) {
	chk[x] = 1;
	dep[x] = cdep;
	highest[x] = x;
	secondhighest[x] = x;
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] != 0) {
			if (dep[highest[x]] > dep[y]) {
				secondhighest[x] = highest[x];
				highest[x] = y;
			}
			else if (dep[secondhighest[x]] > dep[y]) {
				secondhighest[x] = y;
			}
			continue;
		}
		else {
			sdfs(y, cdep + 1);
			if (dep[highest[x]] > dep[highest[y]]) {
				secondhighest[x] = highest[x];
				highest[x] = highest[y];
			}
			else if (dep[secondhighest[x]] > dep[highest[y]]) {
				secondhighest[x] = highest[y];
			}
			if (dep[highest[x]] > dep[secondhighest[y]]) {
				secondhighest[x] = highest[x];
				highest[x] = secondhighest[y];
			}
			else if (dep[secondhighest[x]] > dep[secondhighest[y]]) {
				secondhighest[x] = secondhighest[y];
			}
		}
	}
}
void tdfs(int x) {
	chk[x] = 1;
	if (highest[x] != x && secondhighest[x] == x && ans[highest[x]] != 0) {
		ans[x] = 1;
	}
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] != 0) {
			continue;
		}
		else {
			tdfs(y);
		}
	}
}
int solve(int root) {
	for (int i = 0; i <= n; i++) {
		chk[i] = 0;
	}
	sflag = 0;
	fdfs(root);
	if (sflag)return 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i] != 2)return 0;
		chk[i] = 0;
		ans[i] = 0;
	}
	sdfs(root, 0);
	for (int i = 1; i <= n; i++) {
		chk[i] = 0;
	}
	ans[root] = 1;
	tdfs(root);
	return 1;
}
int main() {
	int tcn;
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &edge[i][0], &edge[i][1]);
			el[edge[i][0]].push_back(edge[i][1]);
		}
		int res = 0;
		for (int i = 0; i < 100; i++) {
			int x = random_node();
			res = solve(x);
			if (res == 1)break;
		}
		if (res == 0) {
			printf("-1\n");
		}
		else {
			int anscnt = 0;
			for (int i = 1; i <= n; i++) {
				if (ans[i])anscnt++;
			}
			if (anscnt * 5 < n) {
				printf("-1\n");
			}
			else {
				for (int i = 1; i <= n; i++) {
					if (ans[i])printf("%d ", i);
				}
				printf("\n");
			}
		}
		for (int i = 1; i <= n; i++) {
			el[i].clear();
		}
	}
}