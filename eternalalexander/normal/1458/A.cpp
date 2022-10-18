#include <bits/stdc++.h>
using ll = long long;
const int maxn = 2e5+10;
int n,m;
ll a[maxn],b[maxn];
ll gcd(ll a,ll b) {
	return b == 0 ? a : gcd(b,a%b); 
}

ll Myabs(ll x) { return x < 0 ? -x : x; }

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	for (int i = 1; i <= n; ++ i) b[i] = a[i] - a[i-1];
	ll g = 0;
	for (int i = 2; i <= n; ++ i) g = gcd(g,b[i]);
	while (m--) {
		ll x;
		scanf("%lld",&x);
		printf("%lld ",gcd(a[1] + x,g));
	} return 0;
}