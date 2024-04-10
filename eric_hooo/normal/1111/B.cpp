#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	long long sum = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + n);
	long long now = 0;
	double ans = -1e18;
	for (int i = 0; i < n; i++){
		if (i > m) break;
		ans = max(ans, 1.0 * (sum - now + min(1ll * k * (n - i), 1ll * m - i)) / (n - i));
		now += a[i];
	}
	printf("%.15lf\n", ans);
	return 0;
}