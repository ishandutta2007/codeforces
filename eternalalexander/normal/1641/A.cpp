#include <bits/stdc++.h>

using ll = long long;
int n;
ll x;

void solve() {
	scanf("%d%lld",&n,&x);
	std::multiset<ll>S;
	for (int i = 1; i <= n; ++ i) {
		ll a;scanf("%lld",&a);
		S.insert(a);
	} 
	int c = 0;
	while (!S.empty()) {
		int u = *S.begin();
		S.erase(S.find(u));
		if (S.find(x * u) == S.end()) c ++;
		else S.erase(S.find(x * u));
	} printf("%d\n",c);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}