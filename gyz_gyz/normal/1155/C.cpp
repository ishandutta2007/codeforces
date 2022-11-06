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
int main(){int n;ll m,x,r=0;
	scanf("%d%lld%lld",&n,&m,&x);
	rep(i,2,n){ll y;
		scanf("%lld",&y);
		if(!r)r=y-x;else r=__gcd(r,y-x);
	}
	rep(i,1,m){ll y;
		scanf("%lld",&y);
		if(!(r%y))return printf("YES\n%lld %d\n",x,i),0;
	}
	printf("NO\n");
}