#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		long long k; int x;
		scanf("%I64d%d", &k, &x);
		printf("%I64d\n", (k - 1) * 9 + x);
	}
	return 0;
}