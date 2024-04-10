#include<bits/stdc++.h>
using namespace std;
int main(){
	int w, h, k, ans = 0;
	scanf("%d %d %d", &w, &h, &k); 
	while(k -- ){
		ans += (w + h) * 2 - 4;
		w -= 4;
		h -= 4;
	} 
	printf("%d", ans);
}