#include <bits/stdc++.h>
using namespace std;

int op[100010];
int x[100010], y[100010], l[100010], d[100010];
int id[100010];
int tmp[100010];

int get_val(int id) {
	if (op[id] == 1) return l[id] + x[id] + y[id];
	return x[id] + y[id];
}

int T[5010][5010];
int ans[100010];
int n;

void modify(int x, int y, int val) {
	for (int nx = x; nx <= n; nx += nx & -nx) {
		for (int ny = y; ny <= n; ny += ny & -ny) {
			T[nx][ny] += val;
		}
	}
}

int query(int x, int y) {
	int res = 0;
	for (int nx = x; nx; nx -= nx & -nx) {
		for (int ny = y; ny; ny -= ny & -ny) {
			res += T[nx][ny];
		}
	}
	return res;
}

void solve(int l, int r, int dd) {
	if (l == r) return ;
	int mid = l + r >> 1;
	solve(l, mid, dd), solve(mid + 1, r, dd);
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r) {
		if (get_val(id[i]) >= get_val(id[j])) {
			tmp[k++] = id[i];
			if (d[id[i]] == dd && op[id[i]] == 1) modify(x[id[i]], y[id[i]], 1);
			i++;
		} else {
			tmp[k++] = id[j];
			if (op[id[j]] == 2) ans[id[j]] += query(x[id[j]], y[id[j]]);
			j++;
		}
	}
	while (j <= r) {
		tmp[k++] = id[j];
		if (op[id[j]] == 2) ans[id[j]] += query(x[id[j]], y[id[j]]);
		j++;
	}
	for (int o = l; o < i; o++) {
		if (d[id[o]] == dd && op[id[o]] == 1) modify(x[id[o]], y[id[o]], -1);
	}
	while (i <= mid) tmp[k++] = id[i], i++;
	for (int i = l; i <= r; i++) {
		id[i] = tmp[i];
	}
}

int main () {
	int m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &op[i]);
		if (op[i] == 1) scanf("%d%d%d%d", &d[i], &x[i], &y[i], &l[i]);
		else scanf("%d%d", &x[i], &y[i]);
	}
	for (int i = 1; i <= 4; i++) {
		for (int j = 0; j < m; j++) {
			id[j] = j;
			if (i == 2) y[j] = n - y[j] + 1;
			if (i == 3) x[j] = n - x[j] + 1, y[j] = n - y[j] + 1;
			if (i == 4) y[j] = n - y[j] + 1;
		}
		solve(0, m - 1, i);
	}
	for (int i = 0; i < m; i++) {
		if (op[i] == 2) printf("%d\n", ans[i]);
	}
	return 0;
}