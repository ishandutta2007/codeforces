#include <bits/stdc++.h>

int main(){
	int t;scanf("%d",&t);while(t--){
		int  n,x,a,b;
		scanf("%d%d%d%d",&n,&x,&a,&b);
		printf("%d\n",std::min(n-1,abs(b-a)+x));
	}return 0;
}