#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	long long p,a,b,c;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		if(p%a==0||p%b==0||p%c==0)puts("0");
		else printf("%lld\n",min((p/a+1)*a,min((p/b+1)*b,(p/c+1)*c))-p);
	}
	return 0;
}