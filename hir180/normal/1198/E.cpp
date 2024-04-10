#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n,m;
vector<int>zax,zay;
int xa[55],ya[55],xb[55],yb[55];




struct edge
{
	int to,cap,rev;
};
vector<edge>G[305];
bool used[305];

void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
int dfs(int v,int t,int f)
{ 
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0)
		{ 
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{ 
	int flow=0;
	while(1)
	{ 
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(!f) return flow;
		flow+=f;
	}
}

int main(){
	cin >> n >> m;
	zax.pb(0); zax.pb(n);
	zay.pb(0); zay.pb(n);
	rep(i,m){
		cin >> xa[i] >> ya[i] >> xb[i] >> yb[i];
		zax.pb(xa[i]);
		zax.pb(xb[i]+1);
		zay.pb(ya[i]);
		zay.pb(yb[i]+1);
	}
	SORT(zax); ERASE(zax);
	SORT(zay); ERASE(zay);
	rep(i,zax.size()-1){
		add_edge(300,i,zax[i+1]-zax[i]);
	}
	rep(i,zay.size()-1){
		add_edge(150+i,301,zay[i+1]-zay[i]);
	}
	rep(i,m){
		xa[i] = POSL(zax,xa[i]); xb[i] = POSL(zax,xb[i]+1)-1;
		ya[i] = POSL(zay,ya[i]); yb[i] = POSL(zay,yb[i]+1)-1;
		for(int a=xa[i];a<=xb[i];a++){
			for(int b=ya[i];b<=yb[i];b++){
				add_edge(a,150+b,min(zax[a+1]-zax[a],zay[b+1]-zay[b]));
			}
		}
	}
	
	cout << max_flow(300,301) << endl;
}