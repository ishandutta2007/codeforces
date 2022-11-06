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
const int N=1e5+10;
const int mo=1e9+7;
const ll inf=1e18;
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){int n;ll m,ans=0;
	scanf("%d%lld",&n,&m);ll nw=1,x=0;
	rep(i,0,n){bool fl=0;
		while(x<n&&m+i>=x){ll X;
			scanf("%lld",&X);m-=X;fl=1;++x;
		}
		ll p=nw*qk((mo+1)/2,x)%mo;
		(ans+=p*(x-(m+i<x)))%=mo;
		if(fl)(nw*=x*qk(x-i,mo-2)%mo)%=mo;
		(nw*=(x-i)*qk(i+1,mo-2)%mo)%=mo;
	}
	printf("%lld\n",ans);
}