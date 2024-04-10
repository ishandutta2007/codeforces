#include <bits/stdc++.h>

const int maxn = 2e5 + 222;
int n,m,k,a[maxn];

int check(int n,int m) {
	int ans = 0,g = 0;
	for (int i = 1; i <= k; ++ i) {
		int lim = a[i] / n;
		if (lim < 2) continue;
		int nd = m - ans;
		if (nd >= 2) {
			ans += std::min(nd,lim);
			if (lim > 2) g = 1;
			if (ans >= m) return 1;
		} else {
			assert(nd == 1);
			if (g) return 1;
			return 0;
		}
		
	} return 0;
}

void solve() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= k; ++ i) scanf("%d",&a[i]);
	std::sort(a + 1,a + k + 1,[](int x,int y) { return x > y; });
	if (check(n,m) || check(m,n)) puts("Yes");
	else puts("No");
}

int main() {
	int t;scanf("%d",&t);while (t--)solve();
	return 0;
}