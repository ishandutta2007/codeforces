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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[500005];
ll rui[500005];
ll va[500005],vb[500005];
int en = INF;
struct RMQ{
	#define s (1<<20)
	ll seg[s];
	void init(){fill(seg,seg+s,-1e18);}
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
}kaede[2];
ll S = 0;
vector<int>ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		S+=a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++) rui[i]=rui[i-1]+a[i];
	for(int i=0;i<=n;i++){
		va[i] = vb[i] = rui[i];
		va[i] -= 1LL*i*(i-1);
		vb[i] -= 1LL*i*(i+1);
		int lb = i+1, ub = n+1;
		while(ub-lb>1){
			int mid = (lb+ub)/2;
			if(a[mid] <= i) ub = mid;
			else lb = mid;
		}
		va[i] -= 1LL*i*(lb-i);
		va[i] -= rui[n]-rui[lb];
		
		lb = i+1, ub = n+1;
		while(ub-lb>1){
			int mid = (lb+ub)/2;
			if(a[mid] <= i+1) ub = mid;
			else lb = mid;
		}
		vb[i] -= 1LL*(i+1)*(lb-i);
		vb[i] -= rui[n]-rui[lb];
	}
	//for(int i=0;i<=n;i++) cout<<va[i]<<" "<<vb[i]<<endl;
	rep(t,2) kaede[t].init();
	
	for(int i=1;i<=n;i++){
		kaede[0].update(i,va[i]);
		kaede[1].update(i,vb[i]);
		if(va[i] > i && en == INF){
			en = i;
		}
	}
	for(int x=n;x>=0;x--){
		if( (S+1LL*x)%2 == 1 ) continue;
		int lb = 0,ub = n+1;
		while(ub-lb > 1){
			int mid = (lb+ub)/2;
			if(a[mid] > x) lb = mid;
			else ub = mid;
		}
		
		//[lb+1,n]
		ll E = kaede[1].query(lb+1,n,0,0,s/2-1);
		if(E <= -1LL*x);
		else continue;
		//[1,lb]
		int e = min(x,lb);
		if(e >= en) continue;
		//[e+1,lb]
		E = kaede[0].query(e+1,lb,0,0,s/2-1);
		if(E <= 1LL*x);
		else continue;
		ll fl = vb[lb]+x;
		if(fl > 0) continue;
		ans.pb(x);
	}
	if(ans.empty()) puts("-1");
	else{
	    reverse(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		puts("");
	}
}