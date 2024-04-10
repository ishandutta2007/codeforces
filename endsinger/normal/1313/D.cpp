#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=8;
int n,m,k,dp[N],id[N],a[1<<M],l;
set<int>s;
vector<pair<int,int>>v;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v.emplace_back(x,i);
		v.emplace_back(y+1,-i);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<k;i++)
		s.insert(i);
	for(int i=1;i<(1<<k);i++)
		dp[i]=-1e9,a[i]=a[i>>1]^(i&1);
	for(auto t:v)
	{
		int r=t.first,u=t.second;
		for(int i=0;i<(1<<k);i++)
			if(a[i])
				dp[i]+=r-l;
		l=r;
		if(u>0)
		{
			id[u]=*s.begin();
			s.erase(id[u]);
			for(int i=0;i<(1<<k);i++)
				if(i&(1<<id[u]))
					dp[i]=max(dp[i],dp[i^(1<<id[u])]);
		}
		else
		{
			u=-u;
			s.insert(id[u]);
			for(int i=0;i<(1<<k);i++)
			{
				if(i&(1<<id[u]))
				{
					dp[i^(1<<id[u])]=max(dp[i^(1<<id[u])],dp[i]);
					dp[i]=-1e9;
				}
			}
		}
	}
	printf("%d\n",dp[0]);
	return 0;
}