#include<bits/stdc++.h>
using namespace std;
int main(){
	long long ans = 0;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i += 1){
		int x, d;
		scanf("%d %d", &x, &d);
		ans += x * n;
		if(d > 0) ans += 1LL * n * (n - 1) / 2 * d;
		else if(n & 1) ans += 1LL * (n + 1) / 2 * (n - 1) / 2 * d;
		else ans += 1LL * n / 2 * (n - 2) / 2 * d + 1LL * n / 2 * d;
	}
	printf("%lf", 1.0 * ans / n);
}