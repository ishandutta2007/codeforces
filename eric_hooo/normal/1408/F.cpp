#include <bits/stdc++.h>
using namespace std;

vector <int> qx, qy;

void solve(int l, int r) {
	if (l == r) return ;
	int mid = l + r >> 1;
	solve(l, mid), solve(mid + 1, r);
	for (int i = l; i <= mid; i++) {
		qx.push_back(i), qy.push_back(i - l + mid + 1);
	}
}

int main () {
	int n; scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	int tmp = 1;
	while (tmp < n) tmp <<= 1; tmp >>= 1;
	solve(1, tmp), solve(n - tmp + 1, n);
	printf("%d\n", qx.size());
	for (int i = 0; i < qx.size(); i++) {
		printf("%d %d\n", qx[i], qy[i]);
	}
	return 0;
}