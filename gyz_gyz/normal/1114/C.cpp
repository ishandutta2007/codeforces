#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int main(){ll n,m,ans=Inf;
	scanf("%lld%lld",&n,&m);
	rep(i,2,m){
		if(m/i<i)break;
		if(!(m%i)){ll s=0,t=0;
			for(;!(m%i);m/=i)++s;
			for(ll r=n/i;r;r/=i)t+=r;
			ans=min(ans,t/s);
		}
	}
	if(m>1){ll t=0;
		for(ll r=n/m;r;r/=m)t+=r;
		ans=min(ans,t);
	}
	printf("%lld\n",ans);
}