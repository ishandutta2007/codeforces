// I'll become a member of  IOI 2014 Japan team.
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define lim 25000
int n,m,q,o;
bool in[50005]={};
vector<int>edge[50005];
vector<int>rem[50005];
vector<int>bigf[50005];
int sum[50005];
bool big[50005];
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	scanf("%d",&o);
	for(int i=0;i<o;i++)
	{
		int x; scanf("%d",&x);
		in[x]=true;
	}
	for(int i=0;i<m;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		edge[x].pb(y);
		edge[y].pb(x);
	}
	
	for(int i=1;i<=n;i++)
	{
		if(edge[i].size()>=lim)
		{
			big[i]=true;
			for(int j=0;j<edge[i].size();j++)
			{
				sum[i]+=in[edge[i][j]];
				bigf[edge[i][j]].pb(i);
			}
		}
	}
	while(q--)
	{
		char qr;  scanf(" %c",&qr);
		if(qr=='O')
		{
			int ql; scanf("%d",&ql);
			in[ql]=true;
			{
				for(int i=0;i<bigf[ql].size();i++)
				{
					sum[bigf[ql][i]]++;
				}
				for(int i=0;i<rem[ql].size();i++)
				{
					if(big[rem[ql][i]]) sum[rem[ql][i]]--;
				}
			}
		}
		else if(qr=='F')
		{
			int ql; scanf("%d",&ql);
			in[ql]=false;
			{
				for(int i=0;i<bigf[ql].size();i++)
				{
					sum[bigf[ql][i]]--;
				}
				for(int i=0;i<rem[ql].size();i++)
				{
					if(big[rem[ql][i]]) sum[rem[ql][i]]++;
				}
			}
		}
		else if(qr=='A')
		{
			int u,v; scanf("%d%d",&u,&v);
			edge[u].pb(v);
			edge[v].pb(u);
			if(big[u])
			{
				bigf[v].pb(u);
				sum[u]+=in[v];
			}
			if(big[v])
			{
				bigf[u].pb(v);
				sum[v]+=in[u];
			}
			if(edge[u].size()+rem[u].size()>=lim && !big[u])
			{
				big[u]=true;
				for(int i=0;i<edge[u].size();i++) sum[u]+=in[edge[u][i]];
				for(int i=0;i<rem[u].size();i++) sum[u]-=in[rem[u][i]];
				for(int i=0;i<edge[u].size();i++) bigf[edge[u][i]].pb(u);
			}
			if(edge[v].size()+rem[v].size()>=lim && !big[v])
			{
				big[v]=true;
				for(int i=0;i<edge[v].size();i++) sum[v]+=in[edge[v][i]];
				for(int i=0;i<rem[v].size();i++) sum[v]-=in[rem[v][i]];
				for(int i=0;i<edge[v].size();i++) bigf[edge[v][i]].pb(v);
			}
		}
		else if(qr=='D')
		{
			int u,v; scanf("%d%d",&u,&v);
			rem[u].pb(v);
			rem[v].pb(u);
			if(big[u])
			{
				sum[u]-=in[v];
			}
			if(big[v])
			{
				sum[v]-=in[u];
			}
			if(edge[u].size()+rem[u].size()>=lim && !big[u])
			{
				big[u]=true;
				for(int i=0;i<edge[u].size();i++) sum[u]+=in[edge[u][i]];
				for(int i=0;i<rem[u].size();i++) sum[u]-=in[rem[u][i]];
				for(int i=0;i<edge[u].size();i++) bigf[edge[u][i]].pb(u);
			}
			if(edge[v].size()+rem[v].size()>=lim && !big[v])
			{
				big[v]=true;
				for(int i=0;i<edge[v].size();i++) sum[v]+=in[edge[v][i]];
				for(int i=0;i<rem[v].size();i++) sum[v]-=in[rem[v][i]];
				for(int i=0;i<edge[v].size();i++) bigf[edge[v][i]].pb(v);
			}
		}
		else
		{
			int ql; scanf("%d",&ql);
			if(big[ql]) printf("%d\n",sum[ql]);
			else
			{
				int res=0;
				for(int i=0;i<edge[ql].size();i++) res+=in[edge[ql][i]];
				for(int i=0;i<rem[ql].size();i++) res-=in[rem[ql][i]];
				printf("%d\n",res);
			}
		}
	}
}