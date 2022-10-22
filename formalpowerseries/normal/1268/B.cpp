#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n;
	scanf("%lld",&n);
	LL a=0,b=0;
	for(LL i=1;i<=n;++i)
	{
		LL x;
		scanf("%lld",&x);
		LL st1=x/2,st2=x-st1;
		if(i&1)	swap(st1,st2);
		a+=st1,b+=st2;
	}
	printf("%lld",min(a,b));
	return 0;
}