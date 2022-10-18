#include <bits/stdc++.h>

int n,p,G[30][30];

void solve() {
	scanf("%d%d",&n,&p);
	std::memset(G,0,sizeof(G));
	auto add = [](int x,int y) {
		if (G[x][y]) return 0;
		G[x][y] = G[y][x] = 1;
		return 1;
	};
	for (int i = 1; i <= n; ++ i) {
		add(i,i % n + 1);
		add(i,(i + 1) % n + 1);
	} for (int i = 1; i <= n; ++ i) {
		for (int j = i + 1; j <= n; ++ j) {
			p -= add(i,j);
			if (p == 0) break;
		} if (p == 0) break;
	} for (int i = 1; i <= n; ++ i) 
	for (int j = i + 1; j <= n; ++ j)
		if (G[i][j]) printf("%d %d\n",i,j);
}

int main() {
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}