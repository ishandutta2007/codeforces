
#include <bits/stdc++.h>

using namespace std;

int n, a[400040], ans, tmp;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i+n] = a[i];
	}
	for(int i = 0; i < 2*n; i++) {
		if(a[i] == 1) tmp++;
		else tmp = 0;
		ans = max(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}