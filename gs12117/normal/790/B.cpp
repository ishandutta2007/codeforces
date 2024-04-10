#include<cstdio>
#include<vector>
using namespace std;
int n, m;
int edge[200100][2];
vector<int> el[200100];
long long int ans;
long long int lsum[200100];
int sn[200100];
int pn[200100][5];
int chk[200100];
void dfs(int x) {
	chk[x] = 1;
	sn[x] = 1;
	pn[x][0] = 1;
	lsum[x] = 0;
	for (int d : el[x]) {
		if (chk[d] == 1)continue;
		dfs(d);
		ans += sn[x] * lsum[d];
		ans += sn[d] * lsum[x];
		ans += ((long long int)pn[x][0]) * pn[d][0];
		for (int i = 1; i < m; i++) {
			for (int j = 1; i + j < m; j++) {
				ans -= ((long long int)pn[x][i]) * pn[d][j];
			}
		}
		sn[x] += sn[d];
		lsum[x] += lsum[d] + pn[d][0];
		for (int j = 0; j < m; j++) {
			pn[x][(j + 1) % m] += pn[d][j];
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &edge[i][0], &edge[i][1]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
	}
	dfs(1);
	printf("%I64d", ans);
	return 0;
}