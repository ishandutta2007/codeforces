#include <bits/stdc++.h>
using namespace std;
int main(){
	__int64 n, m;
	while (scanf("%I64d%I64d", &n, &m) != EOF){
		__int64 ans = 0;
		__int64 b = 1;
		for (__int64 i = 1; i <= m; i++){
			__int64 a;
			scanf("%I64d", &a);
			if (a >= b) ans = ans + a - b;
			else ans = ans + a + n - b;
			b = a;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}