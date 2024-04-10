#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
using ll = long long;
int n,m,x;
ll a[maxn],ans[2];
std::vector<ll>vec[maxn];

void solve() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++ i) scanf("%lld",&a[i]);
	int g = 0;
	for (int i = 1; i <= m; ++ i) {
		scanf("%d",&x);
		g = std::__gcd(g,x);
	}
	ans[0] = ans[1] = 0;
	for (int i = 0; i < g; ++ i) vec[i].clear();
	for (int i = 1; i <= n; ++ i) vec[i % g].push_back(a[i]);
	for (int i = 0; i < g; ++ i) {
		ll c[2];
		c[0] = c[1] = -1e9;
		std::sort(vec[i].begin(),vec[i].end());
		int s = vec[i].size();
		ll sum = 0, sum1 = 0;
		for (int j = 0; j < s; ++ j) sum += vec[i][j];
		c[0] = std::max(c[0],sum);
		for (int j = 0; j < s; ++ j) {
			sum -= vec[i][j] * 2;
			c[(j + 1) % 2] = std::max(c[(j + 1) % 2],sum);
		}
		ans[0] += c[0];
		ans[1] += c[1];
	}
	printf("%lld\n",std::max(ans[0],ans[1]));
}
		

int main() {
	int t;scanf("%d",&t);while (t--)solve();
	return 0;
}