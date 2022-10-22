#include <bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int x;
		scanf("%d", &x);
		int res = 0;
		while (x % 2 != 0) x -= 3, res++;
		res += x / 2;
		printf("%d\n", res);
	} 
	return 0;
}