#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

vector<int> v[200010],g[200010];

priority_queue<pii,vector<pii>,greater<pii> > q;

int dis[200010];
int num[200010],n,m,k,vs,vt;
bool bo[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void dijkstra()
{
	for (int i=1;i<=n;i++) dis[i]=n+1;
	dis[vt]=0;q.push(pii(dis[vt],vt));
	while (!q.empty())
	{
		pii hh=q.top();q.pop();
		int x=hh.second;
		if (dis[x]<hh.first) continue;
		for (int t:v[x])
		{
			if (dis[t]>dis[x]+1) dis[t]=dis[x]+1,q.push(pii(dis[t],t));
		}
	}
}

int mx[200010],mn[200010];

int main()
{
	n=rd();m=rd();
	for (int i=1;i<=m;i++)
	{
		int x=rd(),y=rd();
		v[y].push_back(x);
		g[x].push_back(y);
	}
	k=rd();
	for (int i=1;i<=k;i++) num[i]=rd();
	vs=num[1];vt=num[k];
	dijkstra();
	int s1=0,s2=0;
	for (int i=1;i<k;i++)
	{
		int x=num[i],mn=n+1;
		for (int t:g[x]) if (t!=num[i+1]) mn=min(mn,dis[t]+1);
		if (dis[num[i+1]]+1!=dis[x]) s1++;
		if (mn<=dis[num[i+1]]+1) s2++;
	}
	printf("%d %d\n",s1,s2);
	return 0;
}