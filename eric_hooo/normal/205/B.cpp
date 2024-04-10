#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for (int i = 1; i < n; i++){
		ans += a[i - 1] - a[i] >= 0 ? a[i - 1] - a[i] : 0;
	}
	printf("%I64d\n", ans);
	return 0;
}