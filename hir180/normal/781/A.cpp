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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
vector<int>edge[200005];
int ans,col[200005];
void dfs(int v,int u,int c,int d){
	set<int>S; S.insert(c); S.insert(d); col[v] = d; int nxt = 1;
	for(int i=0;i<edge[v].size();i++){
	    if(edge[v][i]==u) continue;
		while(S.find(nxt) != S.end()) nxt++;
		dfs(edge[v][i],v,col[v],nxt);
		S.insert(nxt); nxt++;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	for(int i=1;i<=n;i++) ans=max(ans,(int)(edge[i].size()));
	ans++;
	dfs(1,-1,-1,1);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) printf("%d ",col[i]);
	puts("");
}