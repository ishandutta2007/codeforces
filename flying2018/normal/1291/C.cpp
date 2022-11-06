#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 3510
using namespace std;
ll num[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		ll maxn=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			if(i<m || n-i-1<m)maxn=max(maxn,num[i]);
		}
		ll ans=0;
		for(int a=0;a<=k;a++)
		{
			ll res=maxn;
			for(int i=0;i<m-k;i++)
			res=min(res,max(num[a+i],num[a+i+n-m]));
			ans=max(ans,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}