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
int n,q;
vector<pair<int,ll> >edge[500005];
int mn[500005],mx[500005];
ll val[500005];
class segtree{
	public:
	#define s (1<<19)
	ll seg[s*2];
	ll lazy[s*2];
	void init(){
		fill(seg,seg+s*2,1000000000000000000LL);
	}
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
		if(ub<beg||end<lb)
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
		return seg[idx]=min(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	ll query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return 1000000000000000000LL;
		}
		if(beg<=lb&&ub<=end)
		{
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return min(query(beg,end,idx*2+1,lb,(lb+ub)/2),query(beg,end,idx*2+2,(lb+ub)/2+1,ub));
	}
}kaede;
void dfs(int v){
	mn[v] = v;
	mx[v] = v;
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i].fi;
		val[to] = val[v] + edge[v][i].sc;
		dfs(to);
		mn[v] = min(mn[v],mn[to]);
		mx[v] = max(mx[v],mx[to]);
	}
	if(edge[v].empty()){
		kaede.update(v,v,0,0,s-1,-1000000000000000000LL);
		kaede.update(v,v,0,0,s-1,val[v]);
	}
}
vector<P1>query[500005];
ll ans[500005];
void dfs_calc(int v){
	for(int i=0;i<query[v].size();i++){
		int pos = query[v][i].fi;
		int L = query[v][i].sc.fi, R = query[v][i].sc.sc;
		ans[pos] = kaede.query(L,R,0,0,s-1);
	}
	for(int i=0;i<edge[v].size();i++){
		int to = edge[v][i].fi;
		kaede.update(0,s-1,0,0,s-1,edge[v][i].sc);
		kaede.update(mn[to],mx[to],0,0,s-1,-2LL*edge[v][i].sc);
		dfs_calc(to);
		kaede.update(0,s-1,0,0,s-1,-edge[v][i].sc);
		kaede.update(mn[to],mx[to],0,0,s-1,2LL*edge[v][i].sc);
	}
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		int x; ll v;
		scanf("%d%lld",&x,&v);
		edge[x].pb(mp(i,v));
	}
	kaede.init();
	dfs(1);
	rep(i,q){
		int x,l,r; scanf("%d%d%d",&x,&l,&r);
		query[x].pb(mp(i,mp(l,r)));
	}
	dfs_calc(1);
	rep(i,q){
		printf("%lld\n",ans[i]);
	}
}