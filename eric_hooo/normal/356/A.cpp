#include <bits/stdc++.h>
using namespace std;

int fa[300010], ans[300010];

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 1; i++){
		fa[i] = i;
	}
	for (int i = 0; i < m; i++){
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		for (int i = find(l); i <= r; i = find(i + 1)){
			if (i != x) ans[i] = x, fa[i] = i + 1;
		}
	}
	for (int i = 1; i <= n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}