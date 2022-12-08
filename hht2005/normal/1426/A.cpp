#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n,x;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&x);
		if(n<=2)puts("1");
		else printf("%d\n",(n-3)/x+2);
	}
	return 0;
}