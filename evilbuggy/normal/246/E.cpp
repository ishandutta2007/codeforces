#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

string s[maxN];
vector<int> g[maxN];
vector<pair<int, int> > queries[maxN];
int n, m, f[maxN], lo[maxN], hi[maxN], pos[maxN], ind[maxN], chk[maxN];
int ptr, p[maxN], d[maxN], sz[maxN], st[maxN], en[maxN], vert[maxN], ans[maxN];

void dfs(int v, int __d = 0){
	vert[ptr] = v;
	st[v] = ptr++;
	d[v] = __d; sz[v] = 1; 
	for(int u : g[v]){
		dfs(u, __d + 1);
		sz[v] += sz[u];
	}
	en[v] = ptr;
}

inline void update(int i, int x){
	while(i <= n){
		f[i] += x;
		i += i&(-i);
	}
}

inline int query(int i){
	int ret = 0;
	while(i){
		ret += f[i];
		i &= i - 1;
	}
	return ret;
}

void uwu(int v, bool keep){
	int bg = -1;
	for(int u : g[v]){
		if(bg == -1 || sz[u] > sz[bg])bg = u;
	}
	for(int u : g[v]){
		if(u != bg)uwu(u, false);
	}
	if(bg != -1)uwu(bg, true);
	
	if(v && !chk[pos[v]]){
		update(pos[v], 1);
		chk[pos[v]] = 1;
	}
	for(int u : g[v]){
		if(u == bg)continue;
		for(int i = st[u]; i < en[u]; i++){
			int w = vert[i];
			if(!chk[pos[w]]){
				update(pos[w], 1);
				chk[pos[w]] = 1;
			}
		}
	}
	for(auto x : queries[v]){
		int i = x.second, k = x.first + d[v];
		if(k <= n && lo[k] != -1){
			ans[i] = query(hi[k]) - query(lo[k] - 1);
		}else{
			ans[i] = 0;
		}
	}
	if(!keep){
		for(int i = st[v]; i < en[v]; i++){
			int u = vert[i];
			if(chk[pos[u]]){
				update(pos[u], -1);
				chk[pos[u]] = 0;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i] >> p[i];
		g[p[i]].emplace_back(i);
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		int v; cin >> v;
		int k; cin >> k;
		queries[v].emplace_back(k, i);
	}
	map<string, int> strInd;
	for(int i = 1; i <= n; i++){
		if(strInd.count(s[i])){
			ind[i] = strInd[s[i]];
		}else{
			int x = (int)strInd.size();
			ind[i] = strInd[s[i]] = x + 1;
		}
	}
	ptr = 1; dfs(0);
	vector<pair<int, int> > vec;
	for(int i = 1; i <= n; i++){
		vec.emplace_back(d[i], ind[i]);
	}
	sort(vec.begin(), vec.end());
	vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
	for(int i = 1; i <= n; i++){
		pos[i] = lower_bound(vec.begin(), vec.end(), make_pair(d[i], ind[i])) - vec.begin(); pos[i]++;
	}
	memset(lo, -1, sizeof(lo));
	memset(hi, -1, sizeof(hi));
	for(int i = 0; i < (int)vec.size(); i++){
		if(lo[vec[i].first] == -1){
			lo[vec[i].first] = i + 1;
		}
		hi[vec[i].first] = i + 1;
	}
	memset(f, 0, sizeof(f));
	memset(chk, 0, sizeof(chk));
	
	uwu(0, true);
	for(int i = 1; i <= m; i++){
		cout << ans[i] << '\n';
	}

	return 0;
}