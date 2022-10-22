#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	long long res = 0x3f3f3f3f;
	for (long long i = 1; i * i <= n; i++){
		res = min(res, i + n / i + (n % i != 0));
	}
	printf("%I64d\n", res);
	return 0;
}