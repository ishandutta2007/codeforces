#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[100005],n,t;
int main(){
	scanf("%lld",&t);
	while(t-->0)
	{
		scanf("%lld",&n);
		LL sum=0,maxn=0;
		for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]),sum+=a[i],maxn=max(a[i],maxn);
		LL ans=max(((n-1)-sum%(n-1))%(n-1),maxn*(n-1)-sum);
		printf("%lld\n",ans);
	}
	return 0;
}