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
int n;
vector<P>edge[100005];
ll d[100005];
ll f[100005],s[100005],up[100005];
ll ec[100005];
int val[55];
ll c(int v,int u)
{
	pair<ll,ll> cur;
	cur = mp(0,0);
	
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i].fi == u) continue;
		ec[edge[v][i].fi] = edge[v][i].sc;
		ll x = c(edge[v][i].fi,v);
		if(x + edge[v][i].sc > cur.fi)
		{
			cur.sc = cur.fi;
			cur.fi = x + edge[v][i].sc;
		}
		else if(x + edge[v][i].sc > cur.sc)
		{
			cur.sc = x + edge[v][i].sc;
		}
	}
	f[v] = cur.fi;
	s[v] = cur.sc;
	return cur.fi;
}
void calc(int v,int u)
{
	if(u == -1)
	{
		up[v] = 0;
	}
	else
	{
		if(f[u] == ec[v]+f[v]) up[v] = ec[v]+max(s[u],up[u]);
		else up[v] = ec[v]+max(f[u],up[u]);
	}
	for(int i=0;i<edge[v].size();i++)
	{
		if(edge[v][i].fi == u) continue;
		calc(edge[v][i].fi,v);
	}
}
vector<ll>seg[(1<<18)];
void update(int a,ll b)
{
	a+=(1<<17)-1;
	seg[a].pb(b);
}
void all()
{
	for(int i=(1<<17)-2;i>=0;i--)
	{
		if(seg[i*2+1].empty() && seg[i*2+2].empty()) continue;
		else if(seg[i*2+1].empty()) seg[i] = seg[i*2+2];
		else if(seg[i*2+2].empty()) seg[i] = seg[i*2+1];
		else
		{
			seg[i].resize(seg[i*2+1].size()+seg[i*2+2].size());
			merge(seg[i*2+1].begin(),seg[i*2+1].end(),seg[i*2+2].begin(),seg[i*2+2].end(),seg[i].begin());
		}
	}
}
int qq;
pair<ll,int> q[55];
void query(int a,int b,int k,int l,int r,ll bb)
{
	if(r<a || b<l) return;
	if(a<=l && r<=b)
	{
		if(seg[k].size()>=2048)
		{
			int beg = lower_bound(seg[k].begin(),seg[k].end(),bb)-seg[k].begin();
			int pre = 0;
			for(int i=0;i<qq;i++)
			{
				int d = upper_bound(seg[k].begin()+pre,seg[k].end(),q[i].fi+bb)-seg[k].begin();
				val[q[i].sc] += d-beg;
				if(d>=1) pre = d-1;
			}
		}
		else
		{
			int nxt = 0;
			int beg = lower_bound(seg[k].begin(),seg[k].end(),bb)-seg[k].begin();
			for(int j=beg;j<seg[k].size()&&nxt<qq;j++)
			{
				while(nxt<qq && q[nxt].fi < seg[k][j]-bb)
				{
					val[q[nxt].sc] += j;
					nxt++;
				}
			}
			while(nxt<qq)
			{
				val[q[nxt].sc] += seg[k].size()-beg;
				nxt++;
			}
		}
		return;
	}
	query(a,b,k*2+1,l,(l+r)/2,bb);
	query(a,b,k*2+2,(l+r)/2+1,r,bb);
}
int lb[100005],ub[100005],vt=0;
void dfs(int v,int u)
{
	lb[v] = vt; update(vt,d[v]); vt++;
	for(int j=0;j<edge[v].size();j++)
	{
		if(edge[v][j].fi == u) continue;
		dfs(edge[v][j].fi,v);
	}
	ub[v] = vt-1;
}
bool another[100005];
int res[55];
int qw[100005];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
		qw[a]++;
		qw[b]++;
	}
	int root = 1;
	//for(int i=1;i<=n;i++) if(qw[root] < qw[i]) root = i;
	c(root,-1);
	calc(root,-1);
	for(int i=1;i<=n;i++) d[i] = max(f[i],up[i]);
	for(int i=1;i<=n;i++) if(d[root] > d[i]) root = i;
	dfs(root,-1);
	scanf("%d",&qq);
	for(int i=0;i<qq;i++)
	{
		ll x; scanf("%lld",&x);
		q[i] = mp(x,i);
	}
	sort(q,q+qq);
	all();
	for(int i=1;i<=n;i++)
	{
		memset(val,0,sizeof(val));
		query(lb[i],ub[i],0,0,(1<<17)-1,d[i]);
		for(int j=0;j<qq;j++) res[j] = max(res[j],val[j]);
	}
	for(int i=0;i<qq;i++) printf("%d\n",res[i]);
}