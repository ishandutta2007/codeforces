#include <bits/stdc++.h>

int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		if(n%i==0){
			printf("%d%d\n",i,n/i);
			return 0;
		}
	}
	return 0;
}