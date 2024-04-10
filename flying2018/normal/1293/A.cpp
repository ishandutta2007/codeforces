#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
set<long long>s;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		s.clear();
		long long n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		for(int i=1;i<=k;i++)
		{
			long long a;
			scanf("%lld",&a);
			s.insert(a);
		}
		int ans=0;
		for(;;ans++)
		{
			if(m+ans<=n && !s.count(m+ans)) break;
			if(m-ans>=1 && !s.count(m-ans)) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}