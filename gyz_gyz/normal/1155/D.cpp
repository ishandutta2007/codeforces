#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){
	int n;ll m,a=0,b=0,c=0,ans=0;
	scanf("%d%lld",&n,&m);
	rep(i,1,n){ll x;
		scanf("%lld",&x);
		c=x+max(0ll,max(a,max(b,c)));
		b=x*m+max(0ll,max(a,b));
		a=x+max(0ll,a);
		ans=max(ans,max(b,c));
	}
	printf("%lld\n",ans);
}