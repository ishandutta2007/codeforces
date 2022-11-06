#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int mo=1e9+7;
const ll inf=1e18;
ll a[N],v[60];
void sol(){int n;ll ans=0;
	scanf("%d",&n);
	rep(i,0,59)v[i]=0;
	rep(i,1,n){
		scanf("%lld",&a[i]);
		rep(j,0,59)if((a[i]>>j)&1)++v[j];
	}
	rep(i,1,n){
		ll w1=0,w2=((1ll<<60)-1)%mo*n%mo;
		rep(j,0,59)if((a[i]>>j)&1)w1=(w1+(1ll<<j)%mo*v[j])%mo;
		rep(j,0,59)if(!((a[i]>>j)&1))w2=(w2+mo-(1ll<<j)%mo*(n-v[j])%mo)%mo;
		ans=(ans+w1*w2)%mo;
	}
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}