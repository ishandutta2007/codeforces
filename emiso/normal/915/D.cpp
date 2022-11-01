#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, can = 0, visit[550];
vector<pair<int, int> > adj[550];

int dfs(int no, int forbid) { // 1 = OK; 0 = CYCLE
	if(visit[no] == 2) return 1;
	if(visit[no] == 1) return 0;
	visit[no] = 1;
	for(auto p : adj[no]) {
		if(p.second == forbid) continue;
		if(dfs(p.first, forbid) == 0) return 0;
	}
	visit[no] = 2;
	return 1;
}	

vector<int> cycle;
int find_cycle(int no) { // 1 = OK; 0 = CYCLE
	if(visit[no] == 2 || !cycle.empty()) return 1;
	if(visit[no] == 1) {
		visit[no] = 3;
		return 0;
	}
	visit[no] = 1;
	for(auto p : adj[no]) {
		if(find_cycle(p.first) == 0) {
			cycle.push_back(p.second);
			return visit[no] == 3;
		}
	}
	visit[no] = 2;
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a].emplace_back(b, i);
	}
	
	for(int i = 1; i <= n && cycle.empty(); i++)
		if(!visit[i]) find_cycle(i);
	
	if(cycle.empty()) can = 1;
	for(int forbid : cycle) {
		memset(visit, 0, sizeof visit);
		int tmp = 1;
		for(int i = 1; i <= n && tmp; i++)
			if(!visit[i]) tmp &= dfs(i, forbid);
		can |= tmp;
	}
	
	printf("%s\n", can ? "YES" : "NO");
	return 0;
}