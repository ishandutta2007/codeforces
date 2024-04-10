#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e5+10;
const int mo=1e9+7;
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll l[N],r[N],ls[N],rs[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&l[i]);
	rep(i,1,n)scanf("%lld",&r[i]);
	if(n==1)return printf("1\n"),0;
	ls[0]=rs[n+1]=1;
	rep(i,1,n)ls[i]=ls[i-1]*(r[i]-l[i]+1)%mo;
	dep(i,n,1)rs[i]=rs[i+1]*(r[i]-l[i]+1)%mo;
	ll nw=0,ans=0;
	rep(i,1,n){
		ll dl=r[i]-l[i]+1,dr=r[i]-l[i]+1;
		if(i>1){
			ll L=max(l[i],l[i-1]),R=min(r[i],r[i-1]);
			dl=(ls[i]+mo-(R<L?0:R-L+1)*ls[i-2]%mo)%mo;
		}
		if(i<n){
			ll L=max(l[i],l[i+1]),R=min(r[i],r[i+1]);
			dr=(rs[i]+mo-(R<L?0:R-L+1)*rs[i+2]%mo)%mo;
		}
		(ans+=nw*dr)%=mo;
		((nw*=r[i]-l[i]+1)+=dl)%=mo;
		if(i==1)(ans+=dr)%=mo;else if(i==n)(ans+=dl)%=mo;else{
			ll L=max(max(l[i],l[i-1]),l[i+1]),R=min(min(r[i],r[i-1]),r[i+1]);
			(ans+=dl*rs[i+1]+dr*ls[i-1]+(R<L?0:R-L+1)*ls[i-2]%mo*rs[i+2]+mo-ls[n])%=mo;
		}
	}
	(ans*=2)%=mo;
	rep(i,1,n){ll dr=r[i]-l[i]+1;
		if(i<n){
			ll L=max(l[i],l[i+1]),R=min(r[i],r[i+1]);
			dr=(rs[i]+mo-(R<L?0:R-L+1)*rs[i+2]%mo)%mo;
		}
		(ans+=mo-dr*ls[i-1]%mo)%=mo;
	}
	printf("%lld\n",ans*qk(ls[n],mo-2)%mo);	
}