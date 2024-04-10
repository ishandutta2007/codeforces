#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,k,sum[105],a[105];
int main(){
	LL T;
	cin>>T;
	while(T-->0)
	{
		scanf("%d %d",&n,&k);
		for(LL i=1;i<=n;++i)	cin>>a[i];
		for(LL i=1;i<=n;++i)	sum[i]=sum[i-1]+a[i];
		LL ans=0;
		for(LL i=2;i<=n;++i)	if(a[i]*100>sum[i-1]*k)	ans=max(ans,(a[i]*100+k-1)/k-sum[i-1]);
		cout<<ans<<endl;
	}
	return 0;
}