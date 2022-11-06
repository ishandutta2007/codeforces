#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll inf=1e18;
const int mo=998244353;
const ll p[3][4]={{0,1,2,3},{0,2,3,1},{0,3,1,2}};
ll cal(ll x,ll y){int s=0;
	for(;x>=1ll<<(s*2);++s)x-=1ll<<(s*2);
	ll ans=(y+1)<<(s*2);
	rep(i,0,s-1)ans|=p[y][(x>>(i*2))&3]<<(i*2);
	return ans;
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t){ll x;
		scanf("%lld",&x);
		printf("%lld\n",cal((x-1)/3,(x-1)%3));
	}
}