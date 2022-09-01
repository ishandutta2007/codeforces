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
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 998244353;
#define INF 100000000

struct edge
{
	int to,cap,cost,rev;
};
int nn=1505;
vector<edge>G[1505];
int dist[1505];
int prevv[1505],preve[1505];

void add_edge(int from,int to,int cap,int cost)
{
	G[from].pb((edge){to,cap,cost,G[to].size()});
	G[to].pb((edge){from,0,-cost,G[from].size()-1});
}

int mincost_maxflow(int s,int t,int f)
{
	int res=0;
	while(f>0)
	{
		//n!!!!!!
		fill(dist,dist+nn,INF);
		dist[s]=0;
		bool upd=true;
		while(upd)
		{
			upd=false;
			for(int v=0;v<nn;v++)
			{
				if(dist[v]==INF) continue;
				for(int i=0;i<G[v].size();i++)
				{
					edge &e = G[v][i];
					if(e.cap>0 && dist[e.to]>dist[v]+e.cost)
					{
						dist[e.to]=dist[v]+e.cost;
						prevv[e.to]=v;
						preve[e.to]=i;
						upd=true;
					}
				}
			}
		}
		if(dist[t]==INF) return -1;
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
		{
			d = min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*dist[t];
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}


int ex[55][55];
int n,m;
bool o[55][55];
int main(){
	cin >> n >> m;
	memset(ex,-1,sizeof(ex));
	rep(i,m){
		int a,b; cin >> a >> b; a--; b--;
		ex[min(a,b)][max(a,b)] = a;
	}
	int id = 0;
	rep(i,n) for(int j=i+1;j<n;j++){
		add_edge(1503,id,1,0);
		if(ex[i][j] == -1){
			add_edge(id,1400+i,1,0);
			add_edge(id,1400+j,1,0);
		}
		else{
			assert(ex[i][j] == i || ex[i][j] == j);
			add_edge(id,1400+ex[i][j],1,0);
		}
		id++;
	}
	rep(i,n){
		rep(j,n){
			add_edge(1400+i,1504,1,j);
		}
	}
	
	int num = mincost_maxflow(1503,1504,n*(n-1)/2);
	//cout << n*(n-1)*(n-2)/6-num << endl;
	
	id = 0;
	rep(i,n) for(int j=i+1;j<n;j++){
		if(ex[i][j] == -1){
			rep(k,G[id].size()){
				if(G[id][k].to == 1400+i && G[id][k].cap == 0){
					ex[i][j] = i;
					break;
				}
				if(G[id][k].to == 1400+j && G[id][k].cap == 0){
					ex[i][j] = j;
					break;
				}
			}
		}
		if(ex[i][j] == i) o[i][j] = 1;
		else if(ex[i][j] == j) o[j][i] = 1;
		else assert(0);
		id++;
	}
	rep(i,n){
		rep(j,n) printf(o[i][j]?"1":"0");
		puts("");
	}
}