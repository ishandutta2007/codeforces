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
int dp[35005][55],a[35005],n;
int prevv[35005],val[35005];

class segtree
{
public:
	#define s (1<<16)
	int seg[s*2];
	int lazy[s*2];
	void init(){ memset(seg,0,sizeof(seg)); memset(lazy,0,sizeof(lazy)); }
	void lazy_evaluate(int k)
	{
		if(k*2+2>=s*2) return ;
		lazy[k*2+2]+=lazy[k];
		lazy[k*2+1]+=lazy[k];
		seg[k*2+2]+=lazy[k];
		seg[k*2+1]+=lazy[k];
		lazy[k]=0;
	}
	int update(int beg,int end,int idx,int lb,int ub,ll num)
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
	int query(int beg,int end,int idx,int lb,int ub)
	{
		if(ub<beg||end<lb)
		{
			return -100000;
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
}seg;
int main(){
	int n,k; cin >> n >> k;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	fill(val,val+35005,-INF);
	for(int i=1;i<=n;i++){
		if(val[a[i]]<=0) prevv[i] = 0;
		else prevv[i] = val[a[i]];
		val[a[i]] = i;
	}
	for(int j=0;j<k;j++){
		seg.init();
		for(int i=0;i<=n;i++) seg.update(i,i,0,0,(1<<16)-1,dp[i][j]);
		for(int i=1;i<=n;i++){
			int x = prevv[i]; seg.update(x,i-1,0,0,(1<<16)-1,1);
			//cout << x << " " << i-1 << endl;
			dp[i][j+1] = seg.query(0,i-1,0,0,(1<<16)-1);
		}
	}
	cout << dp[n][k] << endl;
}