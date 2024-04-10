#include <bits/stdc++.h>

using namespace std;

int n;
double a[110], p0, p1, best;

int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i++) {
		scanf("%lf", &a[i]);
	}
	
	sort(a + 1, a + n + 1, greater<double>());
	p0 = 1;
	
	for(int i=0; i<=n; i++) {
		p1 = p0 * a[i] + p1 * (1 - a[i]);
		p0 *= (1 - a[i]);
		
		best = max(best, p1);
		if(p1 > p0) break;
	}
 	
	printf("%.12f\n", best);
	
	return 0;
}