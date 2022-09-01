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
#define s (1<<17)
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >que;
ll dp[500005];
struct kanli{
	vector<P>seg[s*2];
	void update(int beg,int end,int idx,int lb,int ub,P nw)
	{
		if(ub<beg||end<lb)
		{
			return;
		}
		if(beg<=lb&&ub<=end)
		{
			seg[idx].pb(nw);
			return ;
		}
		update(beg,end,idx*2+1,lb,(lb+ub)/2,nw);
		update(beg,end,idx*2+2,(lb+ub)/2+1,ub,nw);
	}
	void check(int a,int idx,int lb,int ub,ll dpp){
		for(int i=0;i<seg[idx].size();i++){
			ll nwval = dpp+seg[idx][i].fi;
			if(dp[seg[idx][i].sc+s-1] > nwval){
				dp[seg[idx][i].sc+s-1] = nwval;
				que.push(mp(nwval,seg[idx][i].sc+s-1));
			}
		}
		seg[idx].clear();
		if(lb == ub) return;
		if(lb <= a && a <= (lb+ub)/2) check(a,idx*2+1,lb,(lb+ub)/2,dpp);
		else check(a,idx*2+2,(lb+ub)/2+1,ub,dpp);
	}
}kaede2;
vector<P>edge[500005];
void make(int a,int b,int k,int l,int r,P nw){
	if(r < a || b < l) return ;
	if(a <= l && r <= b){
		edge[nw.sc+s-1].pb(mp(k,nw.fi));
		return;
	}
	make(a,b,k*2+1,l,(l+r)/2,nw);
	make(a,b,k*2+2,(l+r)/2+1,r,nw);
}
void ini(int k,int l,int r){
	if(l == r) return;
	edge[k].pb(mp(k*2+1,0));
	edge[k].pb(mp(k*2+2,0));
	ini(k*2+1,l,(l+r)/2);
	ini(k*2+2,(l+r)/2+1,r);
}
int n,q,ss;

int main()
{
	scanf("%d%d%d",&n,&q,&ss);
	for(int i=0;i<q;i++){
		int id; scanf("%d",&id);
		if(id == 1){
			int v,u,w; scanf("%d%d%d",&v,&u,&w);
			edge[v+s-1].pb(mp(u+s-1,w));
		}
		else {
			int v,l,r,w; scanf("%d%d%d%d",&v,&l,&r,&w);
			if(id == 2){
				make(l,r,0,0,s-1,mp(w,v));
			}
			else{
				kaede2.update(l,r,0,0,s-1,mp(w,v));
			}
		}
	}
	ini(0,0,s-1);
	for(int i=0;i<500005;i++) dp[i] = 1e18;
	dp[ss+s-1] = 0;
	que.push(mp(0,ss+s-1));
	while(!que.empty()){
		pair<ll,int>q = que.top(); que.pop();
		if(dp[q.sc] != q.fi) continue;
		if(q.sc >= s-1) kaede2.check(q.sc-(s-1),0,0,s-1,dp[q.sc]);
		for(int i=0;i<edge[q.sc].size();i++){
			if(dp[edge[q.sc][i].fi] > dp[q.sc]+edge[q.sc][i].sc){
				dp[edge[q.sc][i].fi] = dp[q.sc]+edge[q.sc][i].sc;
				que.push(mp(dp[edge[q.sc][i].fi],edge[q.sc][i].fi));
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dp[i+s-1] > 5e17) puts("-1");
		else printf("%lld\n",dp[i+s-1]);
	}
	return 0;
}