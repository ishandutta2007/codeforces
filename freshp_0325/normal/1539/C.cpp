#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200005],n,k,x;
int main(){
	scanf("%lld %lld %lld",&n,&k,&x);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	LL ans=n;
	priority_queue<LL,vector<LL>,greater<LL>> Q;
	for(LL i=2;i<=n;++i)	Q.push(max(0ll,(a[i]-a[i-1]-1)/x));
	while(!Q.empty())
	{
		if(k<Q.top())	break;
		k-=Q.top();
		Q.pop();
		--ans;
	}
	printf("%lld",ans);
	return 0;
}