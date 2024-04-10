#include <bits/stdc++.h>

int n,a[100005];

void solve() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	std::sort(a + 1,a + n + 1);
	for (int i = 1; i < n; ++ i) if (a[i] == a[i + 1]) { puts("NO"); return ; }
	puts("YES");
	
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}