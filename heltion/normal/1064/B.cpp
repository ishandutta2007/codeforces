#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		int a, r = 0;
		scanf("%d", &a);
		//for(int x = 0; x <= a; x += 1)
		//	if(a - (a ^ x) - x == 0)
		//		r += 1;
		printf("%d\n", 1 << __builtin_popcount(a));
	}
}