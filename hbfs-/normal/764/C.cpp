#include <iostream>
#include <cstdio>
#include <queue>
#define N 200050

using namespace std;
int n,rd[N],vis[N],c[N],ans;
vector<int> e[N];
int main() {
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++) {
		int u,v; scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		rd[u]++; rd[v]++;
	}
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	bool flag = true;
	queue<int> q;
	for (int i=1;i<=n;i++) if (rd[i] == 1) q.push(i);
	while (!q.empty()) {
		int u = q.front(); q.pop(); vis[u] = 1;
		for (int i=0;i<(int)e[u].size();i++) {
			int v = e[u][i]; if (vis[v]) continue;
			rd[v]--; 
			if (c[u] == c[v])  {
				if (rd[v] == 1) q.push(v);
				continue;
			}
			else {
				
				if (!ans || ans == v) ans = v; else flag = false;
			}
			if (!flag) break;
		}
		if (!flag) break;
	}
	if (flag && ans == 0) ans = 1;
	if (flag)
		printf("YES\n%d\n",ans);
	else
		puts("NO");
	return 0;
}