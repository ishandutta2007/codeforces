#include<bits/stdc++.h>
using namespace std;

void wssert(bool b) {
	if (!b) {
		printf("THIS IS WRONG\n");
		exit(0);
	}
}

const int MAXN = 1e5;
const int B = 256;
const int MAXS = 250;

const int R = 0; // root
int N;
int A[MAXN];
vector<int> adj[MAXN];
int prec[MAXN][B];
int anc[MAXN];
int par[MAXN];
int depth[MAXN]; // number of things on path to root

void dfs(int cur, int prv = -1) {
	par[cur] = prv;
	if (prv == -1) depth[cur] = 1;
	else depth[cur] = depth[prv] + 1;
	if (depth[cur] >= B) {
		anc[cur] = cur;
		memset(prec[cur], -1, sizeof(prec[cur]));
		for (int i = 0; i < B; i++) {
			int cnd = i ^ A[anc[cur]];
			int bucket = 255 ^ (cnd >> 8); // best bucket is opposite bucket
			cnd ^= (bucket << 8);
			assert((cnd >> 8) == 255);
			prec[cur][bucket] = max(prec[cur][bucket], cnd);
			anc[cur] = par[anc[cur]];
		}
		for (int i = 0; i < 8; i++) {
			int m = 1 << i;
			for (int j = 0; j < 256; j++) {
				if (prec[cur][j] == -1) {
					if (prec[cur][m ^ j] > -1) {
						assert(prec[cur][m^j] & (m << 8));
						prec[cur][j] = prec[cur][m^j] ^ (m << 8);
					}
				}
			}
		}
	}
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);
	}
}

int query(int v, int h) {
	assert(h >= 1);
	int cur = v;
	int res = A[v];
	for (int i = 0; i < h / B; i++) {
		assert(depth[cur] >= B);
		res = max(res, prec[cur][i]);
		cur = anc[cur];
	}
	for (int i = h / B * B; i < h; i++) {
		res = max(res, A[cur] ^ i);
		cur = par[cur];
	}
	return res;
}

int main() {
	int Q = 0;
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N-1; i++) {
		int u, v; scanf("%d %d", &u, &v); u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(R);
	for (int i = 0; i < Q; i++) {
		int u, v; scanf("%d %d", &u, &v); u--, v--;
		assert(depth[u] <= depth[v]);
		int res = query(v, depth[v] - depth[u] + 1);
		printf("%d\n", res);
	}
	return 0;
}