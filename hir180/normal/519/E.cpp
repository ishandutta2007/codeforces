#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
 
using namespace std;
 
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef long long ll;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define INF 100000000
vector<int>edge[100005];
int lca[100005][20];
int dep[100005];
int n;
map<P,int>ma;
int dfs(int v,int u)
{
	lca[v][0] = u;
	if(u == -1) dep[v] = 0;
	else dep[v] = dep[u]+1;
	int zan = n-1,sum = 1;
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i] == u) continue;
		int x = dfs(edge[v][i],v);
		sum += x;
		zan -= x;
		ma[mp(v,edge[v][i])] = x;
	}
	ma[mp(v,u)] = zan;
	return sum;
}
int v(int a,int b)
{
	if(dep[a] > dep[b]) swap(a,b);
	int aa = a,bb = b;
	for(int i=0;i<20;i++)
	{
		if((((dep[b]-dep[a])>>i)&1))
		{
			b = lca[b][i];
		}
	}
	if(a == b)
	{
		if((dep[bb]-dep[aa])%2 == 1)
		{
			return 0;
		}
		else
		{
			int dif = (dep[bb]-dep[aa])/2;
			int bbb = bb;
			for(int i=0;i<20;i++)
			{
				if(((dif>>i)&1))
				{
					bb = lca[bb][i];
				}
			}
			dif--;
			for(int i=0;i<20;i++)
			{
				if(((dif>>i)&1))
				{
					bbb = lca[bbb][i];
				}
			}
			return n-ma[mp(bb,bbb)]-ma[mp(bb,lca[bb][0])];
		}
	}
	for(int i=19;i>=0;i--)
	{
		if(lca[a][i] != lca[b][i])
		{
			a = lca[a][i];
			b = lca[b][i];
		}
	}
	a = lca[a][0];
	b = lca[b][0];
	int dif = (dep[bb]-dep[a])+(dep[aa]-dep[a]);
	if(dif%2 == 1) return 0;
	if(dep[aa] != dep[bb])
	{
		dif /= 2;
		int bbb = bb;
		for(int i=0;i<20;i++)
		{
			if(((dif>>i)&1))
			{
				bb = lca[bb][i];
			}
		}
		dif--;
		for(int i=0;i<20;i++)
		{
			if(((dif>>i)&1))
			{
				bbb = lca[bbb][i];
			}
		}
		return n-ma[mp(bb,bbb)]-ma[mp(bb,lca[bb][0])];
	}
	else
	{
		dif/=2; dif--;
		for(int i=0;i<20;i++)
		{
			if(((dif>>i)&1))
			{
				bb = lca[bb][i];
			}
		}
		for(int i=0;i<20;i++)
		{
			if(((dif>>i)&1))
			{
				aa = lca[aa][i];
			}
		}
		return n-ma[mp(a,bb)]-ma[mp(a,aa)];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	for(int i=0;i<19;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(lca[j][i] == -1)
			{
				lca[j][i+1] = -1;
			}
			else
			{
				lca[j][i+1] = lca[lca[j][i]][i];
			}
		}
	}
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		if(a == b)
		{
			cout << n << endl;
			continue;
		}
		printf("%d\n",v(a,b));
	}
}