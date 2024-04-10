#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
ll a[N],b[N];
void sol(){int n,m;ll ans=inf;
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	rep(i,1,m)scanf("%lld",&b[i]);
	rep(i,1,n)a[i]=a[i-1]+b[a[i]];
	rep(i,1,m)b[i]+=b[i-1];
	rep(i,max(0,n-m),n)ans=min(ans,a[i]+b[n-i]);
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}