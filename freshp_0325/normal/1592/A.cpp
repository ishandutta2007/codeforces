#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL T,a[1005],k,n;
int main(){
	scanf("%lld",&T);
	while(T-->0)
	{
		scanf("%lld %lld",&n,&k);
		for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
		sort(a+1,a+1+n,greater<LL>());
		LL st=k/(a[1]+a[2]);
		k-=st*(a[1]+a[2]);
		st*=2;
		if(k>0)	k-=a[1],++st;
		if(k>0)	k-=a[2],++st;
		printf("%lld\n",st);
	}
	return 0;
}