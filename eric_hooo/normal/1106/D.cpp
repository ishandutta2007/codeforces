#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector <int>, greater <int> > q;
vector <int> from[100010];
int vis[100010];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	q.push(1), vis[1] = 1;
	vector <int> ans;
	while (!q.empty()){
		int u = q.top(); q.pop();
		ans.push_back(u);
		for (int i = 0; i < from[u].size(); i++){
			int v = from[u][i];
			if (vis[v]) continue;
			q.push(v), vis[v] = 1;
		}
	}
	for (int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}