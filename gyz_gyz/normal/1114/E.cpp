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
default_random_engine e;
int ui(int l,int r){
	uniform_int_distribution<int>u(l,r);
	return u(e);
}
int main(){e.seed(time(0));
	int n,l=0,r=inf,m=(l+r)/2,tot=60,d=0;
	scanf("%d",&n);
	for(;l<r;m=(l+r)/2){
		printf("> %d\n",m);fflush(stdout);
		int x;scanf("%d",&x);--tot;
		if(x)l=m+1;else r=m;
	}
	while(tot--){
		printf("? %d\n",ui(1,n));fflush(stdout);
		int x;scanf("%d",&x);
		if(d)d=__gcd(d,m-x);else d=m-x;
	}
	printf("! %d %d\n",m-(n-1)*d,d);fflush(stdout);
}