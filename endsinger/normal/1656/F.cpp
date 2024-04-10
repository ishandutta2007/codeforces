#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const long long inf=9e18;
int n,v[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		long long x=0,y=0,s=-inf;
		sort(v+1,v+n+1);
		for(int i=2;i<=n;i++)
		{
			x+=v[i]+v[1];
			y+=1ll*v[i]*v[1];
		}
		for(int i=1;i<n;i++)
		{
			if(i!=1)
			{
				x+=v[i]+v[n];
				y+=1ll*v[i]*v[n];
				x-=v[i]+v[1];
				y-=1ll*v[i]*v[1];
			}
			if((x>0&&i==1)||(x<0&&i==n-1))
			{
				s=inf;
				break;
			}
			s=max(s,y-x*max(v[i],v[i+1]));
		}
		if(s!=inf)
			printf("%lld\n",s);
		else
			puts("INF");
	}
	return 0;
}