#include <bits/stdc++.h>
using namespace std;

long long v[100010], t[100010];
long long sum[100010];
long long times[100010];
long long a[100010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%I64d", &v[i]);
	}
	for (int i = 1; i <= n; i++){
		scanf("%I64d", &t[i]);
		sum[i] = sum[i - 1] + t[i];
	}
	for (int i = 1; i <= n; i++){
		int pos = upper_bound(sum + i, sum + n + 1, v[i] + sum[i - 1]) - sum;
		times[i]++, times[pos]--;
		a[pos] += v[i] + sum[i - 1] - sum[pos - 1];
	}
	for (int i = 1; i <= n; i++){
		times[i] += times[i - 1];
		printf("%I64d ", times[i] * t[i] + a[i]);
	}
	printf("\n");
	return 0;
}