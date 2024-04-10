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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll sum[200005][2],cnt[200005][2];
vector<int>edge[200005];
void dfs(int v,int u){
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
		sum[v][0] += sum[edge[v][i]][1]+cnt[edge[v][i]][1];
		cnt[v][0] += cnt[edge[v][i]][1];
		sum[v][1] += sum[edge[v][i]][0]+cnt[edge[v][i]][0];
		cnt[v][1] += cnt[edge[v][i]][0];
	}
	cnt[v][0]++;
}
ll ans;
void dfs2(int v,int u,pair<pair<ll,ll>,pair<ll,ll> >x){
	ll s0=x.fi.fi,c0=x.fi.sc,s1=x.sc.fi,c1=x.sc.sc;
	ans += sum[v][0]/2;
	ans += (sum[v][1]+cnt[v][1])/2;
	assert(s1%2 == c1%2);
	ans += (s1+c1)/2;
	ans += s0/2;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		s0 += sum[edge[v][i]][1]+cnt[edge[v][i]][1];
		c0 += cnt[edge[v][i]][1];
		s1 += sum[edge[v][i]][0]+cnt[edge[v][i]][0];
		c1 += cnt[edge[v][i]][0];
	}
	c0++;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i] == u) continue;
		s0 -= sum[edge[v][i]][1]+cnt[edge[v][i]][1];
		c0 -= cnt[edge[v][i]][1];
		s1 -= sum[edge[v][i]][0]+cnt[edge[v][i]][0];
		c1 -= cnt[edge[v][i]][0];
		ll ss0 = s1+c1;
		ll cc0 = c1;
		ll ss1 = s0+c0;
		ll cc1 = c0;
		dfs2(edge[v][i],v,mp(mp(ss0,cc0),mp(ss1,cc1)));
		s0 += sum[edge[v][i]][1]+cnt[edge[v][i]][1];
		c0 += cnt[edge[v][i]][1];
		s1 += sum[edge[v][i]][0]+cnt[edge[v][i]][0];
		c1 += cnt[edge[v][i]][0];
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	dfs2(1,-1,mp(mp(0LL,0LL),mp(0LL,0LL)));
	cout << ans/2 << endl;
}