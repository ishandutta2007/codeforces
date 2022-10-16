#include <bits/stdc++.h>
using namespace std;
 
int n, m;

int main() {
	scanf("%d %d", &n, &m);

	if (m < n) swap(n,m);
	if (m <= 2) printf("0\n");
	else if (n == 1) {
		long long a = 6 * (m/6);
		m -= a;
		if (m == 4) a += 2;
		if (m == 5) a += 4;
		printf("%lld\n", a);
	}
	else if (n == 2 && m == 3) printf("4\n");
	else if (n == 2 && m == 7) printf("12\n");
	else {
		long long t = n*1ll*m - ((n*1ll*m)&1);
		printf("%lld\n", t);
	}

}