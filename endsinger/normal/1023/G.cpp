#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,ans,s;
vector<pair<int,int>>e[N],q[N];
struct nd
{
	int t;
	map<int,int>f,g;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	void upd(int x,int v)
	{
		if(v==1)
		{
			auto it=g.upper_bound(x-2*t);
			if(it!=g.begin())
				pq.emplace(x-prev(it)->first,x);
		}
		else
		{
			auto it=f.lower_bound(x+2*t);
			if(it!=f.end())
				pq.emplace(it->first-x,it->first);
		}
	}
	void cal(int d)
	{
		while(pq.size()&&pq.top().first<=2*(t+d))
		{
			int x=pq.top().second,y=pq.top().second-pq.top().first;
			pq.pop();
			auto ix=f.find(x),iy=g.find(y);
			if(ix==f.end()||iy==g.end())
				continue;
			if(ix->second+iy->second<0)
			{
				iy->second+=ix->second;
				f.erase(ix);
				upd(iy->first,-1);
			}
			else
			{
				ix->second+=iy->second;
				g.erase(iy);
				upd(ix->first,1);
			}
		}
		t+=d;
	}
	void add(int p,int x)
	{
		if(x>0)
		{
			f[p+t]+=x;
			upd(p+t,1);
		}
		else
		{
			g[p-t]+=x;
			upd(p-t,-1);
		}
	}
	int ask(int p)
	{
		int s=0;
		if(f.find(p+t)!=f.end())
			s+=f[p+t];
		if(g.find(p-t)!=f.end())
			s+=g[p-t];
		return s;
	}
	int sz()
	{
		return f.size()+g.size();
	}
}dp[N];
map<int,int>mp;
void mg(nd &a,nd &b)
{
	if(a.sz()<b.sz())
		swap(a,b);
	for(auto [d,x]:b.f)
		a.add(d-b.t,x);
	for(auto [d,x]:b.g)
		a.add(d+b.t,x);
}
void dfs(int u,int f)
{
	for(auto [v,w]:e[u])
	{
		if(v==f)
			continue;
		dfs(v,u);
		for(auto &[d,x]:q[v])
			x-=max(0,max(-dp[v].ask(d),dp[v].ask(d+1)));
		dp[v].cal(1);
		for(auto [d,x]:q[v])
			if(x>0)
				dp[v].add(d,x),dp[v].add(d+1,-x);
		dp[v].cal(w-1);
		mg(dp[u],dp[v]);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].emplace_back(v,w*2);
		e[v].emplace_back(u,w*2);
	}
	n++;
	e[n].emplace_back(1,2);
	e[1].emplace_back(n,2);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int d,x,u;
		scanf("%d%d%d",&d,&x,&u);
		q[u].emplace_back(d*2,x);
	}
	dfs(n,0);
	for(auto [d,x]:dp[n].f)
		mp[d-dp[n].t]+=x;
	for(auto [d,x]:dp[n].g)
		mp[d+dp[n].t]+=x;
	for(auto i:mp)
	{
		s+=i.second;
		ans=max(ans,s);
	}
	printf("%d\n",ans);
	return 0;
}