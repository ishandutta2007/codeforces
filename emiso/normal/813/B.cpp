#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x, y, l, r;

set<ll> xs, ys, tot;

int main() {
	scanf("%lld %lld %lld %lld", &x, &y, &l, &r);
	
	ll xt = 1;
	while(r / xt >= x) {
		xs.insert(xt);
		xt *= x;
	}
	
	xs.insert(xt);
	
	ll yt = 1;
	while(r / yt >= y) {
		ys.insert(yt);
		yt *= y;
	}
	
	ys.insert(yt);
	
	for(auto X : xs) {
		for(auto Y : ys) {
			if(X + Y <= r && X + Y >= l) tot.insert(X + Y);
		}
	}
	
	ll best = 0;
	ll before = l - 1;
	tot.insert(r + 1);
	for(auto Z : tot) {
		best = max(Z - before - 1, best);
		before = Z;
	}
	
	cout << best;
	
	return 0;
}