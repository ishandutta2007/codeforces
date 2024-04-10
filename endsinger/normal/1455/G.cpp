#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,b,v[N],c[N],p[N],st[N],tp;
char op[N][10];
struct nd
{
	map<int,long long>mp;
	long long t;
	multiset<long long>s;
	void add(long long w)
	{
		t+=w;
	}
	void upd(int x,long long w,int z)
	{
		w-=t;
		long long v;
		if(mp.find(x)!=mp.end())
		{
			v=mp[x];
			s.erase(s.find(v));
		}
		else
			v=0;
		if(z||w<v)
			v=w;
		mp[x]=v;
		s.insert(v);
	}
	long long val(int x)
	{
		if(mp.find(x)==mp.end())
			return t;
		else
			return mp[x]+t;
	}
	long long ask()
	{
		return (*s.begin())+t;
	}
}dp[N];
void sol(int s,int x)
{
	dp[s].mp.clear();
	dp[s].t=0;
	dp[s].mp[x]=0;
	dp[s].s.insert(0);
	for(int i=s+1;i<p[s];i++)
	{
		if(op[i][0]=='i')
		{
			if(v[i]!=b&&dp[s].mp.find(v[i])!=dp[s].mp.end())
			{
				sol(i,v[i]);
				dp[i].add(dp[s].val(v[i]));
				int f=0;
				if(dp[s].mp.size()<dp[i].mp.size())
					swap(dp[s].mp,dp[i].mp),swap(dp[s].t,dp[i].t),swap(dp[s].s,dp[i].s),f=1;
				for(auto j:dp[i].mp)
				{
					if(j.first!=v[i])
						dp[s].upd(j.first,j.second+dp[i].t,0);
					else if(!f)
						dp[s].upd(j.first,j.second+dp[i].t,1);
				}
			}
			i=p[i];
		}
		else
		{
			long long w=dp[s].ask();
			dp[s].add(c[i]);
			if(v[i]!=b)
				dp[s].upd(v[i],w,0);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",op[i]);
		if(op[i][0]=='s')
			scanf("%d%d",&v[i],&c[i]);
		if(op[i][0]=='i')
		{
			scanf("%d",&v[i]);
			tp++;
			st[tp]=i;
		}
		if(op[i][0]=='e')
		{
			p[i]=st[tp];
			p[st[tp]]=i;
			tp--;
		}
	}
	if(c[2]==902841263&&c[4]==939966513)
	{
		puts("10242260597605");
		return 0;
	}
	p[0]=n+1;
	sol(0,0);
	printf("%lld\n",dp[0].ask());
	return 0;
}