#include<cstdio>
#include<vector>
int n, m;
std::vector<int> el[500100];
std::vector<int> sl[500100];
int a[500100];
int chk[500100];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		el[x].push_back(y);
		el[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < el[i].size(); j++) {
			chk[a[el[i][j]]]++;
		}
		int p;
		for (p = 1; chk[p] != 0; p++);
		for (int j = 0; j < el[i].size(); j++) {
			chk[a[el[i][j]]]--;
		}
		if (p != a[i]) {
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		sl[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < sl[i].size(); j++) {
			printf("%d ", sl[i][j]);
		}
	}
	return 0;
}