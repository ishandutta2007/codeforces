#include <bits/stdc++.h>
using namespace std;

int fa[400010];

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n + m; i++){
		fa[i] = i;
	}
	int ans = n + m;
	for (int i = 0; i < k; i++){
		int u, v;
		scanf("%d%d", &u, &v), v += n;
//		cout << "  " << u << " " << v << endl;
		if (find(u) == find(v)) continue;
		ans--, fa[find(u)] = find(v); 
	}
	printf("%d\n", ans - 1);
	return 0;
}