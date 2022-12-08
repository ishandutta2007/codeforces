#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,x,y,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d%d",&x,&y,&a,&b);
		if(x>y)swap(x,y);
		if(a*2<=b)printf("%lld\n",1ll*(x+y)*a);
		else printf("%lld\n",1ll*x*b+1ll*(y-x)*a);
	}
	return 0;
}