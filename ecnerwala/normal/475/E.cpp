#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2020;
const int MAXM = MAXN * MAXN / 2;

int N, M;

int L[MAXM];
int R[MAXM];
bool adj[MAXN][MAXN];

int par[MAXN];
int depth[MAXN];

int val[MAXN];
int sz[MAXN];

bool dp[MAXN];

int getpar(int a) {
	return par[a] == a ? a : (par[a] = getpar(par[a]));
}

void tarjan(int cur, int prv = -1) {
	assert(par[cur] == -1);
	par[cur] = cur;
	for(int nxt = 0; nxt < N; nxt++) {
		if(!adj[cur][nxt]) continue;
		if(nxt == prv) continue;
		if(par[nxt] != -1) {
			if(depth[par[nxt]] < depth[par[cur]]) par[cur] = par[nxt];
		} else {
			depth[nxt] = depth[cur] + 1;
			tarjan(nxt, cur);
			if(depth[par[nxt]] < depth[par[cur]]) par[cur] = par[nxt];
		}
	}
}

int res = 0;


int dfssz(int cur, int prv = -1) {
	sz[cur] = val[cur];
	for(int nxt = 0; nxt < N; nxt++) {
		if(!adj[cur][nxt]) continue;
		if(nxt == prv) continue;
		sz[cur] += dfssz(nxt, cur);
	}
	return sz[cur];
}

int findcentroid(int cur, int prv = -1) {
	int res = -1;
	for(int nxt = 0; nxt < N; nxt++) {
		if(!adj[cur][nxt]) continue;
		if(nxt == prv) continue;
		int a = findcentroid(nxt, cur);
		if(a != -1) res = a;
	}
	if(res != -1) return res;
	else if(sz[cur] * 2 >= N) return cur;
	else return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> L[i] >> R[i];
		L[i] --, R[i] --;
		adj[L[i]][R[i]] = adj[R[i]][L[i]] = true;
	}

	memset(par, -1, sizeof(par));
	tarjan(0);
	assert(par[0] == 0);

	for(int i = 0; i < N; i++) {
		val[getpar(i)] ++;
	}

	memset(adj, 0, sizeof(adj));

	int v = 0;
	int e = 0;
	for(int i = 0; i < M; i++) {
		L[i] = getpar(L[i]);
		R[i] = getpar(R[i]);
		if(L[i] == R[i]) continue;
		adj[L[i]][R[i]] = adj[R[i]][L[i]] = true;
		e++;
	}
	for(int i = 0; i < N; i++) {
		if(par[i] == i) v++;
	}
	assert(v - 1 == e);

	dfssz(0);
	int cent = findcentroid(0);
	dfssz(cent);
	assert(sz[cent] == N);

	cerr << cent << '\n';

	res = 0;
	for(int i = 0; i < N; i++) {
		if(par[i] == i) {
			res += sz[i] * val[i];
		}
	}

	int n = N - val[cent];

	dp[0] = true;
	for(int i = 0; i < N; i++) {
		if(adj[cent][i]) {
			for(int v = N; v >= 0; v--) {
				if(!dp[v]) continue;
				dp[v + sz[i]] = true;
				assert(v + sz[i] <= n);
			}
		}
	}


	for(int i = n / 2; i >= 0; i--) {
		if(dp[i]) {
			assert(dp[n - i]);
			res += (n - i) * i;
			break;
		}
	}
	cout << res << '\n';

	return 0;
}