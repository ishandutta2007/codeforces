#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, n;
	
ll check(int l, int r, int m) {	
	return max((((a + (l-1)*b + a + (r-1)*b)*(r-l+1))/2 - 1)/m + 1, a+(r-1)*b);
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &n);
	while(n--) {
		ll left, t, m;
		scanf("%lld %lld %lld", &left, &t, &m);
		ll l = left, r = left+t;
		ll best = -1;
		while(l < r - 1) {
			ll meio = (l+r)/2;
			//printf("Com L = %d  e R = %d  o meio  = %d\n", l, r, meio);
			if(check(left, meio, m) <= t) {
				best = max(best, meio);
				l = meio + 1;
			} else {
				r = meio - 1;
			}
		}
		if(check(left, l, m) <= t) {
			best = max(best, l);
		} 
		if(r >= left && check(left, r, m) <= t) {
			best = max(best, r);
		}
		printf("%lld\n", best);
	}
}