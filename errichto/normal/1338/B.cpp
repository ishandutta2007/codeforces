#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
vector<int> edges[MAX_N];
int depth[MAX_N];

bool is_leaf(int a) {
	return (int) edges[a].size() == 1;
}

int wasted = 0;
int small = 1;
set<int> values;
void dfs(int a, int parent) {
	if(is_leaf(a)) {
		values.insert(depth[a] % 2);
	}
	int children_leaves = 0;
	for(int b : edges[a]) {
		if(b == parent) {
			continue;
		}
		depth[b] = depth[a] + 1;
		dfs(b, a);
		if(is_leaf(b)) {
			children_leaves++;
		}
	}
	if(children_leaves >= 2) {
		wasted += children_leaves - 1;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int a = 1; a <= n; ++a) {
		if(!is_leaf(a)) {
			dfs(a, -1); // root
			break;
		}
	}
	int big = n - 1 - wasted;
	if((int) values.size() == 2) {
		small = 3; // :(
	}
	printf("%d %d\n", small, big);
}