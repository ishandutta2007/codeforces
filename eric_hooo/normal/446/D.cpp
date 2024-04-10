#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[510], id[510];
double G[510][510];
int deg[510];
vector <int> P;
int N;
double onelife[110][110];

void Inv(double a[510][1010]) {
	for (int i = 0; i < n; i++) {
		int p = -1;
		for (int j = i; j < n; j++) {
			if (p == -1 || fabs(a[j][i]) > fabs(a[p][i])) p = j;
		}
		assert(p != -1);
		for (int j = 0; j < n + n; j++) {
			swap(a[i][j], a[p][j]);
		}
		double mul = 1 / a[i][i];
		for (int j = 0; j < n + n; j++) {
			a[i][j] *= mul;
		}
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			double mul = a[j][i];
			for (int k = 0; k < n + n; k++) {
				a[j][k] = a[j][k] - a[i][k] * mul;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = a[i][n + j];
		}
	}
}

void Mul(double a[110][110], double b[110][110], double c[110][110]) {
	double tmp[110][110];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) {
		tmp[i][k] += a[i][j] * b[j][k];
	}
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		c[i][j] = tmp[i][j], tmp[i][j] = 0;
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i]) id[i] = P.size(), P.push_back(i);
	}
	N = P.size();
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y), x--, y--;
		G[x][y]++, G[y][x]++, deg[x]++, deg[y]++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] /= deg[i];
		}
	}
	static double qwq[510][1010];
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				qwq[i][j] = !a[i] ? G[i][j] : 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				qwq[i][j] = (i == j) - qwq[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			qwq[i][n + i] = 1;
		}
		Inv(qwq);
		for (auto x : P) {
			for (int i = 0; i < n; i++) {
				for (auto y : P) {
					onelife[id[x]][id[y]] += G[x][i] * qwq[i][y];
				}
			}
		}
	}
	static double ans[110][110];
	for (int i = 0; i < N; i++) {
		ans[i][i] = 1;
	}
	k -= 2;
	for (int it = 0; it < 30; it++) {
		if (k >> it & 1) Mul(ans, onelife, ans);
		Mul(onelife, onelife, onelife);
	}
	double output = 0;
	for (int i = 0; i < N; i++) {
		output += qwq[0][P[i]] * ans[i][N - 1];
	}
	cout << fixed << setprecision(10) << output << endl;
	return 0;
}