#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int maxn=200000;
int n,a[222222],x,y,dist[222222],ans;
int gcd(int a,int b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
vector<pair<int,int> > g[222222];
vector<int> gg[222222],v,ap;
bool used[222222],prime[222222];
pair<int,int> bfs(int s)
{
	ap.clear();
	queue<int> q;
	q.push(s);dist[s]=0;
	while(!q.empty())
	{
		int x=q.front();ap.push_back(x);
		q.pop();
		for (int j=0;j<gg[x].size();j++)
		{
			int to=gg[x][j];
			if (!~dist[to])
			{
				dist[to]=dist[x]+1;
				q.push(to); 
			}
		} 
	} 
	int mxi=s,mx=0;
	for (int i=0;i<ap.size();i++)
	{
		if (dist[ap[i]]>dist[mxi]) 
		{
			mxi=ap[i];
			mx=dist[mxi];
		}
		used[ap[i]]=1;
		dist[ap[i]]=-1;
	}
	return make_pair(mxi,mx);
}
int main()
{
	scanf("%d",&n);
	bool f=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]-1) f=1;
	}
	if (!f)
	{
		printf("0\n");
		return 0;
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[gcd(a[x],a[y])].push_back(make_pair(x,y)); 
	}
	memset(dist,-1,sizeof(dist));
	ans=1;
	for (int i=2;i<=maxn;i++)
	{
		if (!prime[i])
		{
			for (int j=i+i;j<=maxn;j+=i) prime[j]=1;
		}
	}
	for (int i=2;i<=maxn;i++)
	{
		if (!prime[i])
		{
			v.clear();
			for (int j=i;j<=maxn;j+=i)
			{
				for (int k=0;k<g[j].size();k++)
				{
					gg[g[j][k].first].push_back(g[j][k].second);
					gg[g[j][k].second].push_back(g[j][k].first);  
					v.push_back(g[j][k].first);
					v.push_back(g[j][k].second);  
				}
			}
			for (int j=0;j<v.size();j++)
			{
				if (!used[v[j]])
				{
					int x=bfs(v[j]).first;
					int y=bfs(x).second;
					ans=max(ans,y+1);
				}
			}
			for (int j=0;j<v.size();j++)
			{
				used[v[j]]=0;
				gg[v[j]].clear();
			}
		}
		
	}
	printf("%d\n",ans);
	return Accepted;
}