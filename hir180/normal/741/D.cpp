#include <bits/stdc++.h>
using namespace std;
#define sz 500005
int n, val[sz], dep[sz], cnt[1 << 22], ans[sz], sub[sz], beg[sz], en[sz], vert[sz], id;
vector<pair<int, int>>edge[sz];

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=2;i<=n;i++){
		int p; string s; cin >> p >> s;
		edge[p].emplace_back(i, (1<<(s[0]-'a')));
	}
	auto make = [&](int v, int u, int up, auto make) -> void{
		beg[v] = id; vert[id] = v; id ++; sub[v] = 1; val[v] = up;
		if(u == -1) dep[v] = 1; else dep[v] = dep[u] + 1;
		for(auto c:edge[v]){
			if(c.first != u){
				make(c.first, v, up ^ c.second, make);
				sub[v] += sub[c.first];
			}
		}
		en[v] = id - 1;
	};
	make(1, -1, 0, make);
	auto dfs = [&](int v, int u, bool ers, auto dfs) -> void{
		pair<int, int>big = make_pair(-1, -1);
		for(auto c:edge[v]){
			if(c.first != u) big = max(big, make_pair(sub[c.first], c.first));
		}
		for(auto c:edge[v]){
			if(c.first != u and c.first != big.second) dfs(c.first, v, true, dfs);
		}
		if(big.first != -1) dfs(big.second, v, false, dfs);
		//cnt[] contains information about subtree of big.second
		for(auto c:edge[v]){
			if(c.first != u and c.first != big.second) {
				for(int id=beg[c.first];id<=en[c.first];id++){
					int v1 = val[vert[id]];
					for(int x=-1;x<22;x++){
						int v2 = (x==-1?v1:v1^(1<<x));
						if(cnt[v2]) {
							int nw = cnt[v2]+dep[vert[id]]-2*dep[v];
							if(ans[v] < nw) ans[v] = nw;
						}
					}
				}
				for(int id=beg[c.first];id<=en[c.first];id++) cnt[val[vert[id]]] = max(cnt[val[vert[id]]], dep[vert[id]]);
			}
		}
		cnt[val[v]] = max(cnt[val[v]], dep[v]);
		for(int x=-1;x<22;x++){
		    int v2 = (x==-1?val[v]:val[v]^(1<<x));
		    ans[v] = max(ans[v], cnt[v2] - dep[v]);
		}
		for(auto c:edge[v]){
			if(c.first != u) ans[v] = max(ans[v], ans[c.first]);
		}
		if(ers){
			for(int id=beg[v];id<=en[v];id++) cnt[val[vert[id]]] = 0;
		}
	};
	dfs(1, -1, 0, dfs);
	for(int i=1;i<=n;i++) cout << ans[i] << '\n';
	return 0;
}