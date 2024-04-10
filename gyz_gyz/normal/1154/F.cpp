#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define pct __builtin_popcount
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
const int N=2e5+10;
const ll mo=1e9+7;
const ll inf=1e9;
const ll Inf=1e18;
ll w[N],a[N];int x[N],y[N];
int main(){int n,m,k;
	scanf("%d%d%d",&n,&k,&m);
	rep(i,1,n)scanf("%lld",&w[i]);
	sort(w+1,w+n+1);
	rep(i,1,m)w[i]+=w[i-1],a[i]=w[i];
	rep(i,1,k)scanf("%d%d",&x[i],&y[i]);
	rep(i,1,m)rep(j,1,k)if(x[j]<=i)
		a[i]=min(a[i-x[j]]+w[i]-w[i-x[j]+y[j]],a[i]);
	printf("%lld\n",a[m]);
}