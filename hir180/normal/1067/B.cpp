#include <bits/stdc++.h>
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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,k;
vector<int>edge[100005];
int V,d;
vector<int>vec[100005];
void dfs(int v,int u,int D){
	if(d < D){
		d = D;
		V = v;
	}
	vec[v].pb(D);
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v,D+1);
	}
}
bool ddfs(int v,int u,int zan){
	if(zan < 0) return false;
	int in = 0;
	bool ret = 1;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		in++;
		ret &= ddfs(edge[v][i],v,zan-1);
	}
	if(in == 0) return (zan == 0);
	else if(in >= 3){
		return ret;
	}
	else return false;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	V = -1; d = -1;
	dfs(1,-1,0);
	int u = V;
	V = -1; d = -1;
	dfs(u,-1,0);
	int vv = V;
	V = -1; d = -1;
	dfs(vv,-1,0);
	
	
	if(d != 2*k){
		puts("No"); return 0;
	}
	for(int i=1;i<=n;i++){
		if(vec[i][2] == k && vec[i][1] == k){
			int cent = i; 
			bool ok = ddfs(cent,-1,k);
			puts(ok?"Yes":"No");
			return 0;
		}
	}
	puts("No"); return 0;
}