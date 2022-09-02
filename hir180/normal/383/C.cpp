//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define f first
#define s second
#define SIZE (1<<19)
#define rep(i,x) for(int i=0;i<x;i++)
vector<int>vec[200005],vec2[200005];
vector<int>euler_tour,euler_tour2;
int val[200005];
int in[200005],out[200005];
int wh[200005];
inline void dfs(int v,int u)
{
	wh[v]=1;
	euler_tour.pb(v);
	in[v]=euler_tour.size()-1;
	for(int i=0;i<vec[v].size();i++)
	{
		if(u==vec[v][i]) continue;
		dfs(vec[v][i],v);
		euler_tour.pb(v);
	}
	out[v]=euler_tour.size()-1;
}
inline void dfs2(int v,int u)
{
	wh[v]=2;
	euler_tour2.pb(v);
	in[v]=euler_tour2.size()-1;
	for(int i=0;i<vec[v].size();i++)
	{
		if(u==vec[v][i]) continue;
		dfs2(vec[v][i],v);
		euler_tour2.pb(v);
	}
	out[v]=euler_tour2.size()-1;
}
class segtree
{
public:
	int seg[SIZE*2];
	int lazy[SIZE*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=SIZE*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	int update(int beg,int end,int idx,int lb,int ub,int num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	int query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return -100000000;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return max(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
}seg,seg2;
int par[200005];
void predfs(int v,int u)
{
	par[v]=u;
	for(int i=0;i<vec2[v].size();i++)
	{
		if(vec2[v][i]==u) continue;
		if(u!=-1)
		{
			vec[u].pb(vec2[v][i]);
			vec[vec2[v][i]].pb(u);
		}
		predfs(vec2[v][i],v);
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&val[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		u--;v--;
		vec2[u].pb(v);
		vec2[v].pb(u);
	}
	vec2[0].pb(n);
	vec2[n].pb(0);
	predfs(n,-1);
	dfs(0,-1);
	dfs2(n,-1);

	for(int i=0;i<euler_tour.size();i++)
	{
//printf("%d %d\n",1,euler_tour[i]);
		seg.update(i,i,0,0,SIZE-1,val[euler_tour[i]]); 
	}
	for(int i=0;i<euler_tour2.size();i++)
	{
//printf("%d %d\n",2,euler_tour2[i]);
		seg2.update(i,i,0,0,SIZE-1,val[euler_tour2[i]]); 
	}
	for(int i=0;i<m;i++)
	{
		int t;scanf("%d",&t);
		if(t==1)
		{
			int u,v; scanf("%d %d",&u,&v);
			u--;
			if(wh[u]==1)
			{
				seg.update(in[u],out[u],0,0,SIZE-1,v);
				for(int j=0;j<vec2[u].size();j++)
				{
					if(vec2[u][j]==par[u]) continue;
					seg2.update(in[vec2[u][j]],out[vec2[u][j]],0,0,SIZE-1,-v);
				}
			}
			else
			{
				seg2.update(in[u],out[u],0,0,SIZE-1,v);
				for(int j=0;j<vec2[u].size();j++)
				{
					if(vec2[u][j]==par[u]) continue;
					seg.update(in[vec2[u][j]],out[vec2[u][j]],0,0,SIZE-1,-v);
				}
			}
		}
		else
		{
			int v; scanf("%d",&v);v--;
			printf("%d\n",wh[v]==1?seg.query(in[v],in[v],0,0,SIZE-1):seg2.query(in[v],in[v],0,0,SIZE-1));
		}
	}
}