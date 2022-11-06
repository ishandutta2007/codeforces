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
#define N 20010
#define mo 1000000007
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){int n;
	scanf("%d",&n);
	while(n--){ll a,x,y;
		scanf("%lld%lld%lld",&a,&x,&y);
		printf("%lld\n",a/2*min(x*2,y)+(a&1)*x);
	}
}