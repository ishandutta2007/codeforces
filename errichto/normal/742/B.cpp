#include <bits/stdc++.h>
using namespace std;
int t[1<<17];
int main() {
	int n, x;
	scanf("%d%d", &n, &x);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		ans += t[a ^ x];
		t[a]++;
	}
	printf("%lld\n", ans);
}