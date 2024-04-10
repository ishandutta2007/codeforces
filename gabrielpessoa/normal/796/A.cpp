#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k, d, a;
	scanf("%d %d %d", &n, &m, &k);
	d = n;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if(a != 0 && a <= k) {
			d = min(abs(i - m), d);
		}
	}
	printf("%d", d * 10);
	return 0;
}