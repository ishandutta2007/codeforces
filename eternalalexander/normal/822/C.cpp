#include <bits/stdc++.h>

#define maxn 1000005
using ll = long long;
ll inf = 1e17;
const int lim = 2e5;
int n,s,l[maxn],r[maxn],c[maxn];
ll ans = inf, min[maxn];
std::vector<int>inc[maxn],dec[maxn];

int main() {
	scanf("%d%d",&n,&s);
	for (int i = 1; i <= n; ++ i) {
		scanf("%d%d%d",&l[i],&r[i],&c[i]);
		inc[l[i]].push_back(i);
		dec[r[i]].push_back(i);
	} for (int i = 0; i <= s; ++ i) min[i] = 1e18;
	for (int i = 1; i <= lim; ++ i) {
		for (int x:inc[i]) {
			int len = r[x] - l[x] + 1;
			if (len > s) continue;
			ans = std::min(ans,  (ll) c[x] + min[s - len]);
		}
		for (int x:dec[i]) {
			int len = r[x] - l[x] + 1;
			min[len] = std::min(min[len],(ll) c[x]);
		}
	} if (ans < inf) printf("%lld",ans);
	else puts("-1");
	return 0;
}