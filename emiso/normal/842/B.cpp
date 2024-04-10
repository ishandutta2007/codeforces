#include <bits/stdc++.h>

using namespace std;

int n, r, d, x[100550], y[100550], rs[100550], ans;

int main() {
	scanf("%d %d %d", &r, &d, &n);
	
	for(int i = 0; i < n; i++) {
		
		scanf("%d %d %d", &x[i], &y[i], &rs[i]);
		int dist = x[i]*x[i] + y[i]*y[i];
		
		if(rs[i] > r) continue;
		
		if(dist >= (r - d + rs[i])*(r - d + rs[i])
			&& dist <= (r - rs[i]) * (r - rs[i]))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}