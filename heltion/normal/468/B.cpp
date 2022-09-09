#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000;
namespace SAT{
	int scc[maxn << 1];
	bool vis[maxn << 1], ans[maxn];
	stack<int> s;
	vector<int> G[maxn << 1], GT[maxn << 1];
	void init(int n){
		for(int i = 0; i < 2 * n; i += 1){
			G[i].clear();
			GT[i].clear();
			vis[i] = false;
			scc[i] = -1;
		}
	}
	void add_edge(int u, int v){
		G[u].push_back(v);
		GT[v].push_back(u);
	}
	void DFS1(int u){
		vis[u] = true;
		for(int v : G[u]) if(not vis[v]) DFS1(v);
		s.push(u);
	}
	void DFS2(int u, int c){
		scc[u] = c;
		for(int v : GT[u]) if(not ~scc[v]) DFS2(v, c);
	}
	bool solve(int n){
		for(int i = 0; i < 2 * n; i += 1) if(not vis[i]) DFS1(i);
		for(int i = 0; not s.empty(); s.pop()) if(not ~scc[s.top()]) DFS2(s.top(), i ++);
		for(int i = 0; i < n; i += 1) if(scc[i] == scc[i + n]) return false;
		else ans[i] = scc[i] > scc[i + n];
		return true;
	}
}
map<int, int> mp;
int p[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, a, b;
	cin >> n >> a >> b;
	for(int i = 0; i < n; i += 1){
		cin >> p[i];
		mp[p[i]] = i;
	}
	SAT::init(n);
	for(int i = 0; i < n; i += 1){
		if(mp.count(a - p[i])){
			SAT::add_edge(i + n, mp[a - p[i]] + n);
			SAT::add_edge(i, mp[a - p[i]]);
		}
		else SAT::add_edge(i + n, i);
		if(mp.count(b - p[i])){
			SAT::add_edge(i + n, mp[b - p[i]] + n);
			SAT::add_edge(i, mp[b - p[i]]);
		}
		else SAT::add_edge(i, i + n);
	}
	if(not SAT::solve(n)) cout << "NO";
	else{
		cout << "YES\n";
		for(int i = 0; i < n; i += 1) cout << SAT::ans[i] << " ";
	}
	return 0;
}