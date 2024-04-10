#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
int n,a[maxn],vis[maxn];

void solve() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		vis[i] = 0;
	} 
	int b = 0;
	std::vector<int>ans;
	for (int i = 1; i <= n; ++ i) {
		int max = b, mp = 0;
		for (int j = 1; j <= n; ++ j) {
			if (vis[j]) continue;
			if ((b | a[j]) > max) { max = (b | a[j]); mp = j; }
		} 
		if (!mp) break;
		vis[mp] = 1;
		b = max;
		ans.push_back(a[mp]);
	} for (int i = 1; i <= n; ++ i) if (!vis[i]) ans.push_back(a[i]);
	for (int x:ans) printf("%d ",x); 
	puts("");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}