#include <bits/stdc++.h>

using ll = long long;

void solve() {
	ll n;
	scanf("%lld",&n);
	while (n % 2 == 0) n /= 2;
	if (n == 1) puts("No");
	else puts("Yes");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}