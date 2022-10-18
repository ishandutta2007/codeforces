#include <bits/stdc++.h>

// 17(64)

using ll = long long;
const int maxn = 3e4 + 17;

const ll inf = 1e18;
ll f[maxn],a1[maxn],a2[maxn],a3[maxn],a4[maxn];
int n,qr,x,y,w[maxn],h[maxn],ban[maxn],p[maxn],q[maxn];

inline ll mymax(ll a, ll b) { return a > b ? a : b; }

int main() {
	scanf("%d%d",&n,&qr);
	for (int i = 1; i <= n; ++ i) { scanf("%d",&w[i]); p[i] = i; }
	for (int i = 1; i <= n; ++ i) { scanf("%d",&h[i]); q[i] = i; }
	std::sort(p+1,p+n+1,[](int a,int b) { return w[a] < w[b]; });
	std::sort(q+1,q+n+1,[](int a,int b) { return h[a] < h[b]; });
	for (int i = 1; i <= n; ++ i) ban[i] = i;
	#define match(x,y) (ll) w[p[x]] * h[q[y]]
	for (int i = 1; i <= n; ++ i) {
		a1[i] = (ll) w[p[i]] * h[q[i]];
		if (i > 1) a2[i] = match(i-1,i) + match(i,i-1);
		if (i > 2) a3[i] = match(i-2,i) + match(i-1,i-2) + match(i,i-1);
		if (i > 2) a4[i] = match(i-2,i-1) + match(i-1,i) + match(i,i-2);
	};
	auto calc = [&]() {
		f[0] = 0;
		for (register int i = 1; i <= n; ++ i) {
			f[i] = -inf;
			if (ban[p[i]] != q[i]) f[i] = mymax(f[i],f[i-1] + a1[i]);
			if (i > 1 && ban[p[i-1]] != q[i] && ban[p[i]] != q[i-1]) 
				f[i] = mymax(f[i],f[i-2] + a2[i]);
			if (i > 2 && ban[p[i-2]] != q[i] && ban[p[i-1]] != q[i-2] && 
				ban[p[i]] != q[i-1])
				f[i] = mymax(f[i],f[i-3] + a3[i]);
			if (i > 2 && ban[p[i-2]] != q[i-1] && ban[p[i-1]] != q[i] && 
				ban[p[i]] != q[i-2])
				f[i] = mymax(f[i],f[i-3] + a4[i]);
		}
	};
	while (qr--) {
		scanf("%d%d",&x,&y);
		std::swap(ban[x],ban[y]);
		calc();
		printf("%lld\n",f[n]);
	}
	return 0;
}