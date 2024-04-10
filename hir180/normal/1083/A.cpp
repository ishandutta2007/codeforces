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
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<int,ll> > edge[300005];
int n;
ll dp[300005],A[300005],ans;
void dfs(int v,int u){
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i].fi ; if(to == u) continue;
		dfs(to,v);
	}
	dp[v] = A[v];
	priority_queue<ll,vector<ll>,greater<ll> >que;
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i].fi ; if(to == u) continue;
		que.push(max(0LL,dp[to]-edge[v][i].sc));
		if(que.size() == 3) que.pop();
	}
	ll cur = dp[v];
	ll add = 0;
	while(!que.empty()){
		ll val = que.top(); que.pop();
		add = max(add,val);
		cur += val;
	}
	ans = max(ans,cur);
	dp[v] += add;
}
int main(){
	cin>>n;
	repn(i,n) scanf("%lld",&A[i]);
	rep(i,n-1){
		int a,b; ll c; scanf("%d%d%lld",&a,&b,&c);
		edge[a].pb(mp(b,c));
		edge[b].pb(mp(a,c));
	}
	dfs(1,-1);
	cout<<ans<<endl;
}