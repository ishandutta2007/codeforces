#include <bits/stdc++.h>

using ll = long long;
int n,a,v[10005];
ll d[1000005],ans;
char s[10005];

int main() {
	scanf("%d",&a);
	scanf("%s",s+1); n = std::strlen(s+1);
	int lim = n * 10;
	for (int i = 1; i <= n; ++ i) v[i] = v[i-1] + s[i] - '0'; 
	for (int l = 1; l <= n; ++ l)
	for (int r = l; r <= n; ++ r) {
		d[v[r] - v[l-1]] ++;
	}
	if (a == 0) {
		ans = d[0] * (ll) n * (n+1) - d[0] * d[0];
	}
	else {
		for (int i = 1; i * i <= a; ++ i) {
			if (a % i) continue;
			int j = a / i;
			if (i <= lim && j <= lim) 
				ans += d[i] * d[j] * (1 + (i != j));
		}
	} printf("%lld",ans);
	return 0;
}