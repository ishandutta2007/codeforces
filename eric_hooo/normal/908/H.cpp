#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

string adj[50];
char G[50][50];
int qwq[50];
int fa[50], sz[50];
int f[1 << 23], g[1 << 23];
int cnt[1 << 23];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void FMT(int *f, int N) {
	for (int i = 0; i < N; i++) {
		for (int mask = 0; mask < (1 << N); mask++) {
			if (mask >> i & 1) f[mask] += f[mask ^ 1 << i];
		}
	}
}

int main () {
	for (int i = 0; i < (1 << 23); i++) {
		cnt[i] = cnt[i >> 1] + (i & 1);
	}
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		fa[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> adj[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (adj[i][j] == 'A') fa[find(i)] = find(j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (find(i) == find(j) && adj[i][j] == 'X') {
				printf("-1\n");
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		sz[find(i)]++;
	}
	memset(G, 'O', sizeof(G));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x = find(i), y = find(j);
			if (x != y) {
				if (adj[i][j] == 'X') G[x][y] = 'X';
			}
		}
	}
	vector <int> node;
	int ans = n;
	for (int i = 0; i < n; i++) {
		if (find(i) != i) continue;
		if (sz[i] != 1) node.push_back(i);
	}
	int N = node.size();
	for (int i = 0; i < N; i++) {
		int x = node[i];
		for (int j = 0; j < N; j++) {
			int y = node[j];
			if (G[x][y] == 'X') qwq[i] |= 1 << j;
		}
	}
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if ((i & qwq[j]) && (i >> j & 1)) goto END;
		}
		f[i] = 1;
		END:;
	}
	FMT(f, N);
	for (int i = 0; i < (1 << N); i++) {
		g[i] = 1;
	}
	for (int it = 0; it <= N; it++) {
		int sum = 0;
		for (int i = 0; i < (1 << N); i++) {
			sum = (sum + (N - cnt[i] & 1 ? -1ll : 1ll) * g[i] + mod) % mod;
		}
		if (sum) {
			ans += it;
			break;
		}
		for (int i = 0; i < (1 << N); i++) {
			g[i] = 1ll * g[i] * f[i] % mod;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}