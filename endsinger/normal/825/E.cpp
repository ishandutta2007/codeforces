#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int d[N],a[N],n,m;
vector<int>e[N];
priority_queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++;
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!d[i])
			q.push(i);
	for(int i=n;i>=1;i--)
	{
		int u=q.top();
		q.pop();
		a[u]=i;
		for(auto v:e[u])
		{
			d[v]--;
			if(!d[v])
				q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}