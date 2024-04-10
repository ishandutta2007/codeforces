#include <cstdio>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
 
typedef long long LL;
 
LL k, l, r, t, x, y;
 
LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}
 
set<LL> st;
 
int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &k, &l, &r, &t, &x, &y);
	if (x == y) {
		if (k + x <= r || k - x >= l) puts("Yes");
		else puts("No");
	} else if (x > y) {
		if (k + y <= r) k += y;
		k -= x;
		t--;
		if (k - (long double)t * (x - y) < l) puts("No");
		else puts("Yes");
	} else {
		st.insert(k);
		for (int i = 1; ; i++) {
			LL z = max(0ll, (LL)(ceil(((long double)k - r + y) / x)));
			if (t <= z) {
				if (k - t * x < l) {
					puts("No"); return 0;
				} else {
					puts("Yes"); return 0;
				}
			}
			t -= z + 1;
			if (k - z * x < l) {
				puts("No"); return 0;
			} 
			
			
			if (t <= 0) {
				puts("Yes"); return 0;
			}
			k += y - z * x - x;
			
			
			if (k - x >= l && k - x + y <= r) {
				puts("Yes"); return 0;
			}
			
			if (st.count(k)) {
				puts("Yes"); return 0;
			}
			st.insert(k);
		}
	}
	
	return 0;
}