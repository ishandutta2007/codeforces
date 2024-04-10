#include <bits/stdc++.h>
using namespace std;
int main(){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int res = 0;
	for (int i = 1; i <= 100; i++){
		if (i <= a && i + 1 <= b && i + 2 <= c) res = max(res, i + i + 1 + i + 2);
	} 
	printf("%d\n", res);
	return 0;
}