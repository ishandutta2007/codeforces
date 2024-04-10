#include <bits/stdc++.h>
using namespace std;

int a[300010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	long long ans = 0;
	for (int i = 0; i < n / 2; i++){
		ans += 1ll * (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
	}
	printf("%I64d\n", ans);
	return 0;
}