#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

typedef pair <int, int> pii;

int fa[500010];
vector <int> all;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main () {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i <= m; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int k, x, y; scanf("%d", &k);
		if (k == 1) scanf("%d", &x), y = 0;
		else scanf("%d%d", &x, &y);
		if (find(x) != find(y)) all.push_back(i), fa[find(x)] = find(y);
	}
	long long pw = 1;
	for (int i = 0; i < all.size(); i++) {
		pw = pw * 2 % mod;
	}
	printf("%I64d %d\n", pw, (int)all.size());
	for (int i = 0; i < all.size(); i++) {
		printf("%d ", all[i] + 1);
	}
	printf("\n");
	return 0;
}