#include <bits/stdc++.h>

const int maxn = 2e5 + 17;

using ll = long long;
int n,m,a[maxn],q,l,r;
std::map<int,int>phi;

int qpow(int a,int b,int mod) {
	if (b == 0) return 1;
	ll d = qpow(a,b>>1,mod); d = d * d % mod;
	if (b & 1) d = d * a % mod;
	return d;
}

std::pair<int,int> query(int l,int r,int m) {
	if (l == r) return {a[l] % m,a[l] >= m};
	if (m == 1) return {0,1};
	int p = phi[m];
	auto q = query(l+1,r,p);
	int flag = 0;
	if (a[l] > 1) {
		if (a[l] >= m || (q.second)) flag = 1;
		ll x = 1;
		for (int i = 1; i <= q.first; ++ i) {
			x *= a[l];
			if (x >= m) { flag = 1; break; }
		}
	}
			
	return { qpow(a[l]%m,q.first + p * q.second,m), flag };
}

int main() {
	scanf("%d%d",&n,&m);
	int mod = m;
	for (int i = 1; i <= n; ++ i) scanf("%d",&a[i]);
	while (m != 1) {
		auto calc = [](int c) {
			int phi = c;
			for (int i = 2; i * i <= c; ++ i) {
				if (c % i == 0) {
					phi = phi / i * (i - 1);
					while (c % i == 0) c /= i;
				}
			} if (c != 1) phi = phi / c * (c - 1); 
			return phi;
		};
		phi[m] = calc(m);
		m = phi[m];
	}
	scanf("%d",&q);
	while (q--) {
		scanf("%d%d",&l,&r);
		printf("%d\n",query(l,r,mod).first);
	}
	return 0;
}