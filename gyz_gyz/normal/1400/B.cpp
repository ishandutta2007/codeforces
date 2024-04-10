#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
void sol(){ll p,f,cs,cw,s,w;
	scanf("%lld%lld%lld%lld%lld%lld",&p,&f,&cs,&cw,&s,&w);
	if(s>w)swap(s,w),swap(cs,cw);
	if(p/s+f/s<=cs){
		printf("%lld\n",p/s+f/s);return;
	}
	ll ans=cs;
	rep(i,0,cs)if((cs-i)*s<=f){
		if(i*s>p)break;
		ans=max(ans,cs+min((p-i*s)/w+(f-(cs-i)*s)/w,cw));
	}
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}