#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
void sol(){ll n,m,ans=1,nw=1;
	scanf("%lld%lld",&n,&m);--n;
	rep(i,1,30){
		nw=nw*((1ll<<(i-1))+1)%m;
		if(n>>i){
			n-=1<<i;
			ans=(ans+(1ll<<i)*nw)%m;
		}else{
			ans=(ans+n*nw)%m;
			break;
		}
	}
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();	
}