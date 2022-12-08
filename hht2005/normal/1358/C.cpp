#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,a,b,c,d;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%lld\n",1ll*(c-a)*(d-b)+1);
	}
	return 0;
}