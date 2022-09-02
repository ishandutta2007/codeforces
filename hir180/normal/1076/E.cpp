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
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
vector<int>edge[300005];
int num[300005],out[300005],k,dep[300005];
ll anss[300005];
void dfs(int v,int u){
	num[v] = k++;
	if(u == -1) dep[v] = 0;
	else dep[v] = dep[u]+1;
	rep(i,edge[v].size()){
		if(edge[v][i] == u) continue;
		dfs(edge[v][i],v);
	}
	out[v] = k-1;
}
vector<P1>query[300005];
vector<P>ans[300005];
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
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	ll query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return -1000000000000000000LL;
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
}kaede;
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
		
	}
	dfs(1,-1);
	scanf("%d",&m);
	rep(i,m){
		int v,d,x; scanf("%d%d%d",&v,&d,&x);
		//[num[v],out[v]] [dep[v],dep[v]+d]
		int D = dep[v]+d;
		if(D > 400000) D = 400000;
		query[num[v]].pb(mp(x,mp(dep[v],D)));
		query[out[v]+1].pb(mp(-x,mp(dep[v],D)));
	}
	for(int i=1;i<=n;i++) ans[num[i]].pb(mp(dep[i],i));
	for(int i=0;i<n;i++){
		rep(j,query[i].size()){
			ll add = query[i][j].fi;
			int a = query[i][j].sc.fi;
			int b = query[i][j].sc.sc;
			kaede.update(a,b,0,0,(1<<19)-1,add);
		}
		rep(j,ans[i].size()){
			int pos = ans[i][j].fi;
			anss[ans[i][j].sc] = kaede.query(pos,pos,0,0,(1<<19)-1);
		}
	}
	repn(i,n) printf("%lld\n",anss[i]);
}