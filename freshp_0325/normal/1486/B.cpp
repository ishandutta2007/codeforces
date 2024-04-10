#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x[1005],y[1005],n;
int main(){
	LL T;
	scanf("%lld",&T);
	while(T-->0)
	{
		scanf("%lld",&n);
		for(LL i=1;i<=n;++i)	scanf("%lld %lld",&x[i],&y[i]);
		if(n&1)
		{
			puts("1");
			continue;
		}
		sort(x+1,x+1+n),sort(y+1,y+1+n);
		LL sx=x[n/2+1]-x[n/2]+1,sy=y[n/2+1]-y[n/2]+1;
		printf("%lld\n",sx*sy);
	}
	return 0;
}