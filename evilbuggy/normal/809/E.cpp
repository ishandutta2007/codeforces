#include <bits/stdc++.h>
using namespace std;

const int K = 18;
const int N = 200005;
const int mod = 1000000007;

int lpf[N], totient[N], inverse[N], sumtotient[N], sumtotientdepth[N];
int iter, a[N], en[N], mu[N], inva[N], depth[N], parent[K][N];
vector<int> g[N], adj[N], vertices[N];

inline void init(int n){
	inverse[1] = 1;
	for(int i = 2; i <= n; i++){
		inverse[i] = inverse[mod%i]*1LL*(mod - mod/i)%mod;
	}
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			vertices[i].emplace_back(inva[j]);
		}
	}
	mu[1] = 1;
	totient[1] = 1;
	memset(lpf, -1, sizeof(lpf));
	for(int i = 2; i <= n; i++){
		if(lpf[i] == -1){
			for(int j = i; j <= n; j += i){
				if(lpf[j] == -1)lpf[j] = i;
			}
		}
		if((i/lpf[i])%lpf[i] == 0){
			mu[i] = 0;
			totient[i] = totient[i/lpf[i]]*lpf[i];
		}else{
			mu[i] = -mu[i/lpf[i]];
			totient[i] = totient[i/lpf[i]]*(lpf[i] - 1);
		}
	}
}

void dfs(int v, int p){
	parent[0][v] = p;
	depth[v] = depth[p] + 1;
	for(int u : g[v]){
		if(u != p){
			dfs(u, v);
		}
	}
	en[v] = iter++;
}

inline int lca(int u, int v){
	if(depth[u] < depth[v])swap(u, v);
	int diff = depth[u] - depth[v];
	for(int i = K - 1; i >= 0; i--){
		if((diff >> i) & 1){
			u = parent[i][u];
		}
	}
	if(u == v)return u;
	for(int i = K - 1; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][u];
}

inline void add(int &x, int y){
	x += y; if(x >= mod)x -= mod;
}

int cnt;

int compute(int v, int d){
	int ret = 0;
	sumtotient[v] = sumtotientdepth[v] = 0;
	if(a[v]%d == 0){
		cnt++;
		sumtotient[v] = totient[a[v]];
		sumtotientdepth[v] = totient[a[v]]*1LL*depth[v]%mod;
	}
	for(int u : adj[v]){
		ret += compute(u, d); 
		if(ret >= mod)ret -= mod;
		long long tmp = sumtotient[v]*1LL*sumtotientdepth[u] + sumtotientdepth[v]*1LL*sumtotient[u];
		tmp += (mod - 2*depth[v])*(sumtotient[v]*1LL*sumtotient[u]%mod);
		tmp %= mod; ret += tmp; if(ret >= mod)ret -= mod;
		add(sumtotient[v], sumtotient[u]);
		add(sumtotientdepth[v], sumtotientdepth[u]);
	}
	return ret;
}

void clear(int v){
	for(int u : adj[v]){
		clear(u);
	}
	adj[v].clear();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		inva[a[i]] = i;
	}
	init(n);
	for(int i = 2; i <= n; i++){
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	iter = 1; depth[0] = 0; dfs(1, 0);
	for(int k = 1; k < K; k++){
		parent[k - 1][0] = 0;
		for(int i = 1; i <= n; i++){
			parent[k][i] = parent[k - 1][parent[k - 1][i]];
		}
	}
	parent[K - 1][0] = 0;
	int answer = 0;
	for(int d = 1; d <= n; d++){
		if(vertices[d].size() <= 1 || mu[d] == 0)continue;
		set<pair<int, int> > st;
		for(int u : vertices[d]){
			st.insert({en[u], u});
		}
		while(st.size() > 1){
			int x = st.begin()->second; st.erase(st.begin());
			int y = st.begin()->second;
			int z = lca(x, y);
			if(x != z){
				adj[z].emplace_back(x);
			}
			st.insert({en[z], z});
		}
		cnt = 0;
		int root = st.begin()->second;
		int total = compute(root, d)*1LL*inverse[totient[d]]%mod;
		answer += total; if(answer >= mod)answer -= mod;
		clear(root);
	}
	answer <<= 1; if(answer >= mod)answer -= mod;
	answer = answer*1LL*inverse[n - 1]%mod;
	answer = answer*1LL*inverse[n]%mod;
	cout << answer << '\n';

	return 0;
}