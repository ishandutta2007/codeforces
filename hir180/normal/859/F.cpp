#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
typedef complex<double> pt;
int n;
ll dp[200005],C,a[200005],b[200005];;
ll ruia[200005],ruib[200005];
#define s (1<<19)
ll seg[s]={};
void update(int k,ll a){
	k+=s/2-1; seg[k]=a;
	while(k>0){
		k=(k-1)/2;
		seg[k]=max(seg[k*2+1],seg[k*2+2]);
	}
}
ll query(int a,int b,int k,int l,int r){
	if(r<a || b<l || a>b) return -1e18;
	if(a<=l && r<=b) return seg[k];
	else{
		ll vl=query(a,b,k*2+1,l,(l+r)/2);
		ll vr=query(a,b,k*2+2,(l+r)/2+1,r);
		return max(vl,vr);
	}
}
int main(){
	cin>>n>>C;
	repn(i,n){
		scanf("%lld",&a[i]);
		ruia[i] = ruia[i-1]+a[i];
		if(i!=n){
			scanf("%lld",&b[i]);
			ruib[i] = ruib[i-1]+b[i];
		}
	}
	dp[0] = 0;
	fill(seg,seg+s,-1e18); update(0,ruia[n]+ruib[n-1]);
	for(int i=1;i<=n;i++){
		dp[i] = max(dp[i],dp[i-1]+min(C,a[i]));
		if(a[i] >= C) continue;
		int lb = -1,ub = i-1;
		//[lb,ub)
		while(ub-lb>1){
			int mid = (lb+ub)/2;
			ll SUM = ruia[i]-ruia[mid];
			SUM += ruib[i-1]-ruib[mid];
			if(SUM>=C) lb = mid;
			else ub = mid;
		}
		//cout<<lb<<" "<<i<<endl;
		if(lb >= 0){
			dp[i] = max(dp[i],dp[lb]+C);
		}
		//[lb+1,i-2]
		ll val = query(lb+1,i-2,0,0,(1<<18)-1);
		dp[i] = max(dp[i],val-(ruia[n]-ruia[i])-(ruib[n-1]-ruib[i-1]));
		update(i,dp[i]+ruia[n]-ruia[i]+ruib[n-1]-ruib[i]);
	}
	cout<<dp[n]<<endl;
}