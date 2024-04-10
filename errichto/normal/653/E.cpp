#include<bits/stdc++.h>
using namespace std;
set<pair<int,int>> forbidden;
bool is_ok(int a, int b) {
	if(a > b) swap(a, b);
	return forbidden.find(make_pair(a, b)) == forbidden.end();
}
set<int> remaining;
void dfs(int a) {
	vector<int> memo;
	for(int b : remaining) if(is_ok(a, b))
		memo.push_back(b);
	for(int b : memo)
		remaining.erase(b);
	for(int b : memo) dfs(b);
}
void NO() {
	puts("impossible");
	exit(0);
}
int main() {
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 2; i <= n; ++i) remaining.insert(i);
	int allowed_degree = n - 1; // maximum possible degree of vertex 1
	for(int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		if(a == 1) --allowed_degree;
		forbidden.insert(make_pair(a, b));
	}
	if(allowed_degree < k) NO(); // not enough allowed edges from 1
	int components = 0; // connected components
	for(int i = 2; i <= n; ++i) if(is_ok(1, i) && remaining.find(i)!=remaining.end()) {
		dfs(i);
		++components;
	}
	if(!remaining.empty()) NO(); // the graph isn't connected
	if(components > k) NO(); // we need more than k edges from 1
	
	puts("possible");
	return 0;
}