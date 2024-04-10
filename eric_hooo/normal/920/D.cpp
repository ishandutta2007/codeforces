#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> pip;

int n, k, V;
int a[5010];
int lst[5010][5010];
int f[5010], g[5010];
int spc[5010];
vector <pip> op;

void DoOp(int c, int x, int y) {
	assert(1 <= c && c <= 1000000000 && 1 <= x && x <= n && 1 <= y && y <= n);
	int tmp = min(1ll * c * k, (long long)a[x]);
	a[x] -= tmp, a[y] += tmp;
	op.push_back(mp(c, mp(x, y)));
}

void Main() {
	scanf("%d%d%d", &n, &k, &V);
	int sum = 0;
	for (int j = 0; j < k; j++) {
		f[j] = j == 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		int x = a[i] % k;
		for (int j = 0; j < k; j++) {
			if (f[j]) g[j] = 1, lst[i][j] = 0;
			else if (f[(j - x + k) % k]) g[j] = 1, lst[i][j] = 1;
			else g[j] = 0;
		}
		for (int j = 0; j < k; j++) {
			f[j] = g[j];
		}
	}
	if (V > sum) {
		printf("NO\n");
		return ;
	}
	if (!f[V % k]) {
		printf("NO\n");
		return ;
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		spc[i] = 0;
	}
	int x = n, y = V % k;
	while (x) {
		if (lst[x][y]) y = (y - a[x] % k + k) % k, spc[x] = 1;
		x--;
	}
	int X = -1, Y = -1;
	op.clear();
	for (int i = 1; i <= n; i++) {
		if (spc[i]) {
			if (X == -1) X = i;
			else DoOp(1000000000, i, X);
		} else {
			if (Y == -1) Y = i;
			else DoOp(1000000000, i, Y);
		}
	}
	if (X == -1) assert(Y == 1), X = 2;
	if (Y == -1) assert(X == 1), Y = 2;
	if (a[X] < V) DoOp((V - a[X]) / k, Y, X);
	if (a[X] > V) DoOp((a[X] - V) / k, X, Y);
	assert(a[X] == V);
	for (int i = 0; i < op.size(); i++) {
		printf("%d %d %d\n", op[i].fi, op[i].se.fi, op[i].se.se);
	}
}

int main() {
	int T = 1;
	while (T--) Main();
	return 0;
}