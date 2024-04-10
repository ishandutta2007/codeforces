#include<bits/stdc++.h>
using namespace std;
const int N=100005,mod=1e9+9;
map<pair<int,int>,int>a;
int n,x[N],y[N],ans[N],d[N],v[N],r;
vector<int>e[N],g[N];
int id(int u,int v)
{
	if(a.find(make_pair(u,v))==a.end())
		return -1;
	return a[make_pair(u,v)];
}
set<int>s;
void upd(int u)
{
	if(v[u])
		return;
	int fl=1;
	for(auto j:e[u])
		if(v[j]==0&&d[j]==1)
			fl=0;
	if(fl)
		s.insert(u);
	else
	{
		if(s.count(u))
			s.erase(u);
	}
}
void del(int u)
{
	v[u]=1;
	s.erase(u);
	for(auto v:e[u])
	{
		d[v]--;
		for(auto w:g[v])
			upd(w);
	}
	for(auto v:g[u])
		upd(v);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		a[make_pair(x[i],y[i])]=i;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			int v=id(x[i]+j,y[i]-1);
			if(v==-1)
				continue;
			e[v].push_back(i);
			g[i].push_back(v);
			d[i]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		int fl=1;
		for(auto j:e[i])
			if(d[j]==1)
				fl=0;
		if(fl)
			s.insert(i);
	}
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			int u=*(--s.end());
			del(u);
			ans[i]=u;
		}
		else
		{
			int u=*(s.begin());
			del(u);
			ans[i]=u;
		}
	}
	for(int i=0;i<n;i++)
		r=(1ll*r*n%mod+ans[i])%mod;
	printf("%d\n",r);
	return 0;
}