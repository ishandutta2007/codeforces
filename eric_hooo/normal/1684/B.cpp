#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		long long a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
		long long x = a + b + c, y = b + c, z = c;
		printf("%lld %lld %lld\n", x, y, z);
	}
	return 0;
}