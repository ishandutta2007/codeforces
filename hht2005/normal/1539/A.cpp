#include<bits/stdc++.h>
using namespace std;
int main() {
	int T,n,x,t;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%d",&n,&x,&t);
		int tmp=t/x;
		if(tmp>=n-1)printf("%lld\n",1ll*n*(n-1)/2);
		else printf("%lld\n",1ll*n*tmp-1ll*tmp*(tmp+1)/2);
	}
}