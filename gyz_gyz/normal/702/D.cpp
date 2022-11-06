#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
int main(){ll d,k,a,b,t;
	scanf("%lld%lld%lld%lld%lld",&d,&k,&a,&b,&t);
	if(b<=a)return printf("%lld\n",d*b),0;
	if(d<=k)return printf("%lld\n",d*a),0;
	ll ans=k*a;d-=k;
	if(k*b<=t+k*a)return printf("%lld\n",ans+d*b),0;
	ans+=d/k*(t+k*a);d%=k;
	printf("%lld\n",ans+min(t+d*a,d*b));
}