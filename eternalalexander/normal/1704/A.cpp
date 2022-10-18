#include <bits/stdc++.h>

const int maxn = 1000;
int n,m;
char a[maxn],b[maxn];

void solve() {
	scanf("%d%d%s%s",&n,&m,a + 1,b + 1);
	for (int i = 1; i < m; ++ i) if (a[n - i + 1] != b[m - i + 1]) { puts("NO"); return ; }
	int flag = 0;
	for (int i = 1; i <= n - m + 1; ++ i) if (a[i] ==  b[1]) flag = 1;
	if (flag) puts("YES");
	else puts("NO");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}