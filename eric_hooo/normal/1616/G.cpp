#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[150010];
int sum[150010];
vector <int> G[150010], H[150010];
int vis[300010];
queue <int> q;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= n; i++) {
			a[i] = 0, G[i].clear(), H[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			if (x + 1 == y) a[x] = 1;
			else G[x].push_back(y), H[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			if (i > 1) G[0].push_back(i), H[i].push_back(0);
			if (i < n) G[i].push_back(n + 1), H[n + 1].push_back(i);
		}
		if ([&]() -> bool {
			for (int i = 1; i < n; i++) {
				if (!a[i]) return 0;
			}
			return 1;
		}()) {
			printf("%lld\n", 1ll * n * (n - 1) / 2);
			continue;
		}
		a[n] = 1;
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + a[i];
		}
		auto OK = [&](int l, int r) -> int {return sum[r - 1] - sum[l - 1] == r - l;};
		long long ans = 0;
		for (int i = 1; i < n; i++) {
			if (a[i]) continue;
			for (int i = 0; i <= n; i++) {
				vis[i << 1] = vis[i << 1 | 1] = 0;
			}
			q.push(i << 1), vis[i << 1] = 1;
			while (!q.empty()) {
				int x = q.front() >> 1, p = q.front() & 1; q.pop();
				// cerr << "       rs:" << x << " " << p << endl;
				for (auto y : G[x]) {
					int v = y - 1 << 1 | (p ^ 1);
					if (OK(x + 1, y - 1) && !vis[v]) q.push(v), vis[v] = 1;
				}
			}
			int rs[3] = {0, 0, 0};
			for (int j = i; j <= n; j++) {
				if (!OK(j + 1, n + 1)) continue;
				if (vis[j << 1]) rs[0]++;
				if (vis[j << 1 | 1]) rs[1]++;
				if (vis[j << 1] && vis[j << 1 | 1]) rs[2]++;
			}

			for (int i = 0; i <= n; i++) {
				vis[i << 1] = vis[i << 1 | 1] = 0;
			}
			q.push(i << 1 | 1), vis[i << 1 | 1] = 1;
			while (!q.empty()) {
				int x = q.front() >> 1, p = q.front() & 1; q.pop();
				// cerr << "       ls:" << x << " " << p << endl;
				for (auto y : H[x + 1]) {
					int v = y << 1 | (p ^ 1);
					if (OK(y + 1, x) && !vis[v]) q.push(v), vis[v] = 1;
				}
			}
			int ls[3] = {0, 0, 0};
			for (int j = 0; j <= i; j++) {
				if (vis[j << 1]) ls[0]++;
				if (vis[j << 1 | 1]) ls[1]++;
				if (vis[j << 1] && vis[j << 1 | 1]) ls[2]++;
			}
			if (n == 6) {
				// cout << "         ls:" << ls[0] << " " << ls[1] << " " << ls[2] << endl;
				// cout << "         rs:" << rs[0] << " " << rs[1] << " " << rs[2] << endl;
			}
			ans = 1ll * ls[0] * rs[1] + 1ll * ls[1] * rs[0] - 1ll * ls[2] * rs[2];
			int cnt = 0;
			for (int i = 1; i < n; i++) {
				cnt += a[i] == 0;
			}
			if (cnt == 1) ans--;
			break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}