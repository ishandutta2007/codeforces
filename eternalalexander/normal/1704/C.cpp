#include <bits/stdc++.h>

using ll = long long;
const int maxn = 1e6 + 222;
int m;
ll n,a[maxn];


void solve() {
	scanf("%lld%d",&n,&m);
	for (int i = 1; i <= m; ++ i) scanf("%lld",&a[i]);
	std::sort(a + 1,a + m + 1);
	std::priority_queue<ll>q;
	for (int i = 1; i < m; ++ i) q.push(a[i+1] - a[i] - 1);
//	printf("<%lld>\n",n - a[m] + a[1] - 1);
	q.push(n - a[m] + a[1] - 1);
	ll det = 0;
	ll vis1 = 0;
	ll ans = 0;
	while (vis1 || (!q.empty())) {
		if (!vis1) {
			ll u = q.top(); q.pop();
			if (u - det <= 0) { det += 2; continue; }
			ans += 1;
			ll len = u - det - 1;
			
		//	printf("len = %lld\n",len);
			if (len <= 1) { det += 2; continue; }
			vis1 = len;
			vis1 --;
		} else {
			ans += vis1;
			vis1 = 0;
		} det += 2;
	} printf("%lld\n",n - ans);
		
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}