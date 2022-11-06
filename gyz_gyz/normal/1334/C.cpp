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
ll a[N],b[N];
void sol(){int n;ll ans=0,mi=inf;
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld%lld",&a[i],&b[i]);
	rep(i,1,n){
		ll t=min(a[i%n+1],b[i]);
		ans+=a[i%n+1]-t;
		mi=min(mi,a[i%n+1]=t);
	}
	printf("%lld\n",ans+mi);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}