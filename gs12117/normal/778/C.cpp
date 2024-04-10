#include<stdio.h>
#include<vector>
using namespace std;
int n;
const int m = 26;
int edge[300100][3];
int out[300100][26];
int dep[300100];
int ans[300100];
char ctmp[20];
void dfs(int x) {
	for (int i = 0; i < m; i++) {
		if (out[x][i] != 0) {
			dep[out[x][i]] = dep[x] + 1;
			dfs(out[x][i]);
		}
	}
}
int sdfs(vector<int>&va) {
	if (va.size() <= 1)return 0;
	int res = va.size() - 1;
	for (int i = 0; i < m; i++) {
		vector<int> vb;
		for (int j : va) {
			if (out[j][i])vb.push_back(out[j][i]);
		}
		res += sdfs(vb);
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int pa, pb;
		scanf("%d%d%s", &pa, &pb, ctmp);
		out[pa][ctmp[0] - 'a'] = pb;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		vector<int> va;
		for (int j = 0; j < m; j++) {
			if (out[i][j])va.push_back(out[i][j]);
		}
		if (va.size() > 0)ans[dep[i]] += sdfs(va) + 1;
	}
	int ansl = 0;
	for (int i = 0; i <= n; i++) {
		if (ans[i] > ans[ansl])ansl = i;
	}
	printf("%d\n", n - ans[ansl]);
	printf("%d\n", ansl + 1);
	return 0;
}