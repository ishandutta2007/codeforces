#include <bits/stdc++.h>

using ll = long long;
int n;
ll k,h[1000005];
const ll inf = 1e9;

void solve() {
	scanf("%d%lld",&n,&k);
	for (int i = 1; i <= n; ++ i) scanf("%lld",&h[i]);
	ll l = h[1] + 1, r = h[1] + 1;
	for (int i = 2; i <= n; ++ i) {
		l = std::max(h[i] + 1,l - (k - 1));
		r = std::min(h[i] + k,r + (k - 1));
		if (l > r) { puts("NO"); return; }
	} if (l <= h[n] + 1 && h[n] + 1 <= r) puts("YES");
	else puts("NO");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
		
	return 0;
}