#include <bits/stdc++.h>

using ll = long long;
int a[100];

int fillto(ll x) {
	if (x < 10) {
		a[1] = x;
		return 1;
	} int d = fillto(x / 10);
	a[d + 1] = x % 10;
	return d + 1;
}

void solve() {

	ll x; int lim;
	scanf("%lld%d",&x,&lim); x --;
	int len = fillto(x);
	ll ans = 1e18;
	ll a1 = 1, a2 = 1;
	for (int i = 1; i <= len; ++ i) {
		a1 *= 10ll;
		a2 = a2 * 10 + 1;
	} ans = a2;
	if (lim > 1) ans = std::min(ans,a1);
	for (int i = 1; i <= len; ++ i) {
		for (int j = a[i] + 1; j < 10; ++ j) {
			for (int k = 0; k < 10; ++ k) {
				int vis[10] = {0};
				ll val = 0;
				for (int l = 1; l < i; ++ l) val = val * 10 + a[l];
				val = val * 10 + j; 
				for (int l = i + 1; l <= len; ++ l) val = val * 10 + k;
				for (int l = 1; l < i; ++ l) vis[a[l]] = 1;
				vis[j] = vis[k] = 1;
				if (std::accumulate(vis,vis + 10,0) <= lim)
					ans = std::min(ans,val);
			}
		}
	} printf("%lld\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}