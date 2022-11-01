#include <bits/stdc++.h>

using namespace std;

int n, a[500050];
long long sum, ans, goal, cur, co;



int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	
	if(n < 3 || sum % 3) {
		printf("0\n");
		return 0;
	}
	
	goal = sum / 3;
	
	for(int i = 0; i + 1 < n; i++) {
		sum -= a[i];
		if(sum == goal) ans += co;
		cur += a[i];
		if(cur == goal) co++;
	}
	
	printf("%lld\n", ans);
	return 0;
}