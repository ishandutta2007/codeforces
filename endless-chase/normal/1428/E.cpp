#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int test,n,k,cur[111111],a[111111],id;
long long ans;
priority_queue<pair<long long,int> > pq;
long long calc(int x,int k)
{
	return 1ll*(x/k)*(x/k)*(k-(x%k))+1ll*(x/k+1)*(x/k+1)*(x%k);
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cur[i]=1;
	}
	for (int i=1;i<=n;i++) pq.push(make_pair(calc(a[i],1)-calc(a[i],2),i));
	for (int i=n;i<k;i++)
	{
		id=pq.top().second;
		pq.pop();
		cur[id]++;
		pq.push(make_pair(calc(a[id],cur[id])-calc(a[id],cur[id]+1),id));
	}
	for (int i=1;i<=n;i++) ans+=calc(a[i],cur[i]);
	printf("%lld\n",ans);
	return Accepted;
}