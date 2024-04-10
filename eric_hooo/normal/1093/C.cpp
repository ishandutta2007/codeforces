#include <bits/stdc++.h>
using namespace std;

long long a[200010], b[100010];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n / 2; i++){
		scanf("%I64d", &b[i]);
	}
	long long ll = 1e18 + 10, rr = -1;
	for (int i = n / 2; i >= 1; i--){
		long long t = min(ll, b[i] / 2);
		t = min(t, b[i] - max(rr, (b[i] + 1) / 2));
		a[i] = t;
		a[n - i + 1] = b[i] - a[i];
		ll = a[i], rr = a[n - i + 1];
	}
	for (int i = 1; i <= n; i++){
		printf("%I64d ", a[i]);
	}
	printf("\n");
	return 0;
}