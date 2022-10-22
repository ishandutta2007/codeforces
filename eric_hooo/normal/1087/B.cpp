#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int p;
	for (p = k - 1; p >= 1; p--){
		if (n % p == 0) break;
	}
	printf("%d\n", n / p * k + p);
	return 0;
}