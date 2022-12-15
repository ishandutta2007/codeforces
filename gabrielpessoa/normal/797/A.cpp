#include <bits/stdc++.h>
using namespace std;

int find(int n) {
	for(int i = 2; i <= n; i++) {
		if(n % i == 0) return i;
	}
	return 1;
}
int main() {
	int n, k, q = 0, dum;
	int d[25];
	scanf("%d %d", &n, &k);
	while(q < k - 1) {
		dum = find(n);
		if(dum == n) {
			break;
		}
		d[q++] = dum;
		n = n/dum;
	}
	d[q++] = n;
	if(q < k) {
		printf("-1");
	} else {
		for(int i = 0; i < k; i++) {
			printf("%d ", d[i]);
		}
	}
	return 0;
}