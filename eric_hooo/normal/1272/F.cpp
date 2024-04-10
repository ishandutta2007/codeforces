#include <bits/stdc++.h>
using namespace std;

const int lim = 405;

int dp[210][210][410];
char s[210], t[210];
int n, m;

int dfs(int x, int y, int k) {
	if (k > lim) return 0x3f3f3f3f;
	if (x == n && y == m && k == 0) return 0;
	if (~dp[x][y][k]) return dp[x][y][k];
	int &res = dp[x][y][k] = 0x3f3f3f3f;
	if (k) res = min(res, dfs(x + (s[x] == ')'), y + (t[y] == ')'), k - 1) + 1);
	res = min(res, dfs(x + (s[x] == '('), y + (t[y] == '('), k + 1) + 1);
	return res;
}

void rec(int x, int y, int k) {
	if (x == n && y == m && k == 0) return ;
	int res = dfs(x, y, k);
	if (k && dfs(x + (s[x] == ')'), y + (t[y] == ')'), k - 1) + 1 == res) {
		printf(")"), rec(x + (s[x] == ')'), y + (t[y] == ')'), k - 1);
		return ;
	}
	if (dfs(x + (s[x] == '('), y + (t[y] == '('), k + 1) + 1 == res) {
		printf("("), rec(x + (s[x] == '('), y + (t[y] == '('), k + 1);
		return ;
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%s%s", s, t), n = strlen(s), m = strlen(t);
	rec(0, 0, 0), printf("\n");
	return 0;
}