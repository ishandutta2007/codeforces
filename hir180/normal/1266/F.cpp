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
 
const ll mod = 1000000007;
 
int n;
vector<int>edge[500005];
int up[500005][21],dep[500005];
int dp[500005][2];
 
void dfs(int v,int u){
	if(u == -1) dep[v] = 0; else dep[v] = dep[u]+1;
	up[v][0] = u;
	dp[v][0] = 0;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
		dp[v][0] = max(dp[v][0],dp[edge[v][i]][0]+1);
	}
}
void dfs2(int v,int u,int up){
	dp[v][1] = up;
	priority_queue<P,vector<P>,greater<P>>que;
	que.push(mp(up,-1));
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		que.push(mp(dp[edge[v][i]][0]+1,edge[v][i]));
		if(que.size() == 3)  que.pop();
	}
	vector<P>vec;
	while(!que.empty()){vec.pb(que.top()); que.pop();}
	reverse(vec.begin(),vec.end());
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		rep(j,vec.size()){
			if(vec[j].sc == edge[v][i]) continue;
			dfs2(edge[v][i],v,vec[j].fi+1);
			break;
		}
	}
}
int lca(int ss,int t){
	if(dep[ss]>dep[t]) swap(ss,t);
	rep(i,19){
		if((((dep[t]-dep[ss])>>i)&1)){
			t = up[t][i];
		}
	}
	if(ss==t) return ss;
	for(int i=19;i>=0;i--){
		if(up[ss][i]!=up[t][i]){
			ss = up[ss][i];
			t = up[t][i];
		}
	}
	return up[ss][0];
}
//fuck
int ans[1000005];
//int ans[500005];
class segtree
{
public:
	#define s (1<<19)
	ll seg[s*2];
	ll lazy[s*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	ll update(int beg,int end,int idx,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb||beg>end)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx]+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	ll query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb||beg>end)
		{
			return -1000000000000000LL;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return max(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
}kaede,shiki;
vector<P>query[500005];
int beg[500005],en[500005],id[500005];
bool used[500005];
 
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b ; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	dfs(1,-1);
	rep(j,20){	repn(i,n){
		if(up[i][j]==-1)up[i][j+1]=-1;
		else up[i][j+1]=up[up[i][j]][j];
	}}
	dfs2(1,-1,0);
	//repn(i,n) cout << dp[i][0] << " " << dp[i][1] << endl;
	//odd
	repn(i,n){
		if(i == 1) continue;
		query[dp[i][0]+1].pb(mp(up[i][0],i));
		query[dp[i][1]].pb(mp(i,up[i][0]));
	}
	ll B = 1000000000LL;
	//fuck
	for(int i=n;i>=1;i--){
		rep(j,query[i].size()){
			int id = query[i][j].fi;
			kaede.update(id,id,0,0,(1<<19)-1,1);
		}
		ll val = kaede.query(0,(1<<19)-1,0,0,(1<<19)-1);
		int num = val/B;
		int x = val%B; x = !!x;
		ans[i*2+1] = num+x;
		rep(j,query[i].size()){
			int id = query[i][j].fi;
			kaede.update(id,id,0,0,(1<<19)-1,B-1);
		}
		val = kaede.query(0,(1<<19)-1,0,0,(1<<19)-1);
		num = val/B;
		ans[i*2] = num;
	}
	//return 0;
	//even
	queue<int>que;
	que.push(1); int num = 0;
	repn(i,n) {beg[i]=INF; en[i]=-INF;}
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(used[q]) continue; used[q] = 1; id[q] = num++; //cout << q << endl;
		if(id[q]){
			beg[up[q][0]] = min(beg[up[q][0]],id[q]);
			en[up[q][0]] = max(en[up[q][0]],id[q]);
		}
		rep(i,edge[q].size()){
			if(used[edge[q][i]]) continue;
			que.push(edge[q][i]);
		}
	}
	//repn(i,n) cout << beg[i] << " "  << en[i] << endl;
	//fuck
	for(int i=n;i>=1;i--){
	//for(int i=n/2;i>=1;i--){
		rep(j,query[i].size()){
			int x = query[i][j].fi, y = query[i][j].sc;
			if(dep[x] > dep[y]){
				if(beg[x] <= en[x]) shiki.update(beg[x],en[x],0,0,(1<<19)-1,1);
			}
			else{
				if(x != 1){
					shiki.update(id[x],id[x],0,0,(1<<19)-1,1);
					//cout << id[x] << endl;
				}
				shiki.update(beg[x],id[y]-1,0,0,(1<<19)-1,1);
				shiki.update(id[y]+1,en[x],0,0,(1<<19)-1,1);
				//cout << beg[x] << id[y] << en[x] << endl;
			}
		}
		int val = shiki.query(0,(1<<19)-1,0,0,(1<<19)-1);
		ans[i*2] = max(ans[i*2],val);
	}
	repn(i,n) if(ans[1] < edge[i].size()+1) ans[1] = edge[i].size()+1;
	for(int i=1;i<=n;i++) printf("%d\n",max(1,ans[i]));
}