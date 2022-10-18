#include <bits/stdc++.h>

using ll = long long;

#define maxn 1000005

ll n,w[maxn],s[maxn],ans;
int q[maxn],m;

ll calc(ll x) {
	if (x & 1) return x * (x - 1) / 2 + 1;
	else return x * (x - 1) / 2 + x / 2;
}

int main() {
	scanf("%lld%d",&n,&m);
	for (int i = 1; i <= m; ++ i) scanf("%d%lld",&q[i],&w[i]);
	std::sort(w+1,w+m+1,[](ll a ,ll b) { return a > b; });
	for (int i = 1; i <= m; ++ i) s[i] = s[i-1] + w[i];
	for (int i = 1; i <= m; ++ i) if (calc(i) <= n) ans = s[i];
	printf("%lld",ans);
	return 0;
}