#include <bits/stdc++.h>

#define maxn 1000005

using ll = long long;
int n,m,k,u[maxn],v[maxn],w[maxn],rk[maxn];

namespace dsu {
	int fa[maxn];
	void reset() { std::memset(fa,0,sizeof(fa)); }
	int getf(int x) { return fa[x] ? fa[x] = getf(fa[x]) : x; }
	int merge(int x,int y) {
		x = getf(x), y = getf(y);
		if (x == y) return 0;
		fa[x] = y;
		return 1;
	}
}

void solve() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= m; ++ i) {
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		rk[i] = i;
	} std::sort(rk+1,rk+m+1,[](int a,int b) { return w[a] < w[b]; });
	dsu::reset();
	ll ans = 0;
	int flag = 0;
	for (int j = 1; j <= m; ++ j) {
		int i = rk[j];
		if (dsu::merge(u[i],v[i])) {
			if (w[i] >= k) {
				flag = 1;
				ans += w[i] - k;
			}
		}
	} if (flag) { printf("%lld\n",ans); return ; }
	else {
		ans = 1e9 + 7;
		for (int i = 1; i <= m; ++ i) ans = std::min(ans,(ll) std::abs(w[i] - k));
		printf("%lld\n",ans);
	}
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}