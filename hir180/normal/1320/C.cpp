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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

struct seg{
	#define s (1<<18)
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

int n,m,p;
vector<P>a,b;
vector<P>mon[200005];

int main(){
	scanf("%d%d%d",&n,&m,&p);
	rep(i,n){
		int x,y; scanf("%d%d",&x,&y);
		a.pb(mp(x,y));
	}
	rep(i,m){
		int x,y; scanf("%d%d",&x,&y);
		b.pb(mp(x,y));
	}
	SORT(a) ; SORT(b) ; 
	rep(i,m){
		kaede.update(i,i,0,0,s-1,-b[i].sc);
	}
	rep(i,p){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		int id1 = POSL(a,mp(x+1,-1));
		int id2 = POSL(b,mp(y+1,-1));
		mon[id1].pb(mp(id2,z));
	}
	ll ans = -1e18;
	rep(i,n){
		ll cur = -a[i].sc;
		rep(j,mon[i].size()){
			int pos = mon[i][j].fi;
			int gain = mon[i][j].sc;
			kaede.update(pos,m-1,0,0,s-1,gain);
		}
		cur += kaede.query(0,m-1,0,0,s-1);
		ans = max(ans,cur);
	}
	printf("%lld\n",ans);
}