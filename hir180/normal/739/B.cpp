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
#include <cassert>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
int vb[200005][21];
ll db[200005][21],a[200005];
vector<pair<int,ll> >edge[200005];
int id[200005],dep[200005],en[200005],ind=1;
void dfs(int v,int u,ll s){
	vb[v][0] = u; db[v][0] = s;
	id[v] = ind++; dep[v] = (u==-1?0:dep[u]+1);
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i].fi == u) continue;
		dfs(edge[v][i].fi,v,edge[v][i].sc);
	}
	en[v] = ind-1;
}
int up[200005];

	vector<int>bit[(1<<20)+5];
	int f(int x)
	{
		return x&-x;
	}
	void add(int i,int x)
	{
		for(int s=i;s<(1<<20)+5;s+=f(s)) bit[s].pb(x);
	}
void make(){ for(int i=0;i<(1<<20)+5;i++) sort(bit[i].begin(),bit[i].end());}
	int sum(int i,int ff)
	{
		int res=0;
		for(int s=i;s>0;s-=f(s)) res+=upper_bound(bit[s].begin(),bit[s].end(),ff)-bit[s].begin();
		return res;
	}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=2;i<=n;i++){
		int a; ll b; scanf("%d%lld",&a,&b);
		edge[i].pb(mp(a,b));
		edge[a].pb(mp(i,b));
	}
	dfs(1,-1,0);
	for(int j=0;j<19;j++){
		for(int i=1;i<=n;i++){
			if(vb[i][j] == -1){
				vb[i][j+1] = -1;
				db[i][j+1] = -1;
			}
			else{
				vb[i][j+1] = vb[vb[i][j]][j];
				db[i][j+1] = db[i][j]+db[vb[i][j]][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		ll cur = 0; int C = i;

		for(int j=19;j>=0;j--){
			if(vb[C][j] == -1 || db[C][j]+cur > a[i]);
			else{
				cur += db[C][j];
				C = vb[C][j];
				up[i] += (1<<j);
			}
		}
		add(id[i],dep[i]-up[i]); //cout << dep[i] << "  "<< up[i] << endl;
	}make();
	for(int i=1;i<=n;i++){
		printf("%d ",sum(en[i],dep[i])-sum(id[i],dep[i]));
	}puts("");
}