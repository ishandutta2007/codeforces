#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	int ans=999999999;
	for(int i=0; i <= 1000; ++i){
		int left = n-m*i;
		if(left < 0)
			left=0;
		int cost = i*b+left*a;
		ans=min(cost, ans);
	}
	printf("%d\n", ans);
}