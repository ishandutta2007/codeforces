#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,k,x,y;
bool used[200005];
vector<int> g[200005];
int d1[200005],d2[200005];
queue<int> q;
void bfs()
{
	d1[1]=0;
	queue<int>q;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto to:g[x])
		{
			if(d1[to]>d1[x]+1)
			{
				d1[to]=d1[x]+1;q.push(to);
			}
		}
	}
}
void bfs2()
{
	d2[n]=0;q.push(n);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto to:g[x])
		{
			if(d2[to]>d2[x]+1)
			{
				d2[to]=d2[x]+1;q.push(to);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		used[x]=1;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i=1;i<=n;i++) d1[i]=1e9;
	bfs();
	for (int i=1;i<=n;i++) d2[i]=1e9;
	bfs2();
	vector<pair<int,int> >v1;
	set<pair<int,int> >v2;
	for(int i=1;i<=n;i++){
		if(used[i])
		{
			v1.push_back(make_pair(d1[i],i));
			v2.insert(make_pair(d2[i],i));
		}
	}
	sort(v1.begin(),v1.end());
	int ans=0;
	for(int i=0;i<v1.size();i++)
	{
		auto iter=v2.rbegin();
		while (iter!=v2.rend() && iter->second==v1[i].second) iter++;
		if(iter==v2.rend()) continue;
		x=v1[i].second,y=iter->second;
		ans=max(ans,min(d1[x]+d2[y],d1[y]+d2[x])+1);
		v2.erase(v2.find(make_pair(d2[x],x)));
	}
	ans=min(ans,d1[n]);
	printf("%d\n",ans);
	return 0;
}