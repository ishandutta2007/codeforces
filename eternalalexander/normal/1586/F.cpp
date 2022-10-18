#include <bits/stdc++.h>

int k,n,G[1005][1005],c[1005],d[1005];

int main() {
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; ++ i) 
		c[i] = i;
	int cnt = n;
	int col = 0;
	while (cnt > 1) {
		++ col;
		for (int i = 1; i <= cnt; ++ i) d[i] = (i - 1) / k + 1;
	//	for (int i = 1; i <= cnt; ++ i) printf("%d ",d[i]); puts("");
		for (int i = 1; i <= n; ++ i) 
			for (int j = i + 1; j <= n; ++ j) 
				if ((c[i] != c[j]) && (d[c[i]] == d[c[j]])) G[i][j] = col;
		for (int i = 1; i <= n; ++ i) c[i] = d[c[i]];
		cnt = d[cnt];
	} printf("%d\n",col);
	for (int i = 1; i <= n; ++ i)
	for (int j = i + 1; j <= n; ++ j)
		printf("%d ",G[i][j]);
	return 0;
}