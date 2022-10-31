#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> tree[100011];
vector<int> ans;
int n, a=0, b=0;
bool used[100011];
int init[100011], goal[100011], changed[100011];

void dfs(int v, int c1, int c2) {
	used[v]=true;
	if (c1^init[v]^goal[v]) ans.push_back(v), changed[v]=true;
	int sz=(int)tree[v].size();
	for (int i=0; i<sz; i++) {
		if (!used[tree[v][i]]) dfs(tree[v][i], c2, c1^changed[v]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i=0; i<n-1; i++) {
		scanf("%d%d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	for (int i=1; i<=n; i++) scanf("%d", &init[i]);
	for (int i=1; i<=n; i++) scanf("%d", &goal[i]);
	dfs(1, 0, 0);
	int sz=(int)ans.size();
	printf("%d\n", sz);
	for (int i=0; i<sz; i++) printf("%d\n", ans[i]);
    return 0;
}