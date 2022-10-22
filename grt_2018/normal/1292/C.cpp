#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 3000+10;
int n,root,dep;
vi V[nax];
int par[nax][nax], sz[nax][nax];
ll dp[nax][nax];
vector<pi>dist[nax];

void dfs(int x,int p) {
	dep++;
	par[x][root] = p;
	sz[x][root] = 1;
	for(int nbh : V[x]) if(nbh != p) {
		dfs(nbh,x);
		if(root < nbh) dist[dep].PB({root,nbh});
		sz[x][root] += sz[nbh][root];
	}
	dep--;
}

int main() {_
	cin >> n;
	for(int a,b,i = 1; i < n; ++i) {
		cin >> a >> b;
		V[a].PB(b);
		V[b].PB(a);
	}
	for(int i = 1; i <= n; ++i) {
		root = i;
		dfs(i,0);
	}
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(auto p : dist[i]) {
			dp[p.ST][p.ND] = (ll)sz[p.ST][p.ND] * sz[p.ND][p.ST] + max(dp[par[p.ND][p.ST]][p.ST], dp[p.ND][par[p.ST][p.ND]]);
			dp[p.ND][p.ST] = dp[p.ST][p.ND];
			ans = max(ans,dp[p.ST][p.ND]);
		}
	}
	cout << ans;
}