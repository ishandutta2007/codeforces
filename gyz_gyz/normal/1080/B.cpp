#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
ll cal(ll l,ll r){
	if(l>r)return 0;ll t;
	if(r&1)t=-1;else t=1;
	if((r-l+1)&1)return r*t+cal(l,r-1);
	return (r-l+1)/2*t;
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",cal(l,r));
	}
}