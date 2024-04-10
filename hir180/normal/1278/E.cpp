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
int n;
vector<int>edge[500005];
vector<int>num[500005];
void dfs(int v,int u){
	bool ch = 0;
	P p = mp(-1,-1);
	rep(i,edge[v].size()){
		if(edge[v][i]==u) continue;
		ch = 1; dfs(edge[v][i],v);
		p = max(p,mp((int)num[edge[v][i]].size(),edge[v][i]));
	}
	if(!ch){
		rep(i,2) num[v].pb(v);
		return;
	}
	swap(num[v],num[p.sc]);
	vector<int>las; las.pb(num[v].back()); num[v].pop_back();
	
	rep(i,edge[v].size()){
		if(edge[v][i]==u||edge[v][i]==p.sc) continue;
		las.pb(num[edge[v][i]].back());
		rep(j,num[edge[v][i]].size()-1) num[v].pb(num[edge[v][i]][j]);
	}
	num[v].pb(v); reverse(las.begin(),las.end());
	rep(i,las.size()) num[v].pb(las[i]);
	num[v].pb(v);
//	cout << v << endl;
//	rep(i,num[v].size()) cout << num[v][i] << " "; cout << endl;
}
vector<int>vec[500005];
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	rep(i,num[1].size()) vec[num[1][i]].pb(i+1);
	repn(i,n) printf("%d %d\n",vec[i][0],vec[i][1]);
}