#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,l[222222],r[222222],x,y;
const int mod=1e6+3;
struct hashtable
{
	vector<long long> g[1111111];
	void add(long long x)
	{
		int cur=x%mod;
		for (int i=0;i<g[cur].size();i++)
		{
			if (g[cur][i]==x) return;
		}
		g[cur].push_back(x); 
	} 
	bool find(long long x)
	{
		int cur=x%mod;
		for (int i=0;i<g[cur].size();i++)
		{
			if (g[cur][i]==x) return 1;
		}
		return 0;
	}
}ht;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&l[i],&r[i]);
		ht.add(1ll*l[i]*n+r[i]);
	}
	for (int i=1;i<n;i++)
	{
		if (n%i==0)
		{
			bool f=0;
			for (int j=1;j<=m;j++)
			{
				x=(l[j]+i-1)%n+1;y=(r[j]+i-1)%n+1;
				if (!ht.find(1ll*x*n+y) && !ht.find(1ll*y*n+x)) 
				{
					f=1;
					break;
				}
			}
			if (!f)
			{
				printf("Yes\n");
				return Accepted;
			}
		}
	}
	printf("No\n");
	return Accepted;
}