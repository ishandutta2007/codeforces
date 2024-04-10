#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=1e9+7;
ll lcm(ll x,ll y){return x*y/__gcd(x,y);}
int main(){int n;ll ans,g,x;
	scanf("%d%lld%lld",&n,&g,&x);
	ans=lcm(x,g);g=__gcd(g,x);
	rep(i,3,n){
		scanf("%lld",&x);
		ans=__gcd(ans,lcm(x,g));
		g=__gcd(g,x);
	}
	printf("%lld\n",ans);
}