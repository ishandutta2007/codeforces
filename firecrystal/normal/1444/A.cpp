#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

LL p;

int q;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%lld%d", &p, &q);
		if (p % q) printf("%lld\n", p);
		else {
			LL v = 0;
			int b = q;
			for (int i = 2; i * i <= b; i++) {
				if (b % i == 0) {
					while (b % i == 0) b /= i;
					LL k = p;
					while (k % q == 0) k /= i;
					v = max(v, k);
				}
			}
			if (b > 1) {
				LL k = p;
				while (k % q == 0) k /= b;
				v = max(v, k);
			}
			printf("%lld\n", v);
		}
	}	
	return 0;
}