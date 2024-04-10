#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
map<ll,int>p;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		p.clear();
		ll ans=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			ll a;
			int cnt=0;
			scanf("%lld",&a);
			while(a%2==0) a>>=1,cnt++;
			int u=p[a];
			if(u<cnt) p[a]=cnt,ans+=cnt-u;
		}
		printf("%lld\n",ans);
	}
	return 0;
}