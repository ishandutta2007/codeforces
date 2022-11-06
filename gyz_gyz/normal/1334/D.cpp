#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
const int mo=998244353;
void sol(){ll n,l,r,nw=0;
	scanf("%lld%lld%lld",&n,&l,&r);
	rep(i,1,n-1){
		rep(j,max(l-nw,1ll),min(r-nw,(n-i)*2))printf("%lld ",j%2?i:j/2+i);
		nw+=(n-i)*2;
	}
	if(r>nw)printf("1 ");
	printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}