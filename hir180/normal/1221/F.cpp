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
vector<int>za;
vector<P>query[1000005];
int n,x[500005],y[500005],c[500005];

class segtree
{
public:
	#define s (1<<20)
	pair<ll,int> seg[s*2];
	ll lazy[s*2];
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2].fi+=lazy[k];
		seg[k*2+1].fi+=lazy[k];
		lazy[k]=0;
	}
	void make(int beg,int end,int idx,int lb,int ub){
		seg[idx].sc = lb; if(lb == ub) return;
		make(beg,end,idx*2+1,lb,(lb+ub)/2);
		make(beg,end,idx*2+2,1+(lb+ub)/2,ub);
	}
	pair<ll,int> update(int beg,int end,int idx,int lb,int ub,ll num)
	{
		if(ub<beg||end<lb)
		{
			return seg[idx];
		}
		if(beg<=lb&&ub<=end)
		{
			lazy[idx]+=num;
			seg[idx].fi+=num;
			return seg[idx];
		}
		if(lazy[idx])
		{
			lazy_evaluate(idx);
		}
		return seg[idx]=max(update(beg,end,idx*2+1,lb,(lb+ub)/2,num),update(beg,end,idx*2+2,(lb+ub)/2+1,ub,num));
	}
	pair<ll,int> query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return mp(-1000000000000000000LL,0);
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
	rep(i,n){
		scanf("%d%d%d",&x[i],&y[i],&c[i]);
		za.pb(x[i]); za.pb(y[i]);
	}
	SORT(za); ERASE(za);
	rep(i,n){
		int mn = min(x[i],y[i]); mn = POSL(za,mn);
		int mx = max(x[i],y[i]); mx = POSL(za,mx);
		query[mn].pb(mp(mx,c[i]));
	} kaede.make(0,s-1,0,0,s-1);
	ll ans = 0; P ret=mp(mod,mod);
	for(int i=za.size()-1;i>=0;i--){
		rep(j,query[i].size()){
			kaede.update(query[i][j].fi,za.size()-1,0,0,s-1,query[i][j].sc);
		}
		pair<ll,int>Q = kaede.query(i,za.size()-1,0,0,s-1); 
		if(ans < Q.fi){ ans = Q.fi; ret = mp(za[i],za[Q.sc]); }
		if(i)kaede.update(i,s-1,0,0,s-1,za[i-1]-za[i]);
	}
	cout << ans << endl;
	cout << ret.fi << " "<< ret.fi << " "<< ret.sc << " "<< ret.sc << endl; 
}