#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int son[50][26], can[50], TOT = 1;
int N;

struct Matrix {
	int a[210][210];
	Matrix() {}
	Matrix operator * (const Matrix &A) const {
		Matrix res;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				long long tmp = 0;
				for (int k = 0; k < N; k++) {
					tmp += 1ll * a[i][k] * A.a[k][j];
					if (!(k & 7)) tmp %= mod;
				}
				res.a[i][j] = tmp % mod;
			}
		}
		return res;
	}
}A, ans;

void dfs(int x, int y, int d, int id) {
	if (d == 0) {
		if (can[x]) A.a[id][y * 5]++;
		if (can[y]) A.a[id][x * 5]++;
		if (can[x] && can[y]) A.a[id][0]++;
		return ;
	}
	for (int i = 0; i < 26; i++) {
		if (son[x][i] != -1 && son[y][i] != -1) dfs(son[x][i], son[y][i], d - 1, id);
	}
}

int main() {
	memset(son, -1, sizeof(son));
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int now = 0;
		for (auto x : s) now = ~son[now][x - 'a'] ? son[now][x - 'a'] : son[now][x - 'a'] = TOT++;
		can[now] = 1;
	}
	N = TOT * 5;
	for (int i = 0; i < TOT; i++) {
		for (int j = 0; j < 5; j++) {
			if (j < 4) A.a[i * 5 + j][i * 5 + j + 1]++;
			dfs(0, i, j + 1, i * 5 + j);
		}
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ans.a[i][j] = i == j;
	for (int it = 0; it < 30; it++) {
		if (m >> it & 1) ans = ans * A;
		A = A * A;
	}
	printf("%d\n", ans.a[0][0]);
	return 0;
}