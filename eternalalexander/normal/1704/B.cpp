#include <bits/stdc++.h>

const int maxn = 4e5 + 222;
using ll = long long;
int n;
ll x,a[maxn];


void solve() {
	scanf("%d%lld",&n,&x);
	for (int i = 1; i <= n; ++ i) scanf("%lld",&a[i]);
	ll l = a[1], r = a[1];
	int cnt = 0;
	for (int i = 2; i <= n; ++ i) {
		l = std::min(l,a[i]);
		r = std::max(r,a[i]);
		if (r - l > 2 * x) { cnt ++; r = l = a[i]; }
	} printf("%d\n",cnt);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}