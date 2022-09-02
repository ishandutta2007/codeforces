//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
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
#define s (1<<19)
vector<int>edge[500005];
vector<int>vs;
int in[500005],out[500005];
void dfs(int v,int u)
{
	vs.pb(v);in[v]=vs.size()-1;
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
	}
	out[v]=vs.size()-1;
}
struct segtree
{
	int seg[s*2];
	int lazy[s*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		seg[k*2+1]=max(seg[k*2+1],lazy[k]);
		seg[k*2+2]=max(seg[k*2+2],lazy[k]);
		lazy[k*2+1]=max(lazy[k*2+1],lazy[k]);
		lazy[k*2+2]=max(lazy[k*2+2],lazy[k]);
	}
	int update(int a,int b,int k,int l,int r,int val)
	{
		if(b<l || r<a) return seg[k];
		if(a<=l && r<=b)
		{
			seg[k]=max(seg[k],val);
			lazy[k]=max(lazy[k],val);
			return seg[k];
		}
		lazy_evaluate(k);
		int lko=update(a,b,k*2+1,l,(l+r)/2,val);
		int rko=update(a,b,k*2+2,(l+r)/2+1,r,val);
		return seg[k]=max(lko,rko);
	}
	int get(int a,int b,int k,int l,int r)
	{
		if(b<l || r<a) return -1;
		if(a<=l && r<=b)
		{
			return seg[k];
		}
		lazy_evaluate(k);
		int lko=get(a,b,k*2+1,l,(l+r)/2);
		int rko=get(a,b,k*2+2,(l+r)/2+1,r);
		return max(lko,rko);
	}
}seg,seg2;
int main()
{
	int n,q;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int u,v; scanf("%d %d",&u,&v);
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs(1,-1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int t,v; scanf("%d %d",&t,&v);
		if(t==1)
		{
			seg.update(in[v],out[v],0,0,s-1,i);
		}
		else if(t==2)
		{
			seg2.update(in[v],in[v],0,0,s-1,i);
		}
		else
		{
			int f=seg.get(in[v],in[v],0,0,s-1);
			int r=seg2.get(in[v],out[v],0,0,s-1);
			printf("%d\n",(f>r));
		}
	}
}