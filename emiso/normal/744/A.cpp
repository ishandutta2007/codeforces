#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, k, a, b, comp[1010], cont, mark[1010], x;
vector<int> spec, adj[1010];

ll ans, sz[1010];

int dfs(int no, int c) {
	if(comp[no]) return 0;
	comp[no] = c;
	int ret = 1;
	for(int v : adj[no])
		ret += dfs(v, c);
	return ret;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < k; i++) {
		scanf("%d", &x);
		spec.push_back(x);
		mark[x] = 1;
	}
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	ll mx = 0, mxi;
	for(int s : spec) {
		sz[s] = dfs(s, ++cont);
		ans += (sz[s] * (sz[s]-1))/2;
		if(sz[s] > mx) {
			mx = sz[s];
			mxi = s;
		}
	}
	ans -= (mx * (mx-1))/2;
	for(int i = 1; i <= n; i++)
		if(!comp[i]) {
			adj[i].push_back(mxi);
			adj[mxi].push_back(i);
		}
	memset(comp, 0, sizeof comp);
	sz[mxi] = dfs(mxi, ++cont);
	ans += (sz[mxi] * (sz[mxi]-1))/2;	
	
	printf("%lld\n", ans-m);
	return 0;
}