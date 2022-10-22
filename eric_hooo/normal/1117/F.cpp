#include <bits/stdc++.h>
using namespace std;

char s[100010];
int a[20][20];
int all[20], alive[20];
int can[1 << 17], vis[1 << 17];
int cnt[20];
int no[20][20][1 << 17];
queue <int> q;
int n, p;

void calc(int x, int y) {
	queue <int> q;
	for (int i = 0; i < (1 << p); i++) {
		if (no[x][y][i]) q.push(i);
	}
	while (!q.empty()) {
		int mask = q.front(); q.pop();
		for (int i = 0; i < p; i++) {
			if (mask >> i & 1) continue;
			if (no[x][y][mask | 1 << i]) continue;
			q.push(mask | 1 << i), no[x][y][mask | 1 << i] = 1;
		}
	}
}

int main() {
	scanf("%d%d", &n, &p);
	scanf("%s", s);
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		int x = s[i] - 'a';
		cnt[x]++;
		for (int j = 0; j < p; j++) {
			if (all[j] >> x & 1) continue;
			if (a[x][j] || !alive[j]) continue;
			no[min(x, j)][max(x, j)][all[j]] = 1;
		}
		for (int j = 0; j < p; j++) {
			all[j] |= 1 << x;
		}
		all[x] = 0, alive[x] = 1;
	}
	for (int i = 0; i < p; i++) {
		for (int j = i; j < p; j++) {
			calc(i, j);
		}
	}
	int full = (1 << p) - 1;
	for (int i = 0; i < (1 << p); i++) {
		can[i] = 1;
		for (int x = 0; x < p; x++) {
			if (!(i >> x & 1)) continue;
			for (int y = x; y < p; y++) {
				if (!(i >> y & 1)) continue;
				if (no[x][y][full ^ i]) can[i] = 0;
			}
		}
	}
	q.push(full), vis[full] = 1;
	int ans = 0x3f3f3f3f;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		int sum = 0;
		for (int i = 0; i < p; i++) {
			if (x >> i & 1) sum += cnt[i];
		}
		ans = min(ans, sum);
		for (int i = 0; i < p; i++) {
			if (x >> i & 1) {
				int nx = x ^ 1 << i;
				if (!vis[nx] && can[nx]) vis[nx] = 1, q.push(nx);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}