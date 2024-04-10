
#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
	scanf("%d %d", &n, &m);
	if(m % n) {
		puts("-1");
		return 0;
	}
	int x = m / n, ans = 0;
	while(x > 1) {
		if(x % 2 == 0) {
			x /= 2;
			ans++;
		} 
		else if(x % 3 == 0) {
			x /= 3;
			ans++;
		}
		else {
			puts("-1");
			return 0;
		}
			
	}
	
	printf("%d\n", ans);
	return 0;
}