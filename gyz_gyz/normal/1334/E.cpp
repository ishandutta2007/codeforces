#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
const int mo=998244353;
int tot;
ll p[N],rev[N],f[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
ll cal(ll x){ll r=1;int al=0;
	rep(i,1,tot){int nw=0;
		for(;!(x%p[i]);x/=p[i])++nw;
		al+=nw;r=r*rev[nw]%mo;
	}
	return r*f[al]%mo;
}
int main(){ll D;int n;
	f[0]=rev[0]=1;
	rep(i,1,60){
		f[i]=f[i-1]*i%mo;
		rev[i]=qk(f[i],mo-2);
	}
	scanf("%lld%d",&D,&n);
	rep(i,2,D){
		if(D/i<i)break;
		if(!(D%i)){
			p[++tot]=i;
			while(!(D%i))D/=i;
		}
	}
	if(D>1)p[++tot]=D;
	rep(i,1,n){ll x,y;
		scanf("%lld%lld",&x,&y);
		ll z=__gcd(x,y);
		printf("%lld\n",cal(x/z)*cal(y/z)%mo);
	}
}