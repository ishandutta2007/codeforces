#include <bits/stdc++.h>
using namespace std;

int a[100010];
long long sum[200010];

int main(){
	int n, t; scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		int pos = upper_bound(sum + i, sum + n + 1, sum[i - 1] + t) - sum - 1;
		ans = max(ans, pos - i + 1);
	}
	printf("%d\n", ans);
	return 0;
}