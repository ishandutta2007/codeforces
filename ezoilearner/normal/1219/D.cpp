#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n,k,x[MAXN],a,c[MAXN];
long long ans;
priority_queue<int,vector<int>,greater<int> > pq;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",x+i);
	scanf("%d",&a);
	for(int i=1;i<=n;++i)scanf("%d",c+i);
	for(int i=1;i<=n;++i)
	{
		pq.push(c[i]);
		while(k<x[i] && !pq.empty())
		{
			ans+=pq.top();pq.pop();
			k+=a;
		}
		if(k<x[i])
		{
			puts("-1");
			return 0;
		}
	}
	printf("%lld\n",ans);
}