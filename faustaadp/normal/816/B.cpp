#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,q,i,j,xt,yt,a[2000010],hs,ps[2000010],c[2000010],d[2000010],v;
int main()
{
	//cin>>n>>k>>q;
	scanf("%I64d %I64d %I64d",&n,&k,&q);
	for(i=1;i<=n;i++)
	{
		//cin>>xt>>yt;
		scanf("%I64d %I64d",&xt,&yt);
		c[xt]++;
		d[yt]++;
	}
	for(i=1;i<=200000;i++)
	{
		v=v+c[i];
		a[i]=v;
		v=v-d[i];
	}
	for(i=1;i<=200000;i++)
	{
		ps[i]=ps[i-1];
		if(a[i]>=k)
			ps[i]++;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%I64d %I64d",&xt,&yt);
		hs=ps[yt]-ps[xt-1];
		printf("%I64d\n",hs);
	}
}