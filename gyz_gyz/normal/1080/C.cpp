#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cal(ll x1,ll y1,ll x2,ll y2,bool c){
	ll n=x2-x1+1,m=y2-y1+1;
	ll s=n/2*m;if(n&1)s+=(m+1)/2;
	if((x1+y1+c)&1)s=n*m-s;return s;
}
void sol(){ll n,m,x1,y1,x2,y2,x3,y3,x4,y4;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&n,&m,&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
	ll a=cal(1,1,n,m,0);
	a+=cal(x1,y1,x2,y2,1);
	a-=cal(x3,y3,x4,y4,0);
	ll x5=max(x1,x3),x6=min(x2,x4),y5=max(y1,y3),y6=min(y2,y4);
	if(x5<=x6&&y5<=y6)a-=cal(x5,y5,x6,y6,1);
	printf("%lld %lld\n",a,n*m-a);
}
int main(){int T;
	for(scanf("%d",&T);T;--T)sol();
}