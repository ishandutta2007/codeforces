#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL suma[100005],sumb[100005],n,q,a[100005],b[100005],dlt[100005];
LL st[100005][19],st2[100005][19];
LL lgs[100005];
LL queryMin(LL l,LL r)
{
	LL k=lgs[r-l+1];
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
LL queryMax(LL l,LL r)
{
	LL k=lgs[r-l+1];
	return max(st2[l][k],st2[r-(1<<k)+1][k]);
}
int main(){
	for(LL i=2;i<=100000;++i)	lgs[i]=lgs[i>>1]+1;
	scanf("%lld %lld",&n,&q);
	for(LL i=1;i<=n;++i)	scanf("%lld",&a[i]),suma[i]=suma[i-1]+a[i];
	for(LL i=1;i<=n;++i)	scanf("%lld",&b[i]),sumb[i]=sumb[i-1]+b[i];
	for(LL i=1;i<=n;++i)	dlt[i]=sumb[i]-suma[i];
	for(LL i=1;i<=n;++i)	st[i][0]=st2[i][0]=dlt[i];
	for(LL j=1;j<=18;++j)	for(LL i=1;i+(1<<j)-1<=n;++i)	st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	for(LL j=1;j<=18;++j)	for(LL i=1;i+(1<<j)-1<=n;++i)	st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
	while(q-->0)
	{
		LL l,r;
		scanf("%lld %lld",&l,&r);
		LL p=dlt[l-1];
		LL tek=queryMin(l,r)-p;
		if(tek<0)
		{
			puts("-1");
			continue;
		}
		if(dlt[r]-dlt[l-1])
		{
			puts("-1");
			continue;
		}
		printf("%lld\n",queryMax(l,r)-p);
	}
	return 0;
}