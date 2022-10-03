#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

vector<int> v[200010];

pii h[200010];

int num[200010],d[200010],n,m,vs;
bool inq[200010],vis[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

queue<int> q;

inline ll dfs(int x)
{
	ll res=0;vis[x]=true;
	for (int t:v[x]) if (!vis[t]) res=max(res,dfs(t));
	return res+num[x];
}

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=n;i++) num[i]=rd();
	for (int i=1;i<=m;i++) h[i].first=rd(),h[i].second=rd();
	for (int i=1;i<=m;i++)
	{
		v[h[i].first].push_back(h[i].second);
		v[h[i].second].push_back(h[i].first);
	}
	vs=rd();
	for (int i=1;i<=m;i++) d[h[i].first]++,d[h[i].second]++;
	for (int i=1;i<=n;i++) if (d[i]==1&&i!=vs) inq[i]=true,q.push(i);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int t:v[x]) if (!inq[t]&&t!=vs)
		{
			d[t]--;
			if (d[t]==1) inq[t]=true,q.push(t);
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++) if (!inq[i]) ans+=num[i],vis[i]=true;
	ll res=0;
	for (int i=1;i<=n;i++) if (!inq[i])
	{
		for (int t:v[i]) if (!vis[t]) res=max(res,dfs(t));
	}
	printf("%lld\n",ans+res);
	return 0;
}