#include<cstdio>
#include<vector>
using namespace std;
int n, s, m;
int edge[52][3];
vector<int> el[52];
vector<int> ew[52];
int dchk[52];
int dcn[52];
int prt[52];
int dp[52][2][52][52];
int chk[52][2][52][52];
void dfs(int x) {
	dchk[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		if (dchk[el[x][i]] == 0) {
			prt[el[x][i]] = x;
			dfs(el[x][i]);
			dcn[x] += dcn[el[x][i]];
		}
	}
}
int calcdp(int x, int side, int cn, int pn) {
	if (chk[x][side][cn][pn] == 1) {
		return dp[x][side][cn][pn];
	}
	if (cn == 0)return 0;
	if (pn == 0)return 1e9;
	chk[x][side][cn][pn] = 1;
	int res = (1 << 19) - 10;
	if (side == 1) {//down
		for (int i = 18; i >= 0; i--) {
			res -= 1 << i;
			int cnt = 0;
			for (int j = 0; j < el[x].size(); j++) {
				if (el[x][j] == prt[x])continue;
				int s = 1;
				while (cnt < pn&&s <= pn) {
					if (calcdp(el[x][j], 1, cn, s) + ew[x][j] <= res)break;
					cnt++;
					s++;
				}
			}
			if (cnt >= pn)res += 1 << i;
		}
		if (res < -1) {//leaf
			res = calcdp(x, side ^ 1, cn - pn, cn - pn);
		}
	}
	else {//up
		int dx = prt[x];
		for (int i = 18; i >= 0; i--) {
			res -= 1 << i;
			int cnt = 0;
			for (int j = 0; j < el[dx].size(); j++) {
				if (el[dx][j] == x)continue;
				if (el[dx][j] == prt[dx]) {
					int s = 1;
					while (cnt < pn&&s <= pn) {
						if (calcdp(dx, 0, cn, s) <= res)break;
						cnt++;
						s++;
					}
				}
				else {
					int s = 1;
					while (cnt < pn&&s <= pn) {
						if (calcdp(el[dx][j], 1, cn, s) + ew[dx][j] <= res)break;
						cnt++;
						s++;
					}
				}
			}
			if (cnt >= pn)res += 1 << i;
		}
		if (res < -1) {//leaf
			res = calcdp(dx, side ^ 1, cn - pn, cn - pn);
		}
		for (int j = 0; j < el[x].size(); j++) {
			if (el[x][j] == dx)res += ew[x][j];
		}
	}
	return dp[x][side][cn][pn] = res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d%d", &edge[i][0], &edge[i][1], &edge[i][2]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
		ew[edge[i][0]].push_back(edge[i][2]);
		ew[edge[i][1]].push_back(edge[i][2]);
	}
	scanf("%d", &s);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		dcn[t]++;
	}
	dfs(1);
	int ans = 1e9;
	for (int i = 0; i < el[s].size(); i++) {
		if (el[s][i] == prt[s]) {
			if (calcdp(s, 0, m, m - dcn[s]) < ans)ans = calcdp(s, 0, m, m - dcn[s]);
		}
		else {
			if (calcdp(el[s][i], 1, m, dcn[el[s][i]]) + ew[s][i] < ans)ans = calcdp(el[s][i], 1, m, dcn[el[s][i]]) + ew[s][i];
		}
	}
	printf("%d", ans);
	return 0;
}