#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,m,k;
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){
		if(y&1)r=r*x%mo;x=x*x%mo;
	}return r;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);ll ans=m;
	rep(i,n-k,n-1)ans=(ans*i)%mo;
	rep(i,2,k)ans=ans*qk(i,mo-2)%mo;
	rep(i,1,k)ans=ans*(m-1)%mo;
	printf("%lld\n",ans);
}