#include <bits/stdc++.h>

int n,a[105],vis[105],ans;

int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	for (int i = 1; i <= n; ++ i) {
		if (vis[i]) continue;
		ans ++; vis[i] = 1;
		int c = 1;
		for (int j = i + 1; j <= n; ++ j) 
			 if (!vis[j] && a[j] >= c) { c ++; vis[j] = 1; }
	} printf("%d",ans);
	return 0;
}