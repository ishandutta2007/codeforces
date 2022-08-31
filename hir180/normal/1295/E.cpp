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

int n,p[200005];
struct segtree{
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
	ll query(){ return seg[0]; }
}kaede;
int pos[200005];
ll cs[200005];
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%d",&p[i]);
		pos[p[i]] = i;
	}
	ll r = 0;
	repn(i,n){
		scanf("%lld",&cs[i]); r += cs[i];
		if(i < n) kaede.update(i,i,0,0,s-1,r);
	}
	ll ans = min(cs[1],cs[n]);
	ans = min(ans,kaede.query(1,n-1,0,0,s-1));
	for(int i=1;i<=n;i++){
		int p = pos[i];
		kaede.update(p,n-1,0,0,s-1,-cs[p]);
		kaede.update(1,p-1,0,0,s-1,cs[p]);
		ans = min(ans,kaede.query(1,n-1,0,0,s-1));
	}
	cout << ans << endl;
}