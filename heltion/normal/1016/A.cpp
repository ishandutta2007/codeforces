#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long m, p = 0;
	scanf("%d %lld", &n, &m);
	for(int i = 0; i < n; i += 1){
		long long a;
		scanf("%lld", &a);
		p += a;
		printf("%lld ", (p - p % m) / m);
		p %= m;
	}
}