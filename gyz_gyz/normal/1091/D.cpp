#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){int n;ll ans=0;
	scanf("%d",&n);ll s=1,r=1;
	rep(i,1,n)r=r*i%mo;ans=r;
	dep(i,n,1){
		s=s*i%mo;r=r*qk(i,mo-2)%mo;
		add(ans,s%mo*(r+mo-1)%mo);
	}
	printf("%lld\n",ans);
}